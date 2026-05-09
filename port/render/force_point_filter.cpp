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

extern "C" int port_force_2d_point_filter_enabled(void) {
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
