/*
 * SPDX-License-Identifier: MIT
 *
 * See force_point_filter.h for design notes.
 */

#include "force_point_filter.h"

#include "../gui/Compat.h"

#include <libultraship/bridge/consolevariablebridge.h>

/* G_TF_POINT value from decomp/include/PR/gbi.h — encoded into the second
 * word of the SetOtherMode_H GBI command as `(0 << G_MDSFT_TEXTFILT)`.
 * Hardcoded here to avoid pulling in the full N64 OS header pile. */
#define PORT_GBI_G_TF_POINT 0x0000

/* Per-thread would be nice, but the SSB64 game thread is the only producer
 * of GBI for the sprite library, so a plain static counter is sufficient
 * and avoids pulling <thread> into the helper. */
static int s_port_force_2d_passthrough_depth = 0;

extern "C" void port_force_2d_filter_push_passthrough(void) {
    ++s_port_force_2d_passthrough_depth;
}

extern "C" void port_force_2d_filter_pop_passthrough(void) {
    if (s_port_force_2d_passthrough_depth > 0) {
        --s_port_force_2d_passthrough_depth;
    }
}

extern "C" int port_force_2d_point_filter_enabled(void) {
    if (s_port_force_2d_passthrough_depth > 0) {
        return 0;
    }
    /* Default value PORT_TF2D_FORCE_POINT (0) — opt-out, not opt-in. */
    return CVarGetInteger(CVAR_TEXTURE_FILTER_2D, PORT_TF2D_FORCE_POINT)
           == PORT_TF2D_FORCE_POINT;
}

extern "C" int port_force_2d_filter(int n64_filter) {
    if (port_force_2d_point_filter_enabled()) {
        return PORT_GBI_G_TF_POINT;
    }
    return n64_filter;
}

/* Forward-declared wrapper used by the wallpaper draw-callback registration
 * is implemented as a static helper in decomp/src/gr/grwallpaper.c (it
 * needs the GObj* signature from the decomp headers, so it lives there
 * rather than here). */
