#include <stdlib.h>
#include <unistd.h>

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

    execv(_argv[0], _argv);

    return 255;
}