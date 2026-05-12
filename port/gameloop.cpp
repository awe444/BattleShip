/**
 * gameloop.cpp — PC game loop implementation for the SSB64 port.
 *
 * This file implements the frame loop that drives SSB64's game logic on PC.
 * The N64 game uses 5 OS threads communicating via message queues. On PC,
 * we run the entire game in a single coroutine that yields at blocking
 * points (osRecvMesg with OS_MESG_BLOCK).
 *
 * Architecture:
 *   main() loop
 *     -> PortPushFrame()
 *       -> post INTR_VRETRACE to scheduler queue
 *       -> resume game coroutine
 *         -> scheduler coroutine processes tick (sends to clients)
 *         -> game logic runs one frame
 *         -> display list built, submitted to scheduler
 *         -> scheduler calls osSpTaskStartGo -> port_submit_display_list
 *         -> Fast3D renders via DrawAndRunGraphicsCommands
 *         -> game coroutine yields at next osRecvMesg(BLOCK) on empty queue
 */

#include "gameloop.h"
#include "coroutine.h"
#include "enhancements/enhancements.h"
#include "widescreen/widescreen.h"
#include "port.h"
#include "port_watchdog.h"

#include <libultraship/libultraship.h>
#include <fast/Fast3dWindow.h>
#include <fast/interpreter.h>

#include <cstdint>
#include <cstdio>
#include <chrono>
#include <stdexcept>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <cstring>

/* GBI trace system */
#include "../debug_tools/gbi_trace/gbi_trace.h"

#include "port_log.h"
#include "renderdoc_trigger.h"

#if defined(__ANDROID__)
#include <SDL2/SDL.h>
#endif

/* Backbuffer screenshot capture — implemented in libultraship's DX11 backend.
 * Returns 1 on success, 0 on failure (silent). Never throws. */
extern "C" int portFastCaptureBackbufferPNG(const char *path);

/* Simulated N64 VI VBlank: propagates the queued framebuffer to "current"
 * so the scheduler's CheckReadyFramebuffer fnCheck can correctly stall a
 * gfx task when VI is still using the slot the game wants to draw into.
 * Implemented in port/stubs/n64_stubs.c. */
extern "C" void port_vi_simulate_vblank(void);

extern "C" void lbBackupApplyCheats(void);

/* Taskman DL buffer state — declared in decomp/src/sys/taskman.c.  Used by
 * the kill-switch dump below to label per-frame buffer extents in the log
 * without an extra layer of accessors in the decomp submodule.
 * `SYTaskmanDLBuffer` is the matching layout from decomp/src/sys/taskman.h
 * (Gfx *start; u32 length) — re-declared here to avoid pulling the full
 * decomp header into the port C++ TU. */
struct SYTaskmanDLBuffer_t {
	Gfx     *start;
	uint32_t length;
};
extern "C" {
extern Gfx                 *gSYTaskmanDLHeads[4];
extern Gfx                 *sSYTaskmanDLBranches[4];
extern SYTaskmanDLBuffer_t  sSYTaskmanDLBuffers[2][4];
extern int                  gSYTaskmanTaskID;
}

/* ========================================================================= */
/*  External game symbols (C linkage)                                        */
/* ========================================================================= */

extern "C" {

/* The N64 game entry point — starts the whole boot chain. */
extern void syMainLoop(void);

/* Scheduler task message queue — we post INTR_VRETRACE here each frame. */
extern OSMesgQueue gSYSchedulerTaskMesgQueue;

/* VI retrace interrupt value (matches scheduler.c local define). */
#define INTR_VRETRACE 1

} /* extern "C" */

/*
 * port_make_os_mesg_int() — fully-initialised OSMesg from an integer code.
 *
 * The decomp treats OSMesg as `void*` (PR/os.h); libultraship treats it as a
 * union { u8; u16; u32; void*; } (libultraship/libultra/message.h). Both are
 * 8 bytes, so the calling convention matches, but writing only one union
 * member from C++ leaves the remaining bytes uninitialised — whatever was on
 * the stack in that slot. On MSVC/x64 those bytes happened to be zero and
 * the bug was latent; on macOS/arm64 they held a stack pointer, and the
 * scheduler's `(SYTaskInfo*)mesg` cast in sySchedulerThreadMain then jumped
 * through a garbage `fnCheck` pointer.
 *
 * All port-layer (C++) sends of integer interrupt codes should go through
 * this helper so the full 8 bytes are well-defined on every platform.
 */
static inline OSMesg port_make_os_mesg_int(uint32_t code)
{
	OSMesg m{};          /* zero-initialise every union member */
	m.data32 = code;     /* then set the scalar we care about */
	return m;
}

/* ========================================================================= */
/*  Game coroutine state                                                     */
/* ========================================================================= */

static PortCoroutine *sGameCoroutine = NULL;

/* ========================================================================= */
/*  Game coroutine entry point                                               */
/* ========================================================================= */

/**
 * Wrapper for syMainLoop that matches the coroutine entry signature.
 *
 * syMainLoop creates Thread 1 (idle), which creates Thread 5 (game).
 * Each osStartThread creates a sub-coroutine. When Thread 1 finishes
 * (after starting Thread 5 and returning on PORT), syMainLoop returns.
 *
 * At that point, Thread 5's coroutine exists but is suspended. We need
 * to keep the game coroutine alive and act as the "scheduler" that
 * resumes Thread 5 (and other service threads) each frame.
 *
 * The game coroutine entry function runs syMainLoop (boot), then enters
 * an infinite yield loop. PortPushFrame resumes it each frame, and it
 * yields back immediately — the actual frame work happens when
 * PortPushFrame resumes the individual thread coroutines.
 */
static void game_coroutine_entry(void *arg)
{
	(void)arg;
	port_log("SSB64: Game coroutine started — entering syMainLoop\n");
	syMainLoop();
	port_log("SSB64: syMainLoop returned — boot chain complete\n");
	/* All thread coroutines are now created and suspended.
	 * PortPushFrame will resume them directly via port_resume_service_threads. */
}

/* ========================================================================= */
/*  Display list submission                                                  */
/* ========================================================================= */

/**
 * Called from osSpTaskStartGo (n64_stubs.c) when a GFX task is submitted.
 * Routes the N64 display list through Fast3D for rendering.
 */
static int sGbiTraceInitDone = 0;

/* Per-DL gfx-task wall-clock cost estimator (Phase 3 of the freeze-frame
 * fix). Each command processed by Fast3D's interpreter fires this
 * callback; we accumulate a coarse cost estimate from F3DEX opcodes that
 * dominate real-hw RDP/RSP budget on N64 (triangles, fillrects, texrects).
 *
 * After the DL is fully processed, port_get_last_dl_defer_n() turns the
 * accumulated cost into the deferral count N for the SP/DP-interrupt
 * delay queue in osSpTaskStartGo: light DLs N=1 (no SwitchContext
 * contention, smooth play), heavy climax DLs N=2 (contention triggers
 * the game-thread cap which holds one host frame = visible 1-frame
 * whole-screen freeze, matching real-hw / parallel-rdp behavior).
 *
 * F3DEX opcode reference (SSB64 ucode is gsp.fifo / F3DEX). Top byte of
 * w0 is the opcode. */
static int sFrameTriCount = 0;
static int sFrameRectPx = 0;
static int sFrameLoadBytes = 0;
static int sLastDLTris = 0;
static int sLastDLRectPx = 0;
static int sLastDLLoadBytes = 0;

/* ---------- Per-DL hang diagnostics ----------------------------------------
 *
 * Goal: when a DL submit is suspiciously slow (the watchdog has been firing
 * after ~3.5s on a single coroutine resume inside the scheduler thread), log
 * enough information from inside the interpreter to distinguish:
 *
 *   (a) one DL whose interpreter walk takes seconds (huge DL, deep recursion,
 *       or genuinely infinite loop via a bad branch / circular DL),
 *   (b) the scheduler-tick coroutine submitting many DLs back-to-back
 *       without yielding,
 *   (c) Fast3D internal slowness (GPU sync, shader compile stall, etc.) where
 *       opcode count is small but wall time is large.
 *
 * Instrumentation hooks into the existing gbi_trace_callback (one call per
 * GBI opcode inside the Fast3D interpreter loop), so it has zero cost when
 * diagnostics are off (default) and adds a handful of integer ops per opcode
 * when on. Diagnostics are opt-in: they are disabled unless SSB64_DL_DIAG is
 * set. Logging is guarded by thresholds with env overrides so normal runs
 * are quiet.
 *
 *   SSB64_DL_DIAG=1            enable all DL diagnostics (required; off by default)
 *   SSB64_DL_DIAG_MS=N         log if a DL submit takes more than N ms (default 200)
 *   SSB64_DL_DIAG_OPS=N        log if a DL processes more than N opcodes (default 200000)
 *   SSB64_DL_DIAG_HEARTBEAT=N  inside the interpreter, log every N opcodes
 *                              processed within one submit (default 0 = off;
 *                              try 1000000 if you suspect an infinite DL loop)
 */
static int sDLDiagEnabled       = -1;
static int sDLDiagSlowMs        = 200;
static int sDLDiagSlowOps       = 200000;
static int sDLDiagHeartbeatOps  = 0;
int        sDLDiagKillDepth     = 0;  /* extern-linked from kill-switch above */
static uint64_t sDLOpCount      = 0;
static uint64_t sDLOpHeartbeatNext = 0;
static uint32_t sDLOpHist[256]  = {0};
static uint8_t  sDLFirstOpcode  = 0xFF;
static uint64_t sDLLastW0       = 0;
static uint64_t sDLLastW1       = 0;
static int      sDLMaxDepth     = 0;
static uint32_t sDLSubmitSeq    = 0;

/* Ring buffer of the most recent (opcode, w0, w1) tuples seen by the trace
 * callback in the current DL. On a hang we dump this to see what opcode
 * pattern keeps repeating. Size is a power of two for cheap masking. */
static constexpr int kDLRingSize = 32;
struct DLRingEntry {
	uint64_t w0;
	uint64_t w1;
	int      depth;
	uint8_t  opcode;
};
static DLRingEntry sDLRing[kDLRingSize] = {0};
static int sDLRingHead = 0;
/* Tally of G_DL-class call opcodes by (w1 target). Tracks up to 16 distinct
 * targets per DL — small table is enough because a runaway cycle by
 * definition revisits a tiny number of addresses. */
static constexpr int kDLCallTargets = 16;
struct DLCallTally {
	uint64_t target;
	uint32_t count;
};
static DLCallTally sDLCalls[kDLCallTargets] = {0};
static uint32_t sDLCallTotal = 0;
/* Push (G_DL call/branch) and pop (G_ENDDL) op counters for the current DL.
 * A runaway recursion looks like push >> pop. F3DEX2 end-DL = 0xDF, F3D/F3DEX
 * end-DL = 0xB8 (both reach the same gfx_end_dl_handler_common). */
static uint32_t sDLPushCount = 0;
static uint32_t sDLPopCount  = 0;
/* Root pointer (cast to uintptr_t) for the current DL submit, plus its
 * first opcode and w1. Helpful to identify which game DL kicked off the
 * runaway. */
static uintptr_t sDLRootPtr     = 0;
static uint8_t   sDLRootOpcode  = 0xFF;
static uint64_t  sDLRootW0      = 0;
static uint64_t  sDLRootW1      = 0;
/* When depth crosses a threshold, log the first few G_DL-class pushes so we
 * can see exactly which (caller, target) pairs are building the runaway. */
static uint32_t sDLPushLogged   = 0;
static constexpr uint32_t kDLPushLogMax = 24;

static void diag_init_once(void)
{
	if (sDLDiagEnabled >= 0) return;
	const char *env;
	sDLDiagEnabled = 0;
	env = std::getenv("SSB64_DL_DIAG");
	if (env && !(env[0] == '0' || env[0] == 'n' || env[0] == 'N')) {
		sDLDiagEnabled = 1;
	}
	env = std::getenv("SSB64_DL_DIAG_MS");
	if (env) {
		int v = std::atoi(env);
		if (v >= 0) sDLDiagSlowMs = v;
	}
	env = std::getenv("SSB64_DL_DIAG_OPS");
	if (env) {
		int v = std::atoi(env);
		if (v >= 0) sDLDiagSlowOps = v;
	}
	env = std::getenv("SSB64_DL_DIAG_HEARTBEAT");
	if (env) {
		int v = std::atoi(env);
		if (v >= 0) sDLDiagHeartbeatOps = v;
	}
	env = std::getenv("SSB64_DL_DIAG_KILL_DEPTH");
	if (env) {
		int v = std::atoi(env);
		if (v >= 0) sDLDiagKillDepth = v;
	}
	if (sDLDiagEnabled) {
		port_log("SSB64: DL hang diagnostics enabled — slow_ms=%d slow_ops=%d heartbeat_ops=%d kill_depth=%d\n",
		         sDLDiagSlowMs, sDLDiagSlowOps, sDLDiagHeartbeatOps, sDLDiagKillDepth);
	}
}

/* Forward decl: defined further down so we can use it from the callback. */
static void diag_log_top_opcodes(void);

/* Thin C wrapper for the trace callback (matches GbiTraceCallbackFn signature) */
static void gbi_trace_callback(uintptr_t w0, uintptr_t w1, int dl_depth)
{
	gbi_trace_log_cmd((unsigned long long)w0, (unsigned long long)w1, dl_depth);

	uint8_t opcode = (uint8_t)((w0 >> 24) & 0xFFu);

	if (sDLDiagEnabled) {
		if (sDLOpCount == 0) sDLFirstOpcode = opcode;
		sDLOpCount++;
		sDLOpHist[opcode]++;
		sDLLastW0 = (uint64_t)w0;
		sDLLastW1 = (uint64_t)w1;
		if (dl_depth > sDLMaxDepth) sDLMaxDepth = dl_depth;

		/* Ring of recent commands. */
		sDLRing[sDLRingHead].w0     = (uint64_t)w0;
		sDLRing[sDLRingHead].w1     = (uint64_t)w1;
		sDLRing[sDLRingHead].depth  = dl_depth;
		sDLRing[sDLRingHead].opcode = opcode;
		sDLRingHead = (sDLRingHead + 1) & (kDLRingSize - 1);

		/* Track G_DL-class call/branch opcodes by target so we can pinpoint
		 * a runaway recursion cycle. Opcodes:
		 *   0xDE = G_DL                 (vanilla F3D / F3DEX / F3DEX2)
		 *   0xDC = G_DL_OTR_HASH        (LUS expanded — 128-bit; w1 = upper)
		 *   0xDB = G_DL_OTR_FILEPATH
		 *   0xDA = G_DL_INDEX           (LUS port packed-DL index call)
		 * For a cycle we mostly care about which target keeps recurring,
		 * so use w1 as the key. */
		if (opcode == 0xDE || opcode == 0xDC || opcode == 0xDB || opcode == 0xDA) {
			sDLCallTotal++;
			sDLPushCount++;
			uint64_t key = (uint64_t)w1;
			int slot = -1, free_slot = -1;
			for (int i = 0; i < kDLCallTargets; i++) {
				if (sDLCalls[i].count != 0 && sDLCalls[i].target == key) { slot = i; break; }
				if (free_slot < 0 && sDLCalls[i].count == 0) free_slot = i;
			}
			if (slot < 0 && free_slot >= 0) {
				sDLCalls[free_slot].target = key;
				sDLCalls[free_slot].count  = 0;
				slot = free_slot;
			}
			if (slot >= 0) sDLCalls[slot].count++;

			/* Eagerly log the first kDLPushLogMax G_DL-class pushes once
			 * the stack is clearly deeper than any sane game DL nesting.
			 * Includes the no-push (branch) flag from w0 bit 16 so we can
			 * tell call vs branch. */
			if (dl_depth > 200 && sDLPushLogged < kDLPushLogMax) {
				int branch_flag = (int)((w0 >> 16) & 1u);
				port_log("SSB64: DL push#%u op=0x%02X %s depth=%d target=0x%llX w0=0x%llX\n",
				         (unsigned)sDLPushLogged,
				         (unsigned)opcode,
				         branch_flag ? "BRANCH" : "CALL",
				         dl_depth,
				         (unsigned long long)w1,
				         (unsigned long long)w0);
				/* On the very first eager log, also dump 64 bytes (8
				 * 8-byte commands at LP64) of memory at the branch target
				 * so we can decode the body of the runaway DL.
				 * Memory is potentially garbage; we trust it because Fast3D
				 * has been dereferencing it for thousands of iterations,
				 * but guard against obvious bad pointers. */
				if (sDLPushLogged == 1 && w1 > 0x10000 && w1 < 0x00007FFFFFFFFFFFull) {
					const uint8_t *p = reinterpret_cast<const uint8_t *>((uintptr_t)w1);
					char hexbuf[3 * 64 + 16];
					int hoff = 0;
					for (int i = 0; i < 64 && hoff < (int)sizeof(hexbuf) - 4; i++) {
						hoff += std::snprintf(hexbuf + hoff, sizeof(hexbuf) - hoff,
						                     "%02X%s", p[i], (i % 8 == 7) ? "  " : " ");
					}
					port_log("SSB64: DL branch-target hexdump @0x%llX: %s\n",
					         (unsigned long long)w1, hexbuf);
				}
				sDLPushLogged++;
			}
		} else if (opcode == 0xDF || opcode == 0xB8) {
			/* G_ENDDL (F3DEX2 / F3D respectively). */
			sDLPopCount++;
		}

		/* Kill switch: if the DL call stack grows past a sane cap, abort
		 * the submit by throwing — port_submit_display_list catches it
		 * gracefully so the rest of the frame can proceed. Default off;
		 * set SSB64_DL_DIAG_KILL_DEPTH=10000 (or similar) to engage. */
		extern int sDLDiagKillDepth; /* defined just below */
		if (sDLDiagKillDepth > 0 && dl_depth >= sDLDiagKillDepth) {
			port_log("SSB64: DL kill-switch firing at depth=%d (cap=%d) "
			         "ops=%llu submit=%u pushes=%u pops=%u root=0x%llX root_op=0x%02X\n",
			         dl_depth, sDLDiagKillDepth,
			         (unsigned long long)sDLOpCount,
			         (unsigned)sDLSubmitSeq,
			         sDLPushCount, sDLPopCount,
			         (unsigned long long)sDLRootPtr,
			         (unsigned)sDLRootOpcode);

			/* Identify the runaway loop's entry point by scanning the ring
			 * for the most recent 0xDE BRANCH (no-push).  That's the slot
			 * the runtime is stuck branching to — sDLCalls only tracks
			 * the first 16 unique branch targets and fills up before the
			 * runaway begins, so it's not reliable for this purpose. */
			uintptr_t loopTarget = 0;
			for (int s = 0; s < kDLRingSize; s++) {
				int idx = (sDLRingHead - 1 - s + kDLRingSize) & (kDLRingSize - 1);
				if (sDLRing[idx].opcode == 0xDE
				    && (int)((sDLRing[idx].w0 >> 16) & 1u) == 1) {
					loopTarget = (uintptr_t)sDLRing[idx].w1;
					break;
				}
			}
			if (loopTarget > 0x10000 && loopTarget < 0x00007FFFFFFFFFFFull) {
				constexpr int kHostCmdSize = 16; /* uintptr_t w0; uintptr_t w1; */
				constexpr int kDumpCmds   = 64;
				constexpr int kPreCmds    = 8;
				const uint8_t *base = reinterpret_cast<const uint8_t *>(
				    loopTarget - (uintptr_t)kPreCmds * kHostCmdSize);
				port_log("SSB64: DL kill-switch dump @ loop_target=0x%llX "
				         "(showing %d cmds starting %d before target)\n",
				         (unsigned long long)loopTarget,
				         kDumpCmds, kPreCmds);
				/* Also log buffer 0's base/length so slot math is easy
				 * to do off the raw addresses in the dump below. */
				int tid = gSYTaskmanTaskID;
				if (tid < 0 || tid >= 2) tid = 0; /* defensive clamp */
				port_log("SSB64: DL kill-switch buffer0 start=%p len=%u "
				         "head[0]=%p head[1]=%p branches[0]=%p branches[1]=%p\n",
				         (void *)sSYTaskmanDLBuffers[tid][0].start,
				         (unsigned)sSYTaskmanDLBuffers[tid][0].length,
				         (void *)gSYTaskmanDLHeads[0],
				         (void *)gSYTaskmanDLHeads[1],
				         (void *)sSYTaskmanDLBranches[0],
				         (void *)sSYTaskmanDLBranches[1]);
				for (int c = 0; c < kDumpCmds; c++) {
					const uint8_t *p = base + (size_t)c * kHostCmdSize;
					uintptr_t cw0 = 0, cw1 = 0;
					std::memcpy(&cw0, p,                 sizeof(uintptr_t));
					std::memcpy(&cw1, p + sizeof(uintptr_t), sizeof(uintptr_t));
					int rel = c - kPreCmds;
					uint8_t op = (uint8_t)((cw0 >> 24) & 0xFFu);
					int push_bit = (int)((cw0 >> 16) & 1u);
					port_log("SSB64: DL kill-switch dump  [%+3d] addr=%p "
					         "op=0x%02X b1=0x%02X w0=0x%016llX w1=0x%016llX\n",
					         rel, (const void*)p, op, push_bit,
					         (unsigned long long)cw0, (unsigned long long)cw1);
				}
			}

			throw std::runtime_error("DL kill-switch: runaway display list");
		}

		if (sDLDiagHeartbeatOps > 0 && sDLOpCount >= sDLOpHeartbeatNext) {
			port_log("SSB64: DL heartbeat submit=%u ops=%llu depth=%d last_op=0x%02X w0=0x%llX w1=0x%llX\n",
			         (unsigned)sDLSubmitSeq,
			         (unsigned long long)sDLOpCount,
			         dl_depth,
			         (unsigned)opcode,
			         (unsigned long long)w0,
			         (unsigned long long)w1);
			sDLOpHeartbeatNext = sDLOpCount + (uint64_t)sDLDiagHeartbeatOps;

			/* Once the call stack has clearly run away, dump the call-target
			 * tally and the recent-command ring so we can identify which DL
			 * is recursing. Threshold is intentionally low (>500) — normal
			 * SSB64 DL nesting tops out around 10–20. */
			if (dl_depth > 500) {
				/* Find top 4 call targets by count. */
				int top[4] = {-1, -1, -1, -1};
				for (int i = 0; i < kDLCallTargets; i++) {
					if (sDLCalls[i].count == 0) continue;
					for (int t = 0; t < 4; t++) {
						if (top[t] < 0 || sDLCalls[i].count > sDLCalls[top[t]].count) {
							for (int s = 3; s > t; s--) top[s] = top[s - 1];
							top[t] = i;
							break;
						}
					}
				}
				char buf[512];
				int off = std::snprintf(buf, sizeof(buf),
				    "SSB64: DL runaway depth=%d ops=%llu submit=%u pushes=%u pops=%u "
				    "root=0x%llX root_op=0x%02X root_w0=0x%llX root_w1=0x%llX top_targets=[",
				    dl_depth, (unsigned long long)sDLOpCount,
				    (unsigned)sDLSubmitSeq, sDLPushCount, sDLPopCount,
				    (unsigned long long)sDLRootPtr,
				    (unsigned)sDLRootOpcode,
				    (unsigned long long)sDLRootW0,
				    (unsigned long long)sDLRootW1);
				for (int t = 0; t < 4 && top[t] >= 0 && off < (int)sizeof(buf) - 48; t++) {
					off += std::snprintf(buf + off, sizeof(buf) - off, "%s0x%llX=%u",
					                     t == 0 ? "" : " ",
					                     (unsigned long long)sDLCalls[top[t]].target,
					                     sDLCalls[top[t]].count);
				}
				std::snprintf(buf + off, sizeof(buf) - off, "]");
				port_log("%s\n", buf);

				/* Dump the ring of recent commands (oldest to newest). */
				port_log("SSB64: DL recent commands (oldest→newest):\n");
				for (int i = 0; i < kDLRingSize; i++) {
					int idx = (sDLRingHead + i) & (kDLRingSize - 1);
					port_log("  [%2d] op=0x%02X depth=%d w0=0x%llX w1=0x%llX\n",
					         i, (unsigned)sDLRing[idx].opcode,
					         sDLRing[idx].depth,
					         (unsigned long long)sDLRing[idx].w0,
					         (unsigned long long)sDLRing[idx].w1);
				}
			}
		}
	}

	switch (opcode) {
	/* SSB64 ucode is F3DEX2 (gsp.fifo). Tri opcodes are 0x05/0x06/0x07,
	 * NOT F3DEX's 0xBF/0xB1/0xB5 — confirmed by histogram showing 0x05
	 * and 0x06 emitted in the hundreds per frame. RDP rect/load opcodes
	 * (0xE4, 0xF3, 0xF4, 0xF6) are shared across F3DEX/F3DEX2. */
	case 0x05: /* F3DEX2 G_TRI1 — 1 triangle */
		sFrameTriCount += 1;
		break;
	case 0x06: /* F3DEX2 G_TRI2 — 2 triangles */
	case 0x07: /* F3DEX2 G_QUAD — 2 triangles */
		sFrameTriCount += 2;
		break;
	case 0xE4: /* G_TEXRECT, fillrate-bound */
	case 0xF6: /* G_FILLRECT */
	{
		/* Both encode (ulx,uly,lrx,lry) in 10.2 fixed-point.
		 * G_TEXRECT: w0 = 0xE4 | lrx<<12 | lry; w1 = tile<<24 | ulx<<12 | uly
		 * G_FILLRECT: w0 = 0xF6 | lrx<<12 | lry; w1 = ulx<<12 | uly
		 * Pixel area = (lrx - ulx) * (lry - uly) >> 4 (10.2 → integer). */
		int lrx = (int)((w0 >> 12) & 0xFFF);
		int lry = (int)( w0        & 0xFFF);
		int ulx = (int)((w1 >> 12) & 0xFFF);
		int uly = (int)( w1        & 0xFFF);
		int w_px = (lrx - ulx) >> 2;
		int h_px = (lry - uly) >> 2;
		if (w_px > 0 && h_px > 0) {
			sFrameRectPx += w_px * h_px;
		}
		break;
	}
	case 0xF3: /* G_LOADBLOCK */
	case 0xF4: /* G_LOADTILE */
		/* Coarse: each load contributes ~512 bytes worst case. Real cost
		 * depends on tex size but we just want order-of-magnitude. */
		sFrameLoadBytes += 512;
		break;
	default:
		break;
	}
}

/* Print the top-K opcodes from the per-DL histogram, plus the first/last
 * opcode and recursion depth. Async-unsafe (uses port_log → fprintf); only
 * called from the slow-DL post-mortem path on the scheduler thread. */
static void diag_log_top_opcodes(void)
{
	struct Pair { uint32_t count; uint8_t opcode; };
	Pair top[8];
	int top_n = 0;
	for (int i = 0; i < 256; i++) {
		uint32_t c = sDLOpHist[i];
		if (c == 0) continue;
		if (top_n < 8) {
			top[top_n++] = { c, (uint8_t)i };
		} else {
			int min_idx = 0;
			for (int j = 1; j < 8; j++) if (top[j].count < top[min_idx].count) min_idx = j;
			if (c > top[min_idx].count) top[min_idx] = { c, (uint8_t)i };
		}
	}
	/* Sort top[] descending by count via insertion sort (n<=8). */
	for (int i = 1; i < top_n; i++) {
		Pair k = top[i];
		int j = i - 1;
		while (j >= 0 && top[j].count < k.count) {
			top[j + 1] = top[j];
			j--;
		}
		top[j + 1] = k;
	}
	char buf[256];
	int off = 0;
	for (int i = 0; i < top_n && off < (int)sizeof(buf) - 24; i++) {
		off += std::snprintf(buf + off, sizeof(buf) - off, "%s0x%02X=%u",
		                     i == 0 ? "" : " ", top[i].opcode, top[i].count);
	}
	port_log("SSB64: DL top_opcodes [%s]\n", buf);
}

/* Called by osSpTaskStartGo after Fast3D has processed the DL. Returns
 * the deferral count N for the SP/DP-interrupt delay queue.
 *
 * Heuristic linear cost: each tri ~= 75 RSP cycles, each fillrect/texrect
 * pixel ~= 1 RDP cycle, each load ~= the byte count. Budget is one VI
 * period ≈ 1.04M RCP cycles at 62.5 MHz. If accumulated cost exceeds the
 * budget, the DL would have overrun on real hw → return N=2 (force a
 * 1-frame contention next VI). Otherwise return N=1.
 *
 * Tunable via SSB64_RCP_CYCLE_BUDGET (default 1040000). Lower budget →
 * more freezes; higher → fewer. SSB64_RCP_FORCE_N overrides cost model
 * with a fixed N for testing (matches old SSB64_GFX_DEFER_VI semantics). */
extern "C" int port_get_last_dl_defer_n(void)
{
	static int sBudget = -1;
	static int sForceN = -1;
	static int sRectGate = -1;
	if (sBudget < 0) {
		/* Calibrated empirically against attract-mode DL cost histogram:
		 * p99 ≈ 394k, p99.5 ≈ 397k, max observed = 415k. Setting the
		 * budget at 400k means only the top ~0.1% of DLs trigger a
		 * delayed completion, giving a sparse climax-only freeze rather
		 * than uniform stutter.
		 * See `docs/freeze_frame_rcp_clock_design_2026-04-26.md` for
		 * the full design + tuning rationale. */
		const char *env = std::getenv("SSB64_RCP_CYCLE_BUDGET");
		sBudget = (env != NULL) ? std::atoi(env) : 400000;
		if (sBudget < 1000) sBudget = 1000;
		const char *fenv = std::getenv("SSB64_RCP_FORCE_N");
		sForceN = (fenv != NULL) ? std::atoi(fenv) : 0;
		/* Fillrate gate: a DL must ALSO push significant rect_px (texrect /
		 * fillrect coverage) before we treat it as an authored freeze.
		 * Empirical observation 2026-05-01: high-tri fighter-model DLs in
		 * the attract run-sequence cluster at cost 400–419k with rect_px
		 * 148–167k (false positives), while authored-climax effect DLs
		 * have rect_px ≥ 260k. The cost-only model couldn't distinguish.
		 * Default 200k sits cleanly between the two distributions. */
		const char *renv = std::getenv("SSB64_RCP_RECT_GATE");
		sRectGate = (renv != NULL) ? std::atoi(renv) : 200000;
		if (sRectGate < 0) sRectGate = 0;
		port_log("SSB64: RCP cost model — budget=%d cycles/VI, force_n=%d (0=cost-model, >=1=fixed), rect_gate=%d\n",
		         sBudget, sForceN, sRectGate);
	}
	if (sForceN >= 1) return sForceN;

	/* Scene-level allowlist gate. The cost model exists to recreate the
	 * authored climax-freeze frames in cutscenes / opening sequences /
	 * fighter intros (where original-game scene authors timed dialogue,
	 * camera, and audio around the natural N64 RDP overrun). It has no
	 * business firing in interactive menus or CSS — there are no authored
	 * freezes there to preserve, and the cost+rect heuristic mis-fires on
	 * UI-fillrate-heavy DLs (4-fighter VS CSS panels cluster at cost ≈420k,
	 * rect_px ≈236k, which trips both gates every frame and halves the
	 * game-tick rate). Issue #78. */
	extern unsigned char port_diag_get_scene_curr(void);
	extern int port_scene_wants_freeze_simulation(unsigned char scene_id);
	if (!port_scene_wants_freeze_simulation(port_diag_get_scene_curr())) {
		return 1;
	}

	int cost = sLastDLTris * 75
	         + sLastDLRectPx
	         + sLastDLLoadBytes;
	/* Heavy-DL deferral. The port's coroutine scheduler observes the held
	 * framebuffer one host frame after slot contention, so climax DLs need
	 * one extra VI of synthetic RCP latency beyond the first visible stall.
	 * This shifts all authored freezes together (portrait banners, fighter
	 * poses, stage cuts) instead of patching scene timers individually. */
	int n;
	if (cost < sBudget) {
		n = 1;
	} else if (sLastDLRectPx < sRectGate) {
		/* Cost is over budget but the load is dominated by triangles, not
		 * fillrate — looks like a fighter model render, not an authored
		 * full-screen effect. Don't freeze. */
		n = 1;
	} else {
		n = 3;
	}
	if (n < 1) n = 1;
	if (n > 3) n = 3;
	return n;
}

/* Tracks whether this VI period submitted a rendered gfx task. On real N64,
 * VI still scans out the current framebuffer when a period has no new task;
 * the port mirrors that below by presenting the cached Fast3D framebuffer. */
static int sDLSubmitsThisFrame = 0;

extern "C" void port_submit_display_list(void *dl)
{
	/* Lazy-init the GBI trace system on first DL submit. Always install
	 * the callback because Phase 3's per-DL cost model also runs through
	 * it — gbi_trace_log_cmd is the no-op fast path when tracing is off. */
	if (!sGbiTraceInitDone) {
		sGbiTraceInitDone = 1;
		gbi_trace_init();
		gfx_set_trace_callback(gbi_trace_callback);
	}
	diag_init_once();

	/* Reset per-DL accumulators before Fast3D walks the DL. */
	sFrameTriCount = 0;
	sFrameRectPx = 0;
	sFrameLoadBytes = 0;

	if (dl == NULL) {
		port_log("SSB64: WARNING — display list is NULL!\n");
		return;
	}

	auto context = Ship::Context::GetInstance();
	if (!context) {
		port_log("SSB64: WARNING — no Ship::Context in display list submit!\n");
		return;
	}

	auto window = std::dynamic_pointer_cast<Fast::Fast3dWindow>(context->GetWindow());
	if (!window) {
		port_log("SSB64: WARNING — no Fast3dWindow in display list submit!\n");
		return;
	}

	/* Begin trace frame before Fast3D processes the display list */
	gbi_trace_begin_frame();

	/* Reset per-DL diagnostic accumulators only when diagnostics are
	 * enabled. The opcode counter / histogram are written from the trace
	 * callback (one entry per opcode) while the interpreter walks the DL
	 * below, so they must be cleared just before the Fast3D call when
	 * diagnostic collection is active. */
	if (sDLDiagEnabled) {
		sDLOpCount = 0;
		sDLOpHeartbeatNext = sDLDiagHeartbeatOps > 0 ? (uint64_t)sDLDiagHeartbeatOps : UINT64_MAX;
		sDLFirstOpcode = 0xFF;
		sDLLastW0 = 0;
		sDLLastW1 = 0;
		sDLMaxDepth = 0;
		for (int i = 0; i < 256; i++) sDLOpHist[i] = 0;
		for (int i = 0; i < kDLRingSize; i++) sDLRing[i] = {};
		sDLRingHead = 0;
		for (int i = 0; i < kDLCallTargets; i++) sDLCalls[i] = {};
		sDLCallTotal = 0;
		sDLPushCount = 0;
		sDLPopCount  = 0;
		sDLPushLogged = 0;
		sDLRootPtr = (uintptr_t)dl;
		/* Best-effort read of root DL first command. dl is typed Gfx*; we
		 * read raw 8 bytes to extract opcode + w0 + w1. The host pointer
		 * may be from heap-built DL memory and should be readable; if not,
		 * we'll just see zeros (root_op=0x00 in the log). */
		{
			/* Runtime F3DGfx.words has two uintptr_t fields, so on LP64 hosts
			 * w0/w1 are 8 bytes each. We just need the opcode (top byte of
			 * w0) and the two words for the log; memcpy avoids strict-
			 * aliasing issues. */
			const uint8_t *p = reinterpret_cast<const uint8_t *>(dl);
			uintptr_t w0u = 0, w1u = 0;
			std::memcpy(&w0u, p, sizeof(uintptr_t));
			std::memcpy(&w1u, p + sizeof(uintptr_t), sizeof(uintptr_t));
			sDLRootW0 = (uint64_t)w0u;
			sDLRootW1 = (uint64_t)w1u;
			sDLRootOpcode = (uint8_t)((w0u >> 24) & 0xFFu);
		}
		sDLSubmitSeq++;
	}

	/* Optional: log taskman buffer state for the upcoming submission so we
	 * can correlate slot numbers in the runaway dump back to which buffer
	 * the renderer wrote. Triggered by SSB64_DL_DIAG_LOG_TASKMAN=1. Only
	 * dumps the first command at each buffer's `branch` and `head` so we
	 * can see whether the per-frame init or per-camera advance landed
	 * where we expected. */
	{
		static int sLogTaskman = -1;
		if (sLogTaskman < 0) {
			const char *e = std::getenv("SSB64_DL_DIAG_LOG_TASKMAN");
			sLogTaskman = (e != nullptr && e[0] != '\0' && std::atoi(e) != 0) ? 1 : 0;
		}
		if (sLogTaskman) {
			for (int i = 0; i < 4; i++) {
				port_log("SSB64: DL submit#%u taskman[%d] head=%p branches=%p\n",
				         (unsigned)sDLSubmitSeq, i,
				         (void *)gSYTaskmanDLHeads[i],
				         (void *)sSYTaskmanDLBranches[i]);
			}
		}
	}

	auto dl_start = std::chrono::steady_clock::now();

	std::unordered_map<Mtx *, MtxF> mtxReplacements;
	try {
		window->DrawAndRunGraphicsCommands(static_cast<Gfx *>(dl), mtxReplacements);
	} catch (long hr) {
		port_log("SSB64: CAUGHT DX shader exception HRESULT=0x%08lX\n", hr);
		gbi_trace_end_frame();
		return;
	} catch (...) {
		port_log("SSB64: CAUGHT unknown exception while processing display list\n");
		gbi_trace_end_frame();
		return;
	}

	auto dl_end = std::chrono::steady_clock::now();
	uint64_t dl_ms = (uint64_t)std::chrono::duration_cast<std::chrono::milliseconds>(dl_end - dl_start).count();

	sDLSubmitsThisFrame++;

	/* End trace frame after processing */
	gbi_trace_end_frame();

	/* Capture this DL's cost so port_get_last_dl_defer_n() can use it
	 * to set N for THIS task's SP/DP-interrupt deferral. osSpTaskStartGo
	 * reads it AFTER port_submit_display_list returns. */
	sLastDLTris = sFrameTriCount;
	sLastDLRectPx = sFrameRectPx;
	sLastDLLoadBytes = sFrameLoadBytes;

	if (sDLDiagEnabled) {
		bool slow_time = sDLDiagSlowMs >= 0 && dl_ms >= (uint64_t)sDLDiagSlowMs;
		bool slow_ops  = sDLDiagSlowOps >= 0 && sDLOpCount >= (uint64_t)sDLDiagSlowOps;
		if (slow_time || slow_ops) {
			extern unsigned char port_diag_get_scene_curr(void);
			extern const char *port_diag_get_scene_name(unsigned char);
			unsigned char scene = port_diag_get_scene_curr();
			port_log("SSB64: SLOW DL submit=%u ms=%llu ops=%llu max_depth=%d "
			         "first_op=0x%02X last_w0=0x%llX last_w1=0x%llX tri=%d rect_px=%d "
			         "scene=%u(%s) submits_this_frame=%d\n",
			         (unsigned)sDLSubmitSeq,
			         (unsigned long long)dl_ms,
			         (unsigned long long)sDLOpCount,
			         sDLMaxDepth,
			         (unsigned)sDLFirstOpcode,
			         (unsigned long long)sDLLastW0,
			         (unsigned long long)sDLLastW1,
			         sFrameTriCount,
			         sFrameRectPx,
			         (unsigned)scene,
			         port_diag_get_scene_name(scene),
			         sDLSubmitsThisFrame);
			diag_log_top_opcodes();
		}
	}
}

/* ========================================================================= */
/*  Public API                                                               */
/* ========================================================================= */

#if defined(__ANDROID__)
/**
 * SDL's Android HID path calls into Java (Log / UsbManager / etc.). ART
 * validates JNI string arguments against the native stack's JNI transition
 * frames; our game and service threads run on manually switched AArch64
 * stacks, so the first SDL_Init(SDL_INIT_GAMECONTROLLER) must happen on
 * the real SDL main stack before any port_coroutine_resume.
 */
static void port_android_early_init_sdl_gamecontroller(void)
{
	SDL_SetHint(SDL_HINT_JOYSTICK_THREAD, "1");
	std::string controllerDb = Ship::Context::LocateFileAcrossAppDirs("gamecontrollerdb.txt");
	int mappingsAdded = SDL_GameControllerAddMappingsFromFile(controllerDb.c_str());
	if (mappingsAdded >= 0) {
		port_log("SSB64: Android pre-init gamecontrollerdb \"%s\" (%d)\n",
		         controllerDb.c_str(), mappingsAdded);
	} else {
		port_log("SSB64: Android pre-init gamecontrollerdb failed \"%s\" (%s)\n",
		         controllerDb.c_str(), SDL_GetError());
	}
	if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0) {
		port_log("SSB64: FATAL — Android pre-init SDL_Init(GAMECONTROLLER): %s\n",
		         SDL_GetError());
	}
}
#endif

/* ---- Per-scene SYTaskmanSetup overrides (port-side, no submodule edits) ----
 *
 * Some N64-authored scene taskman setups allocate DL buffers that are
 * tight to the byte on real hardware but tip into overflow on the PC
 * port (where the port-specific scissor widening in syRdpSetViewport
 * lets a few more bitmap tiles per sprite pass the cull).  Overflowing
 * a DL buffer overwrites its trailing gSPEndDisplayList terminator, and
 * because Fast3D's GfxExecStack::branch pushes nullptr sentinels on
 * every non-push branch, the interpreter walks leftover sprite-tile
 * commands past the buffer end indefinitely — exhausting its stack and
 * stalling the game coroutine (watchdog SIGUSR1 ~3 s later).
 *
 * Each entry below names the offending scene-setup symbol and the
 * corrected buffer size.  Run once before any scene loads.
 *
 * See docs/bugs/opening_sector_dl_buffer_overflow_2026-05-12.md for the
 * full root-cause writeup of the OpeningSector case.  Adding more
 * entries: identify the symbol by checking
 * `mv*TaskmanSetup` / `sc*TaskmanSetup` / etc. in the offending scene's
 * source; the symbol is global (`D` in nm output) on the port, so an
 * extern declaration + field write is all that's needed. */

/* Layout prefix of decomp's `SYTaskmanSceneSetup`, copied verbatim from
 * decomp/src/sys/taskman.h up to the field we need to write.  Declaring
 * this locally instead of #including the decomp header keeps the port
 * TU isolated from the rest of the decomp's C-only definitions; only the
 * write to `dl_buffer0_size` matters and a static_assert pins the field
 * offset so a future struct reshuffle in decomp can't silently break us. */
struct PortTaskmanScenePrefix {
	uint16_t flags;
	void   (*func_update)(void);
	void   (*func_draw)(void);
	void    *arena_start;
	size_t   arena_size;
	int32_t  taskgfx_num;
	int32_t  contexts_num;
	size_t   dl_buffer0_size; /* the field we patch */
};
static_assert(offsetof(PortTaskmanScenePrefix, dl_buffer0_size) == 48,
              "SYTaskmanSceneSetup layout drift — recheck taskman.h before patching");

static void port_patch_taskman_setups(void)
{
	/* `mvOpeningSectorTaskmanSetup` is the global SYTaskmanSetup in
	 * decomp/src/mv/mvopening/mvopeningsector.c.  Its first member is a
	 * SYTaskmanSceneSetup, so reinterpreting as PortTaskmanScenePrefix
	 * lets us write `dl_buffer0_size` directly. */
	extern PortTaskmanScenePrefix mvOpeningSectorTaskmanSetup;

	const size_t newSize = sizeof(Gfx) * 10000;
	mvOpeningSectorTaskmanSetup.dl_buffer0_size = newSize;

	port_log("SSB64: PortGameInit — bumped mvOpeningSectorTaskmanSetup.dl_buffer0_size to %zu bytes (~%zu GBI slots)\n",
	         newSize, newSize / sizeof(Gfx));
}

void PortGameInit(void)
{
	port_log("SSB64: PortGameInit — initializing coroutine system\n");

	/* Per-scene Taskman buffer-size patches.  Must run before
	 * syTaskmanStartTask is called for any scene that we override. */
	port_patch_taskman_setups();

	/* Convert the main thread to a fiber so it can participate in
	 * coroutine switching. */
	port_coroutine_init_main();

#if defined(__ANDROID__)
	port_android_early_init_sdl_gamecontroller();
#endif

	/* Create the game coroutine with a large stack (1 MB).
	 * This will host the entire game: syMainLoop -> Thread 1 -> Thread 5
	 * -> scheduler, controller, audio init -> scManagerRunLoop. */
	sGameCoroutine = port_coroutine_create(game_coroutine_entry, NULL, 1024 * 1024);
	if (sGameCoroutine == NULL) {
		port_log("SSB64: FATAL — failed to create game coroutine\n");
		return;
	}

	/* Resume the game coroutine to start the boot chain.
	 * It will run through syMainLoop -> osInitialize -> create Thread 1
	 * -> start Thread 1 -> Thread 1 creates Thread 5 -> Thread 5 inits
	 * peripherals, creates scheduler/audio/controller threads.
	 *
	 * Each thread runs in its own sub-coroutine (created by osStartThread).
	 * They all yield when they hit osRecvMesg(BLOCK) on empty queues.
	 * Eventually control returns here after the entire boot chain has
	 * progressed as far as it can without VI ticks. */
	port_log("SSB64: Starting game coroutine (boot sequence)\n");
	port_coroutine_resume(sGameCoroutine);
	port_log("SSB64: Boot sequence yielded — entering frame loop\n");

	/* Start the hang watchdog now that the boot chain has yielded back.
	 * This avoids firing false alarms during the long synchronous boot. */
	port_watchdog_init();
}

static int sFrameCount = 0;

/* ========================================================================= */
/*  Screenshot capture (env-var driven)                                      */
/* ========================================================================= */
/*
 * Env vars:
 *   SSB64_SCREENSHOT_FRAMES=10,55,100  — frames to capture
 *   SSB64_SCREENSHOT_FRAMES=all        — capture every frame (heavy!)
 *   SSB64_SCREENSHOT_DIR=<path>        — output dir (default debug_traces/screenshots)
 *
 * When unset/empty, feature is OFF and adds only one bool check per frame.
 */

static bool sScreenshotInited = false;
static bool sScreenshotEnabled = false;
static bool sScreenshotAllFrames = false;
static std::unordered_set<int> sScreenshotFrames;
static std::string sScreenshotDir;

static void port_screenshot_init_once(void)
{
	if (sScreenshotInited) {
		return;
	}
	sScreenshotInited = true;

	const char *frames_env = std::getenv("SSB64_SCREENSHOT_FRAMES");
	if (frames_env == nullptr || frames_env[0] == '\0') {
		sScreenshotEnabled = false;
		return;
	}

	const char *dir_env = std::getenv("SSB64_SCREENSHOT_DIR");
	sScreenshotDir = (dir_env != nullptr && dir_env[0] != '\0')
		? dir_env
		: "debug_traces/screenshots";

	if (std::strcmp(frames_env, "all") == 0) {
		sScreenshotAllFrames = true;
	} else {
		/* Parse comma-separated integer list. Ignores malformed tokens. */
		const char *p = frames_env;
		while (*p != '\0') {
			while (*p == ',' || *p == ' ' || *p == '\t') {
				p++;
			}
			if (*p == '\0') {
				break;
			}
			char *end = nullptr;
			long v = std::strtol(p, &end, 10);
			if (end != p && v >= 0 && v <= 0x7FFFFFFF) {
				sScreenshotFrames.insert(static_cast<int>(v));
			}
			if (end == p) {
				/* Couldn't parse — skip a char to avoid infinite loop. */
				p++;
			} else {
				p = end;
			}
		}
	}

	sScreenshotEnabled = sScreenshotAllFrames || !sScreenshotFrames.empty();

	if (sScreenshotEnabled) {
		std::error_code ec;
		std::filesystem::create_directories(sScreenshotDir, ec);
		if (ec) {
			port_log("SSB64: screenshot: failed to create dir '%s': %s\n",
				sScreenshotDir.c_str(), ec.message().c_str());
		}
		if (sScreenshotAllFrames) {
			port_log("SSB64: screenshot capture ENABLED (all frames) dir='%s'\n",
				sScreenshotDir.c_str());
		} else {
			port_log("SSB64: screenshot capture ENABLED (%zu frames) dir='%s'\n",
				sScreenshotFrames.size(), sScreenshotDir.c_str());
		}
	}
}

static void port_screenshot_maybe_capture(int frame)
{
	if (!sScreenshotEnabled) {
		return;
	}
	if (!sScreenshotAllFrames && sScreenshotFrames.count(frame) == 0) {
		return;
	}

	char path[1024];
	std::snprintf(path, sizeof(path), "%s/frame_%d.png",
		sScreenshotDir.c_str(), frame);

	int ok = portFastCaptureBackbufferPNG(path);
	if (ok) {
		port_log("SSB64: screenshot frame %d -> %s\n", frame, path);
	} else {
		port_log("SSB64: screenshot frame %d FAILED -> %s\n", frame, path);
	}
}

void PortPushFrame(void)
{
	// Process cheats safely before the frame updates
	lbBackupApplyCheats();

	/* Capture the wall-clock start of this PortPushFrame for the
	 * frame-pacing fallback below. */
	auto frameStart = std::chrono::steady_clock::now();

	/* Pump SDL events so the window stays responsive and WindowIsRunning
	 * detects the close button. HandleEvents also updates controller state. */
	auto context = Ship::Context::GetInstance();
	if (context) {
		auto window = context->GetWindow();
		if (window) {
			window->HandleEvents();
		}
	}
	/* Propagate the previous frame's queued framebuffer (if any) to VI's
	 * "current" slot. The scheduler's CheckReadyFramebuffer fnCheck reads
	 * osViGetCurrent/NextFramebuffer to decide whether the slot the game
	 * wants to draw into is still locked by VI; without this rotation
	 * those getters would always report NULL and the scheduler would
	 * never stall, so the intentional freeze frames during fighter
	 * intros and the desk-to-stage transition would never appear. Run
	 * this BEFORE posting INTR_VRETRACE so old gfx completions are
	 * delivered before the next game tick can tear down scene memory. */
	port_vi_simulate_vblank();

	/* Post a VI retrace event to the scheduler's message queue. See
	 * port_make_os_mesg_int() above for why we don't just write
	 * `(OSMesg)INTR_VRETRACE` here. */
	osSendMesg(&gSYSchedulerTaskMesgQueue, port_make_os_mesg_int(INTR_VRETRACE), OS_MESG_NOBLOCK);

	/* Resume all service thread coroutines that are waiting for messages.
	 * This runs multiple rounds to handle cascading messages:
	 *   Round 1: Scheduler picks up VRETRACE, sends ticks to clients
	 *   Round 2: Controller reads input, game logic runs one frame
	 *   Round 3+: Display list submitted, scheduler processes GFX task, etc.
	 * Each thread runs until it yields at osRecvMesg(BLOCK) on empty queue. */
	port_resume_service_threads();

	port_enhancement_stage_hazards_tick();
	port_widescreen_tick();

	sFrameCount++;

	/* VI-style idle presentation: when no gfx task was submitted this VI,
	 * original hardware still scans out the current RDRAM framebuffer.
	 * Fast3D normally presents only from DrawAndRunGraphicsCommands(), so
	 * 0-submit frames can otherwise hold an older swapchain image. Present
	 * the cached game framebuffer texture through the normal GUI/window path
	 * without re-running any display list or touching game memory. */
	if (sDLSubmitsThisFrame == 0) {
		bool idlePresented = false;
		static int sFreezePacing = -1;
		if (sFreezePacing < 0) {
			const char *env = std::getenv("SSB64_FREEZE_PACING");
			sFreezePacing = (env != nullptr) ? std::atoi(env) : 1;
		}
		if (sFreezePacing) {
			auto context = Ship::Context::GetInstance();
			auto window = context
				? std::dynamic_pointer_cast<Fast::Fast3dWindow>(context->GetWindow())
				: nullptr;
			if (window) {
				idlePresented = window->PresentCurrentFramebuffer();
			}

			if (!idlePresented) {
				/* Fallback pace to one VI period if there is no cached
				 * framebuffer yet. Normal idle presents pace through the
				 * backend's SwapBuffers path. */
				auto target = frameStart + std::chrono::microseconds(16667);
				auto coarseTarget = target - std::chrono::microseconds(2000);
				auto now = std::chrono::steady_clock::now();
				if (now < coarseTarget) {
					std::this_thread::sleep_for(coarseTarget - now);
				}
				while (std::chrono::steady_clock::now() < target) {
					/* busy-wait */
				}
			}
		}
	}
	sDLSubmitsThisFrame = 0;

	/* Tell the hang watchdog a frame completed. */
	port_watchdog_note_frame_end();

	/* Screenshot capture: env-var driven, zero cost when disabled. */
	port_screenshot_init_once();
	port_screenshot_maybe_capture(sFrameCount);

	/* RenderDoc capture trigger: env-var driven, zero cost when disabled.
	 * TriggerCapture() tells RenderDoc to capture the NEXT Present interval,
	 * so calling it here causes frame (sFrameCount + 1) to be captured.
	 * The one-frame lag is small and consistent — document it in the
	 * feature's env-var contract. */
	portRenderDocOnFrame(static_cast<unsigned int>(sFrameCount));

	{
		static auto sStartTime = std::chrono::steady_clock::now();
		auto now = std::chrono::steady_clock::now();
		double elapsed = std::chrono::duration<double>(now - sStartTime).count();
		if (sFrameCount <= 60 || (sFrameCount % 60 == 0)) {
			port_log("SSB64: Frame %d complete (t=%.2fs)\n", sFrameCount, elapsed);
		}
	}
}

void PortGameShutdown(void)
{
	port_watchdog_shutdown();
	if (sGameCoroutine != NULL) {
		port_coroutine_destroy(sGameCoroutine);
		sGameCoroutine = NULL;
	}
	port_log("SSB64: Game coroutine destroyed\n");
}
