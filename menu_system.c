#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "system.h"
#include "user/user_create.h"

typedef void (*MenuFunction)(int *stack, int *top);

void push(int *stack, int *top, int value) {
	if (*top >= MAX_MENUS - 1)
		FATAL("Ошибка: Стек переполнен! Превышена максимальная глубина меню.\n");
	else
		stack[++(*top)] = value;
}

void pop(int *stack, int *top) {
	if (*top < 0)
		FATAL("Ошибка: Пустой стэк! Нет предыдущего меню.\n");
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
		createUser(stack, top);
	} else if (strcmp(choice, "back") == 0) {
		back(stack, top);
	} else if (strcmp(choice, "home") == 0) {
		mainMenu(stack, top);
	} else if (strcmp(choice, "exit") == 0) {
		exit(EXIT_SUCCESS);
	} else {
		printf("Такой подкоманды не существует. Попробуйте ещё раз.\n");
		userMenu();
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
		mainMenu();
	}
}















































































	if (argc != 1)
		usage(EXIT_FAILURE, argv[0]);

	char command[16];

	while (1) {
		printf("\nВыберите подкоманду:\n\
				\tcreate\t\t- Добавить нового пользователя.\n\
				\tback");	// TODO: доделать

		scanf("%15s", command);

		//if (strcmp(command, "create") == 0)
			//create();
	}
