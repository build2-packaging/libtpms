#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    const char *path;
    long expected, actual;
    FILE *f;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <file> <expected-size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    path = argv[1];
    expected = atol(argv[2]);

    f = fopen(path, "rb");
    if (f == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", path);
        return EXIT_FAILURE;
    }

    fseek(f, 0, SEEK_END);
    actual = ftell(f);
    fclose(f);

    if (actual != expected) {
        fprintf(stderr,
                "Unexpected size of %s.\nExpected: %ld\nGot     : %ld\n",
                path, expected, actual);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
