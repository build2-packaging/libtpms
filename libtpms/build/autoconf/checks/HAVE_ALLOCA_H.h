// HAVE_ALLOCA_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ALLOCA_H

// NOTE: keep consistent with HAVE_UNISTD_H/HAVE_SYS_TIME_H/
// HAVE_NETINET_IN_H, which also key off BUILD2_AUTOCONF_MACOS.

/* Check for the alloca.h header.
 *
 * Available since Linux/glibc and Mac OS. Not available on Windows
 * including MinGW (alloca() is declared by malloc.h there instead), nor
 * on FreeBSD, OpenBSD, or NetBSD (alloca() is declared directly by
 * stdlib.h on all three).
 */
#if defined(__linux__) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_ALLOCA_H 1
#endif
