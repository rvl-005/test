#include <stdio.h>

FILE *fptr;

void createFile(const char *inputString) {
    fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        handleError("Error opening file");
        return;
    }
    fprintf(fptr, "%s\n", inputString);
    fclose(fptr);
}
void readFile(filename) {
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        handleError("Error opening file for reading");
    }
}