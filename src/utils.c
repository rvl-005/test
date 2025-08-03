#include <stdio.h>
#include <stdlib.h>
#include "error.h"

FILE *fptr;

void createFile(const char *inputString) {
    char *input = malloc(100 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        handleError("Error opening file");
        return;
    }
    fprintf(fptr, "%s\n", input);
    free(input);
    fclose(fptr);
}

void appendToFile(const char *inputString) {
    char *input = malloc(100 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    fptr = fopen("output.txt", "a");
    if (fptr == NULL) {
        handleError("Error opening file for appending");
        return;
    }
    fprintf(fptr, "%s\n", input);
    free(input);
    fclose(fptr);
}

void readFile(const char *filename) {
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        handleError("Error opening file for reading");
    }
}