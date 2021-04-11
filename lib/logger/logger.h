#ifndef _LOGGER_H
#define _LOGGER_H 1
#include <stdio.h>

#define VERBOSE_OFF 0
#define VERBOSE_ON 1

#define NORMAL 0x0001
#define DEBUG 0x0002

void set_verbose(const unsigned short _verbose);
void file_output(FILE *file);
void ilog(const int level, const char *format, ...);
void flog(const int level, const char *format, ...);

#endif