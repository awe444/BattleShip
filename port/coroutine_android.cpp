/**
 * coroutine_android.cpp — same-thread stackful coroutines for Android (arm64).
 *
 * A pthread-based backend was tried first, but GLES/SDL are tied to the thread
 * that created the context; running the game coroutine on a worker pthread
 * caused SIGABRT shortly after boot. This file uses AArch64 callee-saved
 * register + SP switching (same model as POSIX ucontext / Win32 fibers).
 */

#if defined(__ANDROID__) || defined(ANDROID)

#if !defined(__aarch64__)
#error "BattleShip Android build only supports arm64-v8a coroutines (see abiFilters)."
#endif

#include "coroutine.h"
#include "port_watchdog.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cstddef>

#define MIN_STACK_SIZE (64 * 1024)

/* Offsets must match coroutine_android_aarch64.S */
typedef struct {
	uint64_t d8_d9[2];
	uint64_t d10_d11[2];
	uint64_t d12_d13[2];
	uint64_t d14_d15[2];
	uint64_t x19, x20, x21, x22, x23, x24, x25, x26, x27, x28;
	uint64_t fp;
	uint64_t lr;
	uint64_t sp;
} PortCoRegs;

static_assert(sizeof(PortCoRegs) == 168, "PortCoRegs size drift — update .S");
static_assert(offsetof(PortCoRegs, sp) == 160, "PortCoRegs.sp offset drift");

struct PortCoroutine {
	PortCoRegs fiber_regs;
	PortCoRegs caller_regs;
	void (*entry)(void *);
	void *arg;
	int finished;
	char *stack_mem;
	size_t stack_size;
};

static PortCoroutine *sCurrentCoroutine = NULL;

extern "C" {
void port_co_swap(PortCoRegs *save, PortCoRegs *load);
void port_co_bootstrap(void);
void port_co_run_entry(PortCoroutine *co);
}

extern "C" void port_co_run_entry(PortCoroutine *co)
{
	co->entry(co->arg);
	co->finished = 1;
	sCurrentCoroutine = NULL;
	port_co_swap(&co->fiber_regs, &co->caller_regs);
	/* Entry returned without ever yielding — caller context must be valid. */
}

void port_coroutine_init_main(void)
{
}

PortCoroutine *port_coroutine_create(void (*entry)(void *), void *arg,
				     size_t stack_size)
{
	if (stack_size < MIN_STACK_SIZE) {
		stack_size = MIN_STACK_SIZE;
	}

	PortCoroutine *co = (PortCoroutine *)calloc(1, sizeof(PortCoroutine));
	if (co == NULL) {
		return NULL;
	}

	co->stack_mem = (char *)malloc(stack_size);
	if (co->stack_mem == NULL) {
		free(co);
		return NULL;
	}

	co->stack_size = stack_size;
	co->entry = entry;
	co->arg = arg;
	co->finished = 0;

	memset(&co->fiber_regs, 0, sizeof(co->fiber_regs));
	memset(&co->caller_regs, 0, sizeof(co->caller_regs));

	uintptr_t sp =
	    (uintptr_t)(co->stack_mem + co->stack_size) & ~(uintptr_t)15ULL;
	sp -= 32; /* ABI red zone / align scratch */
	co->fiber_regs.sp = (uint64_t)sp;
	co->fiber_regs.x19 = (uint64_t)co;
	co->fiber_regs.lr = (uint64_t)(void *)&port_co_bootstrap;

	return co;
}

void port_coroutine_destroy(PortCoroutine *co)
{
	if (co == NULL) {
		return;
	}
	if (co->stack_mem != NULL) {
		free(co->stack_mem);
		co->stack_mem = NULL;
	}
	free(co);
}

void port_coroutine_resume(PortCoroutine *co)
{
	if (co == NULL || co->finished) {
		return;
	}

	PortCoroutine *prev = sCurrentCoroutine;
	sCurrentCoroutine = co;
	port_co_swap(&co->caller_regs, &co->fiber_regs);
	sCurrentCoroutine = prev;
}

void port_coroutine_yield(void)
{
	PortCoroutine *co = sCurrentCoroutine;
	if (co == NULL) {
		fprintf(stderr,
			"SSB64: port_coroutine_yield called outside coroutine\n");
		return;
	}

	port_watchdog_note_yield();

	sCurrentCoroutine = NULL;
	port_co_swap(&co->fiber_regs, &co->caller_regs);
}

int port_coroutine_is_finished(PortCoroutine *co)
{
	if (co == NULL) {
		return 1;
	}
	return co->finished;
}

int port_coroutine_in_coroutine(void)
{
	return sCurrentCoroutine != NULL;
}

#endif /* __ANDROID__ || ANDROID */
