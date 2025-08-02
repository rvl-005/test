// gcc src/main.c -o bin/main.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
// This program prompts the user to input a string, and then outputs a file with said string.

int main() {
    char *inputString = malloc(100 * sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter something!: \n");
    scanf("%99s", inputString);  // safer input with width specifier

    createFile(inputString);

    printf("String written to file successfully.\n");

    free(inputString);
    return 0;
}