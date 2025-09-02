#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "error.h"
#include "utils.h"


bool validateInput(char *filename) {
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        perror("Input error");
        return false;
    }
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    return true;
}
bool validateFile(char *filename, FILE *fptr) {
    if (fptr == NULL) {
        handleError("Error opening file.\n");
        return false;
    }
    if (strlen(filename) == 0) {
        handleError("Filename cannot be empty.\n");
        return false;
    }
    return true;
}