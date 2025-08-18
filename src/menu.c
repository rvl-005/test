#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "utils.h"

MODE mode = MENU;

int menu() {
    MODE mode = MENU;
    bool isRunning = true;
    printf("WELCOME TO DIARY!\n");
    do {
        printf("Please select an item on the menu.\n");
        printf("1. Create a new file\n");
        printf("2. Append to an existing file\n");
        printf("3. Read an existing file\n");
        printf("4. Exit\n");
        printf("Enter your choice: \n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer
        switch (choice) {
            case 1:
                mode = CREATE;
                printf("Entering creating mode...\n");
                createFile("page.txt");
                break;
            case 2:
                mode = APPEND;
                printf("Entering appending mode...\n");
                appendToFile("page.txt");
                break;
            case 3:
                mode = READ;
                printf("Entering reading mode...\n");
                readFile("page.txt");
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                mode = MENU;
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (isRunning);
}