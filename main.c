#include <stdio.h>
#include <stdlib.h>

#include "version.h"

#define PROGRAM_NAME ("sambadc-tool-cli")
#define PACKAGE_NAME ("sambadc-tool-cli")

void usage(int status) {
	printf("\
			Использование: %s\n\
			");

	//if (status != EXIT_SUCCESS)
	//	return status;
	return status;
}

const char version_etc_copyright[] = "Copyright";

void version_etc(FILE *stream,
             const char *command_name, const char *package,
             const char *version) {
	if (command_name)
		fprintf (stream, "%s (%s) %s\n", command_name, package, version);
	else
		fprintf (stream, "%s %s\n", package, version);

	fprintf (stream, version_etc_copyright, _("(C)"), COPYRIGHT_YEAR);

	fputs ("\n", stream);
}

int main() {
	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0)
			usage(EXIT_SUCCESS);
		if (strcmp(argv[1], "--version" == 0)
			version_etc(stdout, PROGRAM_NAME, PACKAGE_NAME, Version);
	}
	if (argc != 1)
		usage(EXIT_FAILURE);

	char command[16];

	while (1) {
		printf("\nВыберите подкоманду:\n");
		printf("\tcreate\t\t- Добавить нового пользователя.\n"

	// TODO: имя, фамилия, полное имя, инициалы, имя для входа (uppo.int), имя для входа (до винды 2000), пароль, подтвердите пароль
	// TODO: пользователь должен сменить пароль при следующем входе в систему, пользователь не может изменить пароль, пароль не истекает, учетная запись отключена
}
