/* Only added to the include path when the target compiler has no
 * sys/time.h of its own (see libtpms/src/buildfile). Provides struct
 * timeval and gettimeofday(), which the TPM 1.2 code under TPM_POSIX uses
 * for TPM_GetTimeOfDay() on such targets.
 */
#ifndef LIBTPMS_COMPAT_SYS_TIME_H
#define LIBTPMS_COMPAT_SYS_TIME_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <windows.h>

static __inline int gettimeofday(struct timeval *tv, void *tz)
{
    /* FILETIME ticks are in 100ns units since 1601-01-01; convert to
     * seconds/microseconds since the Unix epoch (1970-01-01).
     */
    static const unsigned __int64 epoch_diff = 116444736000000000ULL;
    FILETIME ft;
    unsigned __int64 ticks;

    (void)tz;
    GetSystemTimeAsFileTime(&ft);
    ticks = ((unsigned __int64)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    ticks -= epoch_diff;
    tv->tv_sec  = (long)(ticks / 10000000ULL);
    tv->tv_usec = (long)((ticks % 10000000ULL) / 10);
    return 0;
}

#endif
