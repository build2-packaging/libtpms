#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int vasprintf(char **strp, const char *fmt, va_list ap)
{
    va_list ap2;
    int n;

    va_copy(ap2, ap);
    n = vsnprintf(NULL, 0, fmt, ap2);
    va_end(ap2);
    if (n < 0)
        return -1;

    *strp = malloc((size_t)n + 1);
    if (!*strp)
        return -1;

    vsnprintf(*strp, (size_t)n + 1, fmt, ap);

    return n;
}

int asprintf(char **strp, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vasprintf(strp, fmt, ap);
    va_end(ap);

    return n;
}
