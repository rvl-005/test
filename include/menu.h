#ifndef MENU_H
#define MENU_H
typedef enum {
    MENU = 0,
    CREATE,
    APPEND,
    READ
} MODE;
int menu();
#endif