#include <stdio.h>

#define VERSION_MAJOR		0
#define VERSION_MINOR		1
#define VERSION_MICRO		0
#define VERSION_RELEASELEVEL	("final")
#define VERSION_SERIAL		0

const char Version[] = sprintf("%d.%d.%d", VERSION_MAJOR, VERSION_MINOR, VERSION_MICRO);
