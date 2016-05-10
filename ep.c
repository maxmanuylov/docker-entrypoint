#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        return 0;
    }

    char** _argv = malloc(argc * sizeof(char*));
    if (_argv == 0) {
        return 254;
    }

    for (int i = 1; i < argc; i++) {
        _argv[i - 1] = argv[i];
    }
    _argv[argc - 1] = 0;

    execvp(_argv[0], _argv);

    int err = errno;
    fprintf(stderr, "Failed to run command \"%s\": %s\n", _argv[0], strerror(err));

    return err;
}