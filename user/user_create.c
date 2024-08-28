#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_create.h"
#include "system.h"

void user_create() {
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
	char given_name[MAX_LENGTH];
	char surname[MAX_LENGTH];
	//char full_name[MAX_LENGTH * 2 + 1];
	char initials[MAX_LENGTH];
	_Bool must_change_at_next_login = true;

	char command[MAX_LENGTH * 8];

	char output[MAX_OUTPUT];


	printf("Введите имя для входа: ");
	fgets(username, MAX_LENGTH, stdin);
	username[strcspn(username, "\n")] = 0;

	printf("Введите пароль пользователя: ");
	fgets(password, MAX_LENGTH, stdin);
	password[strcspn(password, "\n")] = 0;

	printf("Введите имя пользователя (настоящее имя человека): ");
	fgets(given_name, MAX_LENGTH, stdin);
	given_name[strcspn(given_name, "\n")] = 0;

	printf("Введите фамилию пользователя: ");
	fgets(surname, MAX_LENGTH, stdin);
	surname[strcspn(surname, "\n")] = 0;

	printf("Введите инициалы пользователя: ");
	fgets(surname, MAX_LENGTH, stdin);
	surname[strcspn(surname, "\n")] = 0;

	printf("Пользователь должен сменить пароль? [Y/n] ");
	must_change_at_next_login = get_yes_no_answer();


	snprintf(command, sizeof(command),
			"samba-tool user create '%s' '%s' --given-name='%s' --surname='%s' --initials='%s' %s 2>&1",
			username, password, given_name, surname, initials,
			must_change_at_next_login ? "--must-change-at-next-login" : "");

	FILE *fp = popen(command, "r");
	if (fp == NULL) {
		FATAL("Ошибка при выполнении команды.\n");
	}

	while (fgets(output, sizeof(output), fp) != NULL) {
		printf("%s\n", output);
	}

	int status = pclose(fp);

	if (WIFEXITED(status)) {
		int exit_status = WEXITSTATUS(status);
		if (exit_status == 0) {
			printf("Пользователь успешно создан.\n");
			if (must_change_at_next_login) {
				printf("Пользователю будет предложено сменить пароль при первом входе.\n");
			}
		} else {
			printf("Ошибка при создании пользователя. Код возврата: %d\n", exit_status);
		}
	} else {
		printf("Команда завершилась некорректно.\n");
	}
}
