# Sprite LUT stale-token SEGV in `Fast::gfx_step` (2026-05-08)

## Symptoms

Late in a session, the runtime log starts emitting:

```
[error] RelocPointerTable: invalid/stale token 0x________
        (generation=0x___, max_index=____,
         caller=/.../src/lb/lbcommon.c:3013)
```

shortly followed by a SIGSEGV deep inside the F3D interpreter:

```
#0 Fast::gfx_step  libultraship/src/fast/interpreter.cpp:5632
   opcode = (int8_t)(cmd->words.w0 >> 24);   // cmd points at a bogus address
#1 Fast::Interpreter::Run
#2 Fast3dWindow::DrawAndRunGraphicsCommands
#3 port_submit_display_list      port/gameloop.cpp:195
#4 osSpTaskStartGo                port/stubs/n64_stubs.c:479
```

Reported in PR #13 comment 4408464727.

## Root cause

`src/lb/lbcommon.c` reads `sprite->LUT` as a 32-bit relocation token in three
places — line ~2816 (`G_IM_FMT_CI` in the unconditional branch of
`lbCommonPrepSObjAttr`), line ~2845 (the `attr-equal` switch), and line 3013
(`lbCommonSetExternSpriteParams`, the LUT-tracker update). All three call
`PORT_RESOLVE(sprite->LUT)` directly.

If the source `Sprite` was loaded via a path that misses the post-pass1
half-swap repair window (sibling pointer hadn't been registered yet when
`portFixupSprite` first ran), the LUT token's generation can mismatch the live
table. `PORT_RESOLVE` logs the stale-token error and **returns NULL**.

That NULL is then handed to `gDPLoadTLUT(...)`, which bakes it into the next
`G_LOADTLUT` command in the display list. When `Fast::gfx_step` later walks
into the resulting bogus command pointer, it dereferences arbitrary memory
and SEGVs at the address shown in the report.

The pattern is the same as the existing fix for `sprite->bitmap` in
`lbCommonDecodeSpriteBitmapsSiz4b` and `lbCommonMakeSObjForGObj` (already
guarded in `port/decomp-patches/lbcommon-port-sprite-reloc-tokens.patch`):
retry the half-swap repair, then NULL-skip the consumer.

## Fix

Extended the existing port patch
(`port/decomp-patches/lbcommon-port-sprite-reloc-tokens.patch`) to add three
more PORT-only sites:

- `lbCommonPrepSObjAttr` G_IM_FMT_CI (unconditional branch): retry
  `portFixupSpriteRelocTokensOnly(sprite)`, then skip the
  `gDPLoadTLUT` call when the resolved LUT is `NULL`.
- `lbCommonPrepSObjAttr` G_IM_FMT_CI (`attr-equal` switch arm): same retry +
  NULL-skip; preserve the `_lut != sLBCommonPrevSpriteLUT` change-detection
  semantics by short-circuiting with `_lut != NULL &&` first.
- `lbCommonSetExternSpriteParams`: retry the half-swap fixup before the
  `PORT_RESOLVE` call so the cached `sLBCommonPrevSpriteLUT` reflects the
  repaired token whenever repair is possible.

Non-`PORT` decomp source paths remain byte-identical via `#ifdef PORT`/`#else`
guards. Skipping the TLUT load on a stale token leaves a sprite frame with
the *previous* TLUT bound (visual glitch) instead of feeding the F3D
interpreter a bogus pointer (crash) — the same trade-off already accepted for
NULL-bitmap returns in `lbCommonDecodeSpriteBitmapsSiz4b`.

## Per-`Bitmap.buf` follow-up (PR comment 4410476377)

A separate SEGV with the same root cause was reported against
`lbCommonDecodeBitmapSiz4b`:

```
#0 lbCommonDecodeBitmapSiz4b (bitmap_csr=0x40fff, bitmap_buf=0x81fff,
                              bitmap_start=0x0)               lbcommon.c:2373
#1 lbCommonDecodeSpriteBitmapsSiz4b (sprite=0x55555ab91680)   lbcommon.c:2410
#2 lbCommonMakeSObjForGObj                                    lbcommon.c:3120
#3 mnMessageMakeMessage                                       mnmessage.c:190
```

The argument values are the smoking gun: with `n=48` and `res=532480`,
`(NULL + res/2 - 1) = 0x40fff` (`bitmap_csr`), `(NULL + res - 1) = 0x81fff`
(`bitmap_buf`), `NULL = 0x0` (`bitmap_start`) — i.e. `PORT_RESOLVE(bitmap[n-1].buf)`
returned `NULL` and `(NULL + offset)` was passed straight into the decoder.
The decoder then walks down from a bogus `bitmap_csr` address and SEGVs.

This is the exact same family as the LUT case but at a per-`Bitmap` field
that the existing patch did not yet cover. The first guard the patch added —
`if (bitmap == NULL) return;` — only catches the case where the *array*
pointer itself is unresolvable; here the array resolved fine
(`bitmap=0x55555ab91660`) but its individual `buf` token did not.

The fix mirrors the LUT pattern: inside the loop body, after computing
`res`, retry `portFixupBitmap(&bitmap[n - 1])` and `continue` past the
`lbCommonDecodeBitmapSiz4b` call if `PORT_RESOLVE(bitmap[n - 1].buf)` is
still `NULL`. Skipping the decode for one frame leaves the sprite undecoded
(brief visual glitch) instead of SEGVing the whole process. The non-PORT
decomp path is unchanged.

## Audit hook

Any other `PORT_RESOLVE(sprite->LUT)` or `PORT_RESOLVE(*->bitmap)` call site
in the rendering path that feeds the result directly to a `gDP*` macro
without a NULL guard is a candidate for the same stale-token-into-DL crash.
The deeper fix — make `Sprite` half-swap repair atomic with the file load so
no consumer ever sees a stale token — lives in `port/bridge/lbreloc_byteswap.cpp`
and is out of scope for this defensive patch.
