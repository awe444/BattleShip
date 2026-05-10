#include "RelocPointerTable.h"

#include <cstdlib>
#include <cstring>
#include <spdlog/spdlog.h>

/**
 * Flat array mapping token index → pointer.
 * Index 0 is reserved (NULL token). Valid indices start at 1.
 *
 * Token layout: [12 bits generation][20 bits index]
 *   - Generation range [0x100..0xFFF] = 3840 generations before wrap.
 *     Days of continuous play — effectively infinite for real users.
 *
 *     The MIN of 0x100 (not 0x080 or 0x001) is load-bearing: it ensures
 *     the top BYTE of every emitted token, `(token >> 24)`, is always
 *     >= 0x10. libultraship's `Interpreter::SegAddr` (fast/interpreter.cpp)
 *     falls back from `portRelocTryResolvePointer` to a classic N64
 *     segmented-address decode whenever the resolve returns NULL:
 *
 *         segNum = (uint32_t)(w1 >> 24);
 *         if (segNum < MAX_SEGMENT_POINTERS && mSegmentPointers[segNum])
 *             return mSegmentPointers[segNum] + (w1 & 0x00FFFFFF);
 *
 *     MAX_SEGMENT_POINTERS is 16 (0x10).  SSB64 binds segment 0xE every
 *     frame to the graphics heap, so any stale/NULL-resolving token whose
 *     top byte landed in [0x00..0x0F] would be silently aliased to
 *     `gSYTaskmanGraphicsHeap.ptr + low24(token)` instead of failing
 *     loudly.  The 8/24 layout we used originally happened to satisfy
 *     this invariant by construction (gen lived in 0x80..0xFF, top byte
 *     == gen).  When we widened to 12/20 the top byte became `gen >> 4`,
 *     which can dip into the 0x00..0x0F segment-pointer range whenever
 *     gen lands in 0x000..0x0FF — producing visible menu-graphics
 *     corruption on long sessions and after libultraship started
 *     evicting cached display-list widenings on every reloc-file load
 *     (forces re-resolution through the current generation, which makes
 *     every transient NULL-resolve land in SegAddr's fallback).
 *
 *     Keep `TOKEN_GENERATION_MIN >= (MAX_SEGMENT_POINTERS << 4)` whenever
 *     touching either the layout or libultraship's segment table size.
 *
 *   - 1M indices per scene. Old layout allowed 16M; real measurements
 *     show typical usage well under 100K, so 1M leaves 10x headroom.
 *     Anything that registers >1M tokens in a single scene needs a real
 *     conversation about why before we widen this back.
 *
 * Initial capacity: 256K entries (~2 MB). Grows by doubling if needed,
 * capped at TOKEN_INDEX_MASK (1M).
 */

static constexpr uint32_t INITIAL_CAPACITY = 256 * 1024;
static constexpr uint32_t TOKEN_GENERATION_SHIFT = 20;
static constexpr uint32_t TOKEN_INDEX_MASK = 0x000FFFFF;     // 20 bits = 1M-1
static constexpr uint32_t TOKEN_GENERATION_MAX = 0xFFF;      // 12 bits
// Must satisfy (TOKEN_GENERATION_MIN >> 4) >= MAX_SEGMENT_POINTERS (= 16) so
// that (token >> 24) never falls inside libultraship's segment-pointer table.
// See header comment above for the full rationale.
static constexpr uint32_t TOKEN_GENERATION_MIN = 0x100;

static void **sPointerTable = nullptr;
static uint32_t sNextIndex = 1;
static uint32_t sCapacity = 0;
static uint32_t sGeneration = TOKEN_GENERATION_MIN;

static void ensureCapacity(void)
{
	if (sPointerTable == nullptr)
	{
		sCapacity = INITIAL_CAPACITY;
		sPointerTable = (void **)calloc(sCapacity, sizeof(void *));
	}
	else if (sNextIndex >= sCapacity)
	{
		uint32_t newCapacity = sCapacity * 2;
		if (newCapacity > TOKEN_INDEX_MASK)
		{
			spdlog::error("RelocPointerTable: token index capacity exhausted");
			abort();
		}
		spdlog::info("RelocPointerTable: growing {} -> {} entries", sCapacity, newCapacity);
		sPointerTable = (void **)realloc(sPointerTable, newCapacity * sizeof(void *));
		memset(sPointerTable + sCapacity, 0, (newCapacity - sCapacity) * sizeof(void *));
		sCapacity = newCapacity;
	}
}

static uint32_t makeToken(uint32_t index)
{
	return (sGeneration << TOKEN_GENERATION_SHIFT) | index;
}

static bool decodeToken(uint32_t token, uint32_t *index)
{
	uint32_t generation = token >> TOKEN_GENERATION_SHIFT;
	uint32_t decodedIndex = token & TOKEN_INDEX_MASK;

	if ((token == 0) || (generation != sGeneration) ||
	    (decodedIndex == 0) || (decodedIndex >= sNextIndex))
	{
		return false;
	}

	*index = decodedIndex;
	return true;
}

extern "C" {

uint32_t portRelocRegisterPointer(void *ptr)
{
	if (ptr == nullptr)
	{
		return 0;
	}

	ensureCapacity();

	uint32_t index = sNextIndex++;
	sPointerTable[index] = ptr;
	return makeToken(index);
}

void *portRelocResolvePointer(uint32_t token)
{
	return portRelocResolvePointerDebug(token, nullptr, 0);
}

void *portRelocResolvePointerDebug(uint32_t token, const char *file, int line)
{
	if (token == 0)
	{
		return nullptr;
	}

	uint32_t index = 0;
	if (!decodeToken(token, &index))
	{
		if (file != nullptr)
		{
			spdlog::error("RelocPointerTable: invalid/stale token 0x{:08X} "
			              "(generation=0x{:03X}, max_index={}, caller={}:{})",
			              token, sGeneration, sNextIndex - 1, file, line);
		}
		else
		{
			spdlog::error("RelocPointerTable: invalid/stale token 0x{:08X} "
			              "(generation=0x{:03X}, max_index={})",
			              token, sGeneration, sNextIndex - 1);
		}
		return nullptr;
	}

	return sPointerTable[index];
}

void *portRelocTryResolvePointer(uint32_t token)
{
	uint32_t index = 0;
	if (!decodeToken(token, &index))
	{
		return nullptr;
	}

	return sPointerTable[index];
}

uint32_t portRelocTokenTableGeneration(void)
{
	return sGeneration;
}

void portRelocResetPointerTable(void)
{
	sNextIndex = 1;
	sGeneration++;
	if (sGeneration > TOKEN_GENERATION_MAX)
	{
		sGeneration = TOKEN_GENERATION_MIN;
	}

	if (sPointerTable != nullptr)
	{
		memset(sPointerTable, 0, sCapacity * sizeof(void *));
	}
}

} // extern "C"
