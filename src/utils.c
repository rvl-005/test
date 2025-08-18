#include <stdio.h>
#include <stdlib.h>
#include "error.h"

FILE *fptr;
char *input;


void createFile(const char *inputString) {
    char *input = malloc(100 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    fptr = fopen("page.txt", "w");
    if (fptr == NULL) {
        handleError("Error opening file");
        return;
    } else printf("Page creation complete!\n");
    printf("Please write something: \n");
    fprintf(fptr, "%s\n", input);
    free(input);
    fclose(fptr);
}

void appendToFile(const char *inputString) {
    if (input == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    fptr = fopen("page.txt", "a");
    if (fptr == NULL) {
        handleError("Error opening file for appending\n");
        return;
    } else printf("Successfully wrote to page!\n");
    fprintf(fptr, "%s\n", input);
    free(input);
    fclose(fptr);
}

void readFile(const char *filename) {
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        handleError("Error opening file for reading\n");
    } else printf("Successfully read page!\n");
}