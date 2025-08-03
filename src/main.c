// gcc -Iinclude src/main.c src/error.c src/utils.c -o bin/diary.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

// This program prompts the user to input a string, and then outputs a file with said string.
enum MODE {
    MENU = 0,
    CREATE = 1,
    APPEND = 2,
    READ = 3
};
int main() {
    enum MODE mode = MENU;
    bool isRunning = true;
    do {
        printf("WELCOME TO DIARY!\n");
        printf("Please select an item on the menu.\n");
        printf("1. Create a new file\n");
        printf("2. Append to an existing file\n");
        printf("3. Read an existing file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer
        switch (choice) {
            case 1:
                mode = CREATE;
                printf("Entering creating mode:");
                break;
            case 2:
                mode = APPEND;
                printf("Entering appending mode: ");
                break;
            case 3:
                mode = READ;
                printf("Entering reading mode: ");
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                mode = MENU;
                printf("Invalid choice. Please try again.\n");
                break;
        }
        return 0;
    } while (isRunning);
}