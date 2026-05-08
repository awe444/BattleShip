# Overscan inset strip (PORT-only)

**Date:** 2026-05-08
**Status:** RESOLVED (port enhancement, not a regression)
**Affected files:**
- `src/sys/rdp.c` — `syRdpSetViewport`, `syRdpResetSettings`
- `src/sys/objdisplay.c` — `dGCCameraScissor{Top,Bottom,Left,Right}` defaults
- `src/lb/lbcommon.c` — `lbCommonDrawSprite` clamp
- `src/lb/lbfade.c` — `lbFadeProcDisplay` fill rect

## Symptom

The PC port rendered with ~3% black borders on every side of the 4:3 frame.
The displayed image was 300×220 inside a 320×240 frame instead of filling the
full 320×240.

## Cause

This is original-game behaviour, not a port bug. SSB64 was authored against
1999-era CRTs and inset every camera viewport by 10 pixels on each side as a
**CRT-overscan-safe margin** so that important pixels (HUD, damage %, stock
icons, fighter portraits) stayed inside the visible area on TVs that cropped
the outer ~5–10% of the picture. The same inset also bought back ~14% of RDP
fill-rate, which mattered on N64 with 4 fighters + particle FX + stage
geometry.

The inset is encoded in five places that all use the literal value `10`:

1. **Camera viewport** — hundreds of call sites pass
   `syRdpSetViewport(&cobj->viewport, 10.0F, 10.0F, 310.0F, 230.0F)` (e.g.
   `mvopening*.c`, `mvending.c`, `ifcommon.c`).
2. **Per-frame default scissor** — `syRdpResetSettings` emits
   `gDPSetScissor(..., 10·sx, 10·sy, W − 10·sx, H − 10·sy)`.
3. **Per-camera scissor clamp** — `func_80016000` / `func_8001663C` /
   `func_80018134` in `objdisplay.c` derive the scissor extents from the
   viewport's `vscale`/`vtrans` and then clamp through the mutable globals
   `dGCCameraScissor{Top,Bottom,Left,Right}`, defaulted to 10.
4. **Sprite-camera scissor clamp** — `lbCommonDrawSprite` does the same
   clamp inline with literal `* 10` constants.
5. **Screen-fade overlay** — `lbFadeProcDisplay` draws the fade colour with
   `gDPFillRectangle(..., 10, 10, 310, 230)`.

The PC port's renderer (libultraship Fast3D) replays the GBI faithfully, so
the same inset shows up on screen.

## Fix

PORT-only intercept guarded by `#ifdef PORT` at every site:

1. **`syRdpSetViewport`** — detect the canonical
   `(10.0F, 10.0F, 310.0F, 230.0F)` extents and substitute
   `(0, 0, GS_SCREEN_WIDTH_DEFAULT, GS_SCREEN_HEIGHT_DEFAULT)`. Other
   extents (e.g. the magnified `ifcommon` viewport at line 1668) are left
   untouched.
2. **`syRdpResetSettings`** — emit the default scissor at full frame
   `(0, 0, gSYVideoResWidth, gSYVideoResHeight)`.
3. **`dGCCameraScissor{Top,Bottom,Left,Right}`** — initialize to 0 instead
   of 10 so the per-camera scissor clamp doesn't re-clip the now-expanded
   viewport back to the inset.
4. **`lbCommonDrawSprite`** — `#ifndef PORT` around the literal-`10` clamp.
5. **`lbFadeProcDisplay`** — full-frame fill rect
   `(0, 0, GS_SCREEN_WIDTH_DEFAULT, GS_SCREEN_HEIGHT_DEFAULT)` so screen
   transitions don't leave a faint un-faded ring at the original inset.

The non-PORT code paths are byte-identical to the prior decomp source, so
ROM-matching builds are unaffected.

## Caveats

This is the **blunt-fix** approach — it expands the active draw region but
does **not** re-author HUD / menu layout, which were positioned assuming the
300×220 region. Possible cosmetic side effects:

- HUD elements (damage %, stock icons, timer) sit slightly closer to the
  frame edges than the original devs intended.
- Cinematics framed against the 300×220 region may now show small amounts
  of off-screen geometry near the edges.
- Stages whose camera bounds were tuned for the inset may briefly reveal
  level seams during dramatic camera moves.

If any of these become objectionable, the proper long-term fix is the
"correct" approach from the prior analysis: audit the camera/viewport init
sites and matching projection matrices and re-author HUD layout for the
expanded frame — i.e. the same kind of game-side patching that real
widescreen support will need.

## Class

Port display enhancement — same family as `display_list_widening_2026-04-06`
(decomp DL emits N64-canonical values that the modern renderer can be made
to widen; intercept at the GBI emit point and rescale).
