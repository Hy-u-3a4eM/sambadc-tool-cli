#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>

#include "system.h"

void fatal(const char *restrict file, int line, const char *restrict func, const char *restrict fmt, ...) {
	va_list args;
	va_start(args, fmt);

	fprintf(stderr, "%s:%d: fatal error: ", file, line);
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\nin function `%s`", func);
	fprintf(stderr, "\n");

	va_end(args);

	exit(EXIT_FAILURE);
}

_Bool get_yes_no_answer() {
	int ch = tolower(getchar());
	if (ch == 'y' || ch == '\n')
		return true;
	else
		return false;
}
