/*
 * AArch64 stack swap for Android coroutines (Bionic has no ucontext).
 * Must match PortCoRegs layout in coroutine_android.cpp.
 *
 * void port_co_swap(PortCoRegs *save, PortCoRegs *load);
 *
 * Callee-saved: d8-d15, x19-x28, fp (x29), lr (x30), sp.
 * x16-x18 are used as scratch; caller-saved live on each fiber's stack.
 */
    .text
    .align 4
    .global port_co_swap
    .type port_co_swap, %function
port_co_swap:
    mov x17, x0
    mov x18, x1

    /* Save SIMD callee-saved (lower 64 bits of v8-v15). */
    stp d8, d9, [x17, #0]
    stp d10, d11, [x17, #16]
    stp d12, d13, [x17, #32]
    stp d14, d15, [x17, #48]

    stp x19, x20, [x17, #64]
    stp x21, x22, [x17, #80]
    stp x23, x24, [x17, #96]
    stp x25, x26, [x17, #112]
    stp x27, x28, [x17, #128]
    stp x29, x30, [x17, #144]

    mov x16, sp
    str x16, [x17, #160]

    /* Load destination */
    ldr x16, [x18, #160]
    ldp x29, x30, [x18, #144]
    ldp x27, x28, [x18, #128]
    ldp x25, x26, [x18, #112]
    ldp x23, x24, [x18, #96]
    ldp x21, x22, [x18, #80]
    ldp x19, x20, [x18, #64]

    ldp d8, d9, [x18, #0]
    ldp d10, d11, [x18, #16]
    ldp d12, d13, [x18, #32]
    ldp d14, d15, [x18, #48]

    mov sp, x16
    ret

    .size port_co_swap, .-port_co_swap

/* First entry: x19 = PortCoroutine*, then C entry. */
    .align 4
    .global port_co_bootstrap
    .type port_co_bootstrap, %function
port_co_bootstrap:
    mov x0, x19
    bl port_co_run_entry
    /* port_co_run_entry tail-swaps; no return */

    .size port_co_bootstrap, .-port_co_bootstrap
