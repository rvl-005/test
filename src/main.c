// gcc -Iinclude src/main.c src/error.c src/utils.c src/file.c src/menu.c -o bin/diary.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "menu.h"

int main() {
    menu();
}