#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#define MAX_MENUS 2

typedef void (*MenuFunction)(int *, int *);

extern int stack[MAX_MENUS];
extern int top;

void push(int *, int *, int);

int pop(int *, int *);

void userMenu(int *, int *);

void mainMenu(int *, int *);

void runMainMenu();

#endif // MENU_SYSTEM_H
