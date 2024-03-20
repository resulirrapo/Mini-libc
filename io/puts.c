#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int puts(const char* str) {
    int input = write(1, str, strlen(str));

    if (input != '\0') {
        write(1, "\n", 1);
        return 0;
    }
    return -1;
}
