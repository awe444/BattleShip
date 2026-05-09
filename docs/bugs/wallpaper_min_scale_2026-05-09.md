# Stage Wallpaper Minimum-Scale Floor (PORT)

**Date:** 2026-05-09
**Status:** RESOLVED (port enhancement)
**Sibling:** [overscan_inset_strip_2026-05-08](overscan_inset_strip_2026-05-08.md)

## Symptom

After the [overscan-inset strip](overscan_inset_strip_2026-05-08.md)
expanded the rendered viewport from the original CRT-overscan-safe
inset of `(10,10)-(310,230)` to the full `(0,0)-(320,240)` frame,
several stage backgrounds left visible artifacts in the outer 10 px
border on every side:

- Black border ring whenever the engine kept the wallpaper at its
  default zoom (close camera, players near each other).
- On Race to the Finish (`grWallpaperMakeBonus3`), stale framebuffer
  contents flickered in the borders because the bonus-stage wallpaper
  is just a `gsDPFillRectangle` clear and the original clear extents
  matched the inset.

Foreground geometry was unaffected — the issue was background-only and
visible only in stages (menus tolerate the borders).

## Root cause

Stage wallpaper sprites are **300×220** inside a **320×240** frame.
The original game authored them inset by 10 px on every side so the
visible image fit inside the CRT-overscan-safe region. The engine
already supports dynamic zoom (`grWallpaperCalcPersp`,
`grWallpaperSectorProcUpdate`) — when players spread out it scales the
wallpaper to between the floor (`1.004x`) and `2.0x`, and at any scale
beyond `~1.091x` the wallpaper covers the whole frame even on PORT.

Three code paths in `decomp/src/gr/grwallpaper.c` set or clamp the
wallpaper scale, and on the original game all three converged on the
inset region for at least some camera configurations:

1. `grWallpaperCalcPersp` — most stages (Hyrule, Dream Land, Saffron,
   Congo, Peach's, Mushroom Kingdom, Planet Zebes, Last/Master Hand).
   Floors `scale` at `1.004F` and clamps the panning position to the
   `10.0F` inset boundary.
2. `grWallpaperSectorProcUpdate` — Sector Z. Same `1.004F` floor.
3. `grWallpaperMakeStatic` — Yoster Island, Yoster Small, all bonus
   stages, 1P Training Mode. Hardcodes `scale = 1.0F`, position
   `(10, 10)`, and uses `SP_FASTCOPY` (which uses RDP COPY mode, so
   it can't scale).

The Bonus3 fill rectangle in `dGRWallpaperDisplayList` is a separate
fourth site.

## Fix

PORT-only patch
[`port/decomp-patches/wallpaper-min-scale.patch`](../../port/decomp-patches/wallpaper-min-scale.patch)
applied to `decomp/src/gr/grwallpaper.c` at configure time.

Defines:

- `PORT_WALLPAPER_MIN_SCALE = 1.10F` — slightly above the
  `max(320/300, 240/220) ≈ 1.0909` minimum required for the wallpaper
  to fully cover a 320×240 frame.
- `PORT_WALLPAPER_MIN_POS_X = -5.0F`,
  `PORT_WALLPAPER_MIN_POS_Y = -1.0F` — top-left position that centers a
  300×220 sprite scaled by 1.10 inside 320×240.

Per-site changes (all gated by `#ifdef PORT`; non-PORT paths are
byte-identical to the prior decomp source):

| Site | Change |
|------|--------|
| `dGRWallpaperDisplayList` (line 43) | `gsDPFillRectangle(10,10,310,230)` → `gsDPFillRectangle(0,0,GS_SCREEN_WIDTH_DEFAULT,GS_SCREEN_HEIGHT_DEFAULT)` |
| `grWallpaperCalcPersp` scale floor | `1.004F` → `PORT_WALLPAPER_MIN_SCALE` |
| `grWallpaperCalcPersp` pan clamp | inset constant `10.0F` → `0.0F` (max position) and `(-width-10.0F)+320.0F` → `(-width-0.0F)+320.0F` (min) |
| `grWallpaperSectorProcUpdate` scale floor | `1.004F` → `PORT_WALLPAPER_MIN_SCALE`. Position formula `10.0F - (300.0F * scale)` is mathematically equivalent to `(320 - 300*temp)/2` and remains exactly centered for any scale, so unchanged. |
| `grWallpaperMakeStatic` | scale `1.0F` → `PORT_WALLPAPER_MIN_SCALE`, position `(10,10)` → `(PORT_WALLPAPER_MIN_POS_X, PORT_WALLPAPER_MIN_POS_Y)`, and **drop `SP_FASTCOPY`** because COPY mode cannot scale (the same dance that `mvopening*.c` does whenever it bumps wallpaper scale above 1.0) |
| `grWallpaperMakeCommon` | initial scale `1.004F` → `PORT_WALLPAPER_MIN_SCALE`, initial position recentered. Also avoids a one-frame top-left flash before the first `grWallpaperCommonProcUpdate` tick. |
| `grWallpaperMakeSector` | initial position only; scale untouched (set by proc update on first tick) |

Movie/cutscene wallpapers in `decomp/src/mv/mvopening/*.c` are out of
scope — they already pre-scale to 2.0×/4.0× with scripted positions.

## Trade-offs

- **Yoster Island / bonus stages / Training Mode** never zoomed in
  vanilla; they now always render the wallpaper at 1.10× with bilinear
  filtering. The slight softness vs. the original 1.0× pixel-perfect
  blit is the unavoidable cost of full-frame coverage and is similar
  in character to the rest of the wallpaper in any fully-zoomed-out
  camera state.
- The Sector Z `SP_FASTCOPY`-less fall-through was already exercised
  by the `1.004F`-scale default, so no new code path is opened up.
- All non-PORT code paths are byte-identical to the prior decomp
  source.

## Audit hooks

- Any new wallpaper drawing path that hardcodes `1.0F`, `1.004F`, or
  `10.0F` position constants for stage backgrounds should consult
  `PORT_WALLPAPER_MIN_SCALE` and the matching position macros.
- If a future stage wallpaper has dimensions other than 300×220 (e.g.
  re-authored content for higher resolutions), the scale floor needs
  to be recomputed as `max(320/W, 240/H)`.
- Setting any non-1.0× scale on a sprite while leaving `SP_FASTCOPY`
  set is a silent no-op for the scaling — `mvopening*.c` and the new
  `grWallpaperMakeStatic` PORT branch both clear the flag first.
