/*
 * SPDX-License-Identifier: MIT
 *
 * Per-element texture-filter override for the SSB64 port.
 *
 * libultraship's global "Texture Filter" CVar (gTextureFilter) selects the
 * default sampler / shader behaviour for textures whose DL leaves filtering
 * at G_TF_BILERP / G_TF_AVERAGE.  When the original DL explicitly emits
 * gsDPSetTextureFilter(G_TF_POINT) the LUS interpreter clamps the sampler
 * to GL_NEAREST / MTLSamplerMinMagFilterNearest and skips the 3-point
 * shader path (verified in libultraship/src/fast/backends/gfx_*.cpp), so a
 * DL-level G_TF_POINT always wins regardless of the CVar.
 *
 * SSB64's sprite library (decomp/src/lb/lbcommon.c) sets G_TF_BILERP for
 * every 2D primitive, which makes HUD / menus / title sprites blur whenever
 * the user picks Linear or Three-Point.  Ghostship and SoH avoid this by
 * forcing point filtering on the sprite path.  We replicate that with a
 * tiny substitution helper that the patched sprite-library emission sites
 * route their filter argument through:
 *
 *   port_force_2d_filter(orig_filter)
 *       Returns G_TF_POINT when CVAR_TEXTURE_FILTER_2D is in "Force None"
 *       mode, otherwise returns the original N64 filter value untouched.
 *
 * 3D rendering paths (fighters, stages, items, particles) never call this
 * helper, so their filtering continues to follow the global CVar.
 */
#ifndef PORT_RENDER_FORCE_POINT_FILTER_H
#define PORT_RENDER_FORCE_POINT_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

/* CVAR_TEXTURE_FILTER_2D values. */
enum {
    PORT_TF2D_FORCE_POINT = 0, /* Default: HUD / sprites always nearest. */
    PORT_TF2D_MATCH_GLOBAL = 1 /* Use whatever gTextureFilter says. */
};

/* True when the user wants 2D draws forced to nearest filtering. */
int port_force_2d_point_filter_enabled(void);

/* Returns G_TF_POINT when forcing is enabled, else the original filter. */
int port_force_2d_filter(int n64_filter);

/* Counter-based passthrough scope.  Specific sprite-library callers (stage
 * wallpapers, the title-screen animated fire texture) want their pixels to
 * follow the global texture-filter CVar like 3D geometry does, even when
 * the user has selected "Force None" for the 2D filter.  Pushing increments
 * a counter which makes both port_force_2d_point_filter_enabled() and
 * port_force_2d_filter() behave as if forcing were disabled; popping
 * decrements it.  Calls must be balanced (push/pop pairs may nest). */
void port_force_2d_filter_push_passthrough(void);
void port_force_2d_filter_pop_passthrough(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PORT_RENDER_FORCE_POINT_FILTER_H */
