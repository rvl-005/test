#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "utils.h"

MODE mode = MENU;

int menu() {
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
                isRunning = false;
                return 0;
            default:
                mode = MENU;
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (isRunning);
}

int pauseScreen(char *filename) {
    printf("Do you want to \n 1. return to the menu? \n 2. go back to writing?\n or 3. exit the program?:\n ");
    int response;
    scanf("%d", &response);
    getchar(); // Clear the newline character from the input buffer
    switch (response) {
        case 1:
            mode = MENU;
            menu();
            return 0;
            break;
        case 2:
            MODE previousMode = mode;
            switch (previousMode) {
                case CREATE:
                    createFile();
                    break;
                case APPEND:
                    appendToFile();
                    break;
                case READ:
                    readFile();
                    break;
                default:
                    printf("Unknown mode. Returning to menu.\n");
                    menu();
                    break;
            }
            break;
        case 3:
            printf("Exiting the program.\n");
            return 0;
    }
}