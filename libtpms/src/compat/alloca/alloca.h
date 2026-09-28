/* Only added to the include path when the target compiler has no alloca.h
 * of its own (see libtpms/src/buildfile). FreeBSD ships no such header at
 * all: alloca() is declared directly by <stdlib.h> there (already included
 * unconditionally by NVMarshal.c above its own #include <alloca.h>), so an
 * empty stand-in is sufficient here.
 */
