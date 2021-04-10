#ifndef _LOGGER_H
#define _LOGGER_H

unsigned short VERBOSE_OFF = 0;
unsigned short VERBOSE_ON = 1;

unsigned short NORMAL = 0x0001;
unsigned short DEBUG = 0x0002;

void set_verbose(const unsigned short _verbose);
void file_output(FILE *file);
void ilog(int level, const char *format, ...);
void flog(int level, const char *format, ...);

#endif