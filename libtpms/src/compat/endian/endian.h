/* Only added to the include path when the target compiler has no endian.h
 * of its own (see libtpms/src/buildfile). The upstream sources that
 * #include <endian.h> do not use any of its macros or functions, so an
 * empty stand-in is sufficient here.
 */
