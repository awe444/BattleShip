# OpeningSector intro hang — DL buffer 0 overflow during cockpit fade-in

**Status:** RESOLVED — port-level patch in `port/gameloop.cpp` (`port_patch_taskman_setups`) runs at `PortGameInit` and bumps the global `mvOpeningSectorTaskmanSetup.scene_setup.dl_buffer0_size` from `sizeof(Gfx) * 2500` to `sizeof(Gfx) * 10000` before any scene loads.  The decomp submodule is untouched.

## Symptom

On a fresh boot, the attract loop reaches the `nSCKindOpeningSector` overlay — the "Great Fox flying past the camera, cockpit fading in" scene authored at `sySchedulerGetTicCount() >= 3420` (~57 s after boot, see `mvOpeningSectorFuncStart`'s startup wait loop). After roughly 5–10 s of that scene running, the game-loop coroutine stalls. The port watchdog (`port/port_watchdog.cpp::kHangThresholdMs = 3000`) then fires `SIGUSR1` to the main thread and the SIGABRT-handler logs:

```
SSB64: ---- main-thread backtrace (fault context) ----
libc.so.6(pthread_kill)
libc.so.6(gsignal)
libc.so.6(abort)
ImGui::NewFrame
Ship::Gui::StartFrame
Fast::Fast3dWindow::PresentCurrentFramebuffer
PortPushFrame
main
```

`pthread_kill` is the watchdog's `pthread_kill(sMainThread, SIGUSR1)`. The backtrace looks misleading (ImGui in flight) because the watchdog signal is asynchronous — it arrives while the main thread is in PresentCurrentFramebuffer waiting on a stuck Fast3D submission.

Total observed time from boot to hang: ~1 minute (matches user report).

## Root cause

`mvOpeningSectorTaskmanSetup` allocates `dl_buffer0_size = sizeof(Gfx) * 2500` — 2500 GBI command slots. The OpeningSector scene emits more than 2500 commands per frame once the cockpit sprite's animated scale-up (`mvOpeningSectorCockpitProcUpdate`: `scale += 0.025` per frame from 0.25 to 1.0) finishes growing it to full screen.

The overflow source is `lbCommonDrawSObjBitmap`. Per submit (steady state, after cockpit scaled to ~1.0):

| Sprite | nbitmaps | bmheight | calls / frame | emitted ops |
|---|---|---|---|---|
| Wallpaper × 4 (one per quadrant) | 44 | 5 | 44 each | 4 × 44 × 11 = 1936 |
| Cockpit (centered, fade-in) | 48 | 5 | 48 | 48 × 11 = 528 |
| **Subtotal** | — | — | 224 | **2464** |
| Camera prep / RDP setup / frame-end chain / Great Fox + Arwing 3D model bind | — | — | — | ~110 |
| **Grand total** | — | — | — | **~2574** |

Each `lbCommonDrawSObjBitmap` call hits the slow path (11 GBI ops: `SETTIMG`, `SETTILE`, `LOADSYNC`, `LOADBLOCK`, `PIPESYNC`, `SETTILE`, `SETTILESIZE`, `TEXRECT` (3 cmds: `E4` + `E1` + `F1`), `PIPESYNC`) because each Bitmap entry has a unique `bitmap->buf` (every horizontal stripe of the wallpaper / cockpit is a separate TMEM load).

`port/gameloop.cpp`'s instrumented run produced this directly: `SSB64: DLBuffer OVERFLOW kind=0 used=41168 alloc=40000`, i.e. **2573 commands written into a 2500-slot buffer** — 73 commands past the end.

The 73 trailing commands land in heap memory immediately after the buffer allocation, which (because no other allocator touches that region between frames) holds bytes left over from earlier writer iterations — all valid GBI sprite-tile commands with no `gSPEndDisplayList` terminator. Frame-end chaining (`func_800053CC` in `decomp/src/sys/taskman.c`) appends a `gSPBranchList(head[0])` from the main DL into this region; the very last command the buffer was supposed to contain (a `G_ENDDL`) has been overwritten by the next sprite tile.

Fast3D's interpreter (`libultraship/src/fast/interpreter.cpp`) walks the chain. `GfxExecStack::branch` pushes a `nullptr` sentinel onto `cmd_stack` on every non-push branch, so `cmd_stack.size()` grows monotonically. Diagnostics captured:

```
SSB64: DL kill-switch firing at depth=1000 (cap=1000) ops=65489 submit=3054
       pushes=1562 pops=14 root=0x7AD93D8063A0 root_op=0xDE
```

A push/pop imbalance of 1548 (pushes 1562 — pops 14) shows the interpreter ran nothing but BRANCH-class commands for the last 1500 iterations. The kill-switch dump at the runaway entry point `loop_target = buffer_start + buffer_length` (precisely the byte one past the allocation) reveals the trailing 64+ commands are all canonical `lbCommonDrawSObjBitmap` 11-cmd tile sequences with monotonically incrementing texture pointers (+0xF08 each) and Y positions, confirming the writer's overflow signature.

The game-loop coroutine sits blocked in `Fast::Interpreter::Run` waiting for the unbounded chain to terminate. Liveness counters stop advancing; the watchdog fires `SIGUSR1` 3 s later.

## Why N64 hardware doesn't hit this

The math is the same on N64 (`sizeof(Gfx) = 8`, buffer = 20000 bytes = same 2500 slots), so the same writer count would overflow into the same heap-slack region. Two reasons the real cartridge survives:

1. **RSP is hardware, not a software state machine.** The RSP-side ucode walks DL commands by DMA fetch through a hard-bounded fetch stack (~10 entries). Past-the-end commands either get dropped on a hardware fetch stall, decoded into noop / garbled rendering, or crash one frame later — they don't pin the CPU thread in an infinite-loop interpreter.
2. **Visual artifact, not a hang.** If the overflow produces a corrupt frame on N64, the next VI flips to a new framebuffer and the writer resets its head. The damage is bounded to one frame's flicker. On the port, the interpreter is the master clock and the chain has to terminate before any other coroutine runs.

The decomp itself is technically vulnerable on real hardware (the boundary is razor-thin — 2574 / 2500 = 103 %), but the original game ships within the safety margin produced by N64-specific microcode behavior and a slightly different scissor (the 10-pixel CRT-overscan inset in `syRdpSetViewport`'s non-PORT path) that culls a handful of trailing cockpit/wallpaper tiles. The port's PORT-specific scissor expansion (`syRdpSetViewport` PORT branch detects `(10,10,310,230)` and rewrites to `(0,0,320,240)` to fill modern displays — see `overscan_inset_strip_2026-05-08`) draws those extra tiles too and tips the scene past the buffer's headroom.

## Fix

`port/gameloop.cpp::port_patch_taskman_setups` — called once from `PortGameInit`, before the game coroutine starts.  Declares the relevant prefix of `SYTaskmanSceneSetup` locally as `PortTaskmanScenePrefix` (matched against the decomp header with a `static_assert(offsetof(...dl_buffer0_size) == 48)` so a future struct reshuffle in decomp can't silently break us), externs the global `mvOpeningSectorTaskmanSetup`, and writes `dl_buffer0_size = sizeof(Gfx) * 10000`.  The decomp submodule is **not** modified — the patch lives entirely in the port repo.

Could have been a smaller bump (3500–4000 covers the observed overflow with ample headroom), but the larger allocation:

- Absorbs any future increase in cockpit fade detail / additional sprites without a re-tune.
- Costs nothing observable on a modern host (~160 KB of host RAM in a transient scene buffer).
- Documents intent: "this scene's buffer was undersized for the port's wider visible area."

The same scaffolding is the right pattern for any future scene whose `*TaskmanSetup` is undersized on the port — add another extern + assignment inside `port_patch_taskman_setups` and no submodule edit is required.

## Verification

- Pre-fix: hang reproducible at ~50–60 s after boot, every run. Kill-switch dump shows 224 sprite calls / 2464 ops + 110 ops other = 2574 ops emitted into a 2500-slot buffer; runaway loop_target = buffer end + 1.
- Post-fix: ran `./BattleShip` for 95 s with `SSB64_DL_DIAG=1 SSB64_DL_DIAG_KILL_DEPTH=1000`. No `kill-switch firing`, no `DLBuffer OVERFLOW`, no watchdog. Per-submit bitmap tally reaches the full 224-call steady state (4 × wallpaper@44 + cockpit@48) repeatedly without stalling.

## Related diagnostics (kept for future debugging)

All retained diagnostics live in `port/gameloop.cpp` — the decomp submodule has zero diagnostic instrumentation added by this fix.

- Kill-switch (`SSB64_DL_DIAG_KILL_DEPTH`) — when the Fast3D `cmd_stack` depth exceeds the cap, throws to abort the runaway submit cleanly, logs ops / pushes / pops / root pointer, then dumps the buffer-0 layout (start / length / `gSYTaskmanDLHeads[0..1]` / `sSYTaskmanDLBranches[0..1]`) plus a 64-command hexdump around the runaway entry point.  The accessors externed at file scope (`gSYTaskmanDLHeads`, `sSYTaskmanDLBranches`, `sSYTaskmanDLBuffers`, `gSYTaskmanTaskID`) reach the decomp's file-scope globals directly through the linker — they're all global `B`/`D` symbols on nm.
- Per-opcode trace ring (`sDLRing`, 32 entries) — captured on every Fast3D step so the kill-switch can find the most recent `0xDE BRANCH` (no-push) and use its `w1` as the runaway loop target.
- Optional taskman submission log (`SSB64_DL_DIAG_LOG_TASKMAN=1`) — dumps `gSYTaskmanDLHeads[0..3]` and `sSYTaskmanDLBranches[0..3]` per submit.
- "DLBuffer OVERFLOW" line from `decomp/src/sys/taskman.c::syTaskmanCheckBufferLengths` (existing decomp PORT branch, not added by this fix) — fires whenever any DL buffer's `head` advances past `start + length`, with the kind / used / alloc / start / head fields.

The diagnostics fire only when `SSB64_DL_DIAG` is set in the environment; default release builds get the same per-frame cost as before this investigation.

## Audit hook

Any `SYTaskmanSetup::dl_buffer*_size = sizeof(Gfx) * N` with `N <= 3000` in a scene that draws full-frame multi-bitmap sprites at scale ≥ 1.0 should be reviewed under PORT. The 10-pixel scissor expansion adds ~5–10 % more visible bitmap tiles per sprite, and at the original buffer's headroom that is enough to overflow. Candidates to inspect: every overlay using `lbCommonMakeSObjForGObj` with `Sprite` assets where `nbitmaps × bmheight ≥ 220` (i.e. designed to fill the 220-px-tall N64 visible region).
