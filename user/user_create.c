#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "user_create.h"
#include "system.h"

void user_create() {
	char username[MAX_LENGTH] = "";
	char password[MAX_LENGTH] = "";
	char given_name[MAX_LENGTH] = "";
	char surname[MAX_LENGTH] = "";
	//char full_name[MAX_LENGTH * 2 + 1] = "";
	char initials[MAX_LENGTH] = "";
	_Bool must_change_at_next_login = true;

	char command[MAX_LENGTH * 8];

	char output[MAX_OUTPUT];

	clear_stdin();

	printf("Введите имя пользователя (настоящее имя человека, не логин!): [] ");
	fgets(given_name, MAX_LENGTH, stdin);
	given_name[strcspn(given_name, "\n")] = 0;
	//clear_stdin();

	printf("Введите фамилию пользователя: [] ");
	fgets(surname, MAX_LENGTH, stdin);
	surname[strcspn(surname, "\n")] = 0;
	//clear_stdin();

	printf("Введите инициалы пользователя: [] ");
	fgets(initials, MAX_LENGTH, stdin);
	initials[strcspn(initials, "\n")] = 0;
	//clear_stdin();

	printf("Пользователь должен сменить пароль? [Y/n] ");
	must_change_at_next_login = get_yes_no_answer();

	printf("Введите имя для входа (логин): ");
	fgets(username, MAX_LENGTH, stdin);
	username[strcspn(username, "\n")] = 0;
	//clear_stdin();

	printf("Введите пароль пользователя: ");
	fgets(password, MAX_LENGTH, stdin);
	password[strcspn(password, "\n")] = 0;
	//clear_stdin();


	snprintf(command, sizeof(command),
			"samba-tool user create '%s' '%s' %s%s%s%s%s%s%s%s%s%s2>&1",
			username, password,
			(strlen(given_name) > 0) ? "--given-name='" : "", given_name, (strlen(given_name) > 0) ? "' " : "",
			(strlen(surname) > 0) ? "--surname='" : "", surname, (strlen(surname) > 0) ? "' " : "",
			(strlen(initials) > 0) ? "--initials='" : "", initials, (strlen(initials) > 0) ? "' " : "",
			must_change_at_next_login ? "--must-change-at-next-login " : "");

	printf("  > %s\n", command);

	FILE *fp = popen(command, "r");
	if (fp == NULL) {
		fprintf(stderr, "Ошибка при выполнении команды.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(output, sizeof(output), fp) != NULL) {
		printf("%s", output);
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
