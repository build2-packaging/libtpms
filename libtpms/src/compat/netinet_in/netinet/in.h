/* Only added to the include path when the target compiler has no
 * netinet/in.h of its own (see libtpms/src/buildfile). The TPM 1.2 code
 * under TPM_POSIX includes it purely for the byte order conversions
 * (htonl(), htons(), ntohl(), ntohs()), which winsock2.h provides directly
 * on such targets.
 */
#ifndef LIBTPMS_COMPAT_NETINET_IN_H
#define LIBTPMS_COMPAT_NETINET_IN_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

#endif
