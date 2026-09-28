/* Only added to the include path when the target compiler has no unistd.h
 * of its own (see libtpms/src/buildfile). Provides the handful of POSIX/GNU
 * declarations used on such targets: the process ID query backing
 * TPM_CAP_PROCESS_ID, STDERR_FILENO, and dprintf()/vdprintf() (glibc
 * extensions historically declared alongside unistd.h) used for debug
 * logging to a raw file descriptor.
 */
#ifndef LIBTPMS_COMPAT_UNISTD_H
#define LIBTPMS_COMPAT_UNISTD_H

#include <io.h>
#include <process.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef _PID_T_
#define _PID_T_
typedef int pid_t;
#endif

#define getpid _getpid

#define STDERR_FILENO 2

static __inline int vdprintf(int fd, const char *format, va_list args)
{
    char buf[1024];
    int n = vsnprintf(buf, sizeof(buf), format, args);

    if (n > 0) {
        if (n >= (int)sizeof(buf))
            n = (int)sizeof(buf) - 1;
        _write(fd, buf, (unsigned int)n);
    }
    return n;
}

static __inline int dprintf(int fd, const char *format, ...)
{
    va_list args;
    int n;

    va_start(args, format);
    n = vdprintf(fd, format, args);
    va_end(args);
    return n;
}

#endif
