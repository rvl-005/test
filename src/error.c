#include <stdio.h>
#include <errno.h>
#include "error.h"

void handleError(const char *message) {
    switch(errno) {
        case ENOENT:
            printf("Error: %s - File not found.\n", message);
            break;
        case ENOMEM:
            printf("Error: %s - Not enough memory.\n", message);
            break;
        case EINVAL:
            printf("Error: %s - Invalid argument.\n", message);
            break;
    }
}