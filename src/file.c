#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "error.h"
#include "utils.h"
#include "file.h"

void createFile() {
    char filename[256];
    printf("Enter the name of your file: \n");
    validateInput(filename);
    FILE *fptr = fopen(filename, "w");
    validateFileInput(filename, fptr);
    printf("Page creation complete!\n");
    fclose(fptr);
}

void appendToFile(const char *filename) {
    FILE *fptr = fopen(filename, "a");
    if (fptr == NULL) {
        handleError("Error opening file for appending.\n");
        return;
    }

    char inputString[1000];
    bool isWriting = true;

    do {
        printf("Please write something. Type ESC alone and press Enter to exit.\n");
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';

        if (strcmp(inputString, "ESC") == 0) {
            printf("Would you like to stop writing? y or n? ");
            char response = getchar();
            getchar(); // Clear newline

            if (response == 'y' || response == 'Y' || response == '\n') {
                printf("Returning to menu...\n");
                isWriting = false;
                break; // Exit loop cleanly
            } else {
                printf("Resuming loop...\n");
                continue;
            }
        }

        fprintf(fptr, "%s\n", inputString);

    } while (isWriting);

    fclose(fptr);
    printf("Successfully wrote to page!\n");
}


void readFile() {
    char filename[256];
    printf("What file do you want to read?: \n");
    validateInput(filename);
    FILE *fptr = fopen(filename, "r");
    char inputString[1000];
    validateFileInput(filename, fptr);
    while(fgets(inputString, sizeof(inputString), fptr)) {
            printf("%s", inputString);
    }
    printf("Successfully read page!\n");
    fclose(fptr);
}

