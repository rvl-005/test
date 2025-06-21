// gcc src/main.c -o bin/main.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// This program prompts the user to input a string, and then outputs a file with said string.

FILE *fptr;

void createFile(const char *inputString) {
    fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fptr, "%s\n", inputString);
    fclose(fptr);
}
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