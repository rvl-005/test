// gcc src/main.c -o bin/main.exe
#include <stdio.h>
#include <string.h>
// This program prompts the user to input a string, and then outputs a file with said string.

FILE *fptr;
char inputString[];

void addString() {
    // Prompts user for input
    printf("Enter something!: \n");
    // processes input
    scanf("%s", inputString);
}
void createFile() {
    // Opens file for writing
    fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    // Writes input string to file
    fprintf(fptr, "%s\n", inputString);
    // Closes the file
    fclose(fptr);
}
int main() {
    addString();
    createFile();
    printf("String written to file successfully.\n");
    return 0;
}