// HAVE_ENDIAN_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ENDIAN_H

// NOTE: overrides the builtin check, which keys off __GLIBC__. That macro
// is defined by glibc's own headers, not by the compiler, so it is never
// visible to this predefs-based probe: the builtin check is always false
// on real glibc/Linux, silently falling back to the empty compat/endian
// stand-in where TpmProfile_Common.h actually needs real __BYTE_ORDER/
// __LITTLE_ENDIAN/__BIG_ENDIAN macros (its __linux__/__CYGWIN__/
// __gnu_hurd__ branch), corrupting TPM2 marshaling on every little-endian
// Linux target. Keyed off __linux__ instead, a genuine compiler predefine.

/* Check for the endian.h header which provides macros for byte-order
 * manipulation.
 *
 * Available since Linux/glibc, Cygwin, and GNU/Hurd. NetBSD also reaches
 * this header (TpmProfile_Common.h routes only FreeBSD/DragonFly to
 * sys/endian.h directly, so NetBSD falls through to endian.h too).
 * OpenBSD ships it as well. Not needed for Mac OS or FreeBSD/DragonFly:
 * TpmProfile_Common.h takes its own dedicated __APPLE__/__FreeBSD__/
 * __DragonFly__ branches instead and never touches this header's macros.
 * Not available on Windows, including MinGW.
 */
#if defined(__linux__)   || \
    defined(__CYGWIN__)  || \
    defined(__gnu_hurd__) || \
    defined(__NetBSD__)  || \
    defined(__OpenBSD__)
#  define HAVE_ENDIAN_H 1
#endif
