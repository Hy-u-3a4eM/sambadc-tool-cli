#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#define MAX_MENUS 2

typedef void (*MenuFunction)(int *, int *);

int stack[MAX_MENUS];
int top = -1;

void push(int *, int *, int);

void pop(int *, int *);

void userMenu(int *, int *);

void mainMenu(int *, int *);

#endif // MENU_SYSTEM_H
