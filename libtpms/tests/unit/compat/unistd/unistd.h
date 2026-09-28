/* Only added to the include path when the target compiler has no unistd.h
 * of its own (see libtpms/tests/unit/buildfile). base64decode.c does not
 * use any of its declarations, so an empty stand-in is sufficient here.
 */
