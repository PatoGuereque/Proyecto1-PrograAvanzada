#include <stdarg.h>
#include <stdio.h>
#include "logger.h"

unsigned short verbose = 0;
FILE *file_out;

void set_verbose(const unsigned short _verbose) {
    verbose = _verbose;
}

void file_output(FILE *file) {
    file_out = file;
}

void ilog(int level, const char *format, ...) {
    if(level & NORMAL || (verbose && level & DEBUG)) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

void flog(int level, const char *format, ...) {
    if(level & NORMAL || (verbose && level & DEBUG)) {
        va_list args;
        if (file_out) {
            va_start(args, format);
            vfprintf(file_out, format, args);
            va_end(args);
        }
        
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}