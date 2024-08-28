#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>

void fatal(const char *restrict, int line, const char *restrict, const char *restrict, ...);

#define FATAL(fmt, ...) fatal(__FILE__, __LINE__, __func__, fmt, __VA_ARGS__)

_Bool get_yes_no_answer();

#endif // SYSTEM_H
