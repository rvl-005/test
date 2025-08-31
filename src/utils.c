#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

void createFile(const char *filename) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        handleError("Error opening file.\n");
        return;
    }
    printf("Page creation complete!\n");
    fclose(fptr);
}

void appendToFile(const char *filename) {
    FILE *fptr = fopen(filename, "a");
    char inputString[1000];
    
    if (fptr == NULL) {
        handleError("Error opening file for appending.\n");
        return;
    } else {
        printf("Please write something: \n");
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';
        fprintf(fptr, "%s\n", inputString);
        printf("Successfully wrote to page!\n");
        fclose(fptr);
    }
}

void readFile(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    char inputString[1000];

    if (fptr == NULL) {
        handleError("Error opening file for reading.\n");
    } else {
        while(fgets(inputString, sizeof(inputString), fptr)) {
            printf("%s", inputString);
        }
        printf("Successfully read page!\n");
        fclose(fptr);
    }
}