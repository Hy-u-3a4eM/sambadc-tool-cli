#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu_system.h"
#include "system.h"
#include "user/user_create.h"

typedef void (*MenuFunction)(int *stack, int *top);

void push(int *stack, int *top, int value) {
	if (*top >= MAX_MENUS - 1) {
		fprintf(stderr, "Ошибка: Стек переполнен! Превышена максимальная глубина меню.\n");
		exit(EXIT_FAILURE);
	}
	else
		stack[++(*top)] = value;
}

int pop(int *stack, int *top) {
	if (*top < 0) {
		fprintf(stderr, "Ошибка: Пустой стэк! Нет предыдущего меню.\n");
		exit(EXIT_FAILURE);
	}
	else
		return stack[(*top)--];
}

void userMenu(int *stack, int *top) {
	char choice[16];

	printf("\n\
Выберите подкоманду:\n\
  create\t- Добавить нового пользователя.\n\n\
  back\t- Вернуться на предыдущее меню.\n\n\
  home\t- Вернуться на главное меню.\n\n\
  exit\t- Выйти из программы\n\n");

	scanf("%15s", choice);

	if (strcmp(choice, "create") == 0) {
		push(stack, top, 0);
		user_create();
	} else if (strcmp(choice, "back") == 0) {
		mainMenu(stack, top);
	} else if (strcmp(choice, "home") == 0) {
		mainMenu(stack, top);
	} else if (strcmp(choice, "exit") == 0) {
		exit(EXIT_SUCCESS);
	} else {
		printf("Такой подкоманды не существует. Попробуйте ещё раз.\n");
		userMenu(stack, top);
	}
}

void mainMenu(int *stack, int *top) {
	char choice[16];

	printf("\n\
Выберите подкоманду:\n\
  user\t- Управление пользователями.\n\n\
  exit\t- Выйти из программы\n\n");

	scanf("%15s", choice);

	if (strcmp(choice, "user") == 0) {
		push(stack, top, 0);
		userMenu(stack, top);
	} else if (strcmp(choice, "exit") == 0) {
		exit(EXIT_SUCCESS);
	} else {
		printf("Такой подкоманды не существует. Попробуйте ещё раз.\n");
		mainMenu(stack, top);
	}
}
