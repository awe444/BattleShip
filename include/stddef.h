#ifndef __STDDEF_H__
#define __STDDEF_H__

#include <PR/ultratypes.h>

/* N64 shim: libc headers (e.g. Android NDK <unistd.h>) expect ptrdiff_t from
 * <stddef.h>. Do not use #include_next here — include order must stay stable
 * for IDO builds. HOST/PORT toolchains expose __PTRDIFF_TYPE__. */
#if defined(PORT) && defined(__PTRDIFF_TYPE__)
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#endif

#ifdef _MSC_VER
/* MSVC: offsetof is a compiler intrinsic */
#ifndef offsetof
#define offsetof(type, member) ((size_t)&(((type*)0)->member))
#endif
#elif !defined(__sgi)
/* GCC/Clang: use built-in offsetof macro */
#define offsetof(type, member) __builtin_offsetof(type, member)
#else
/* IDO: use macro from Indy headers */
#define offsetof(s, m) (size_t)(&(((s*)0)->m))
#endif

#endif /* __STDDEF_H__ */
