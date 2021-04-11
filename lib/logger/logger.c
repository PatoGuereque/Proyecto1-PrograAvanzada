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

void ilog(const int level, const char *format, ...) {
    if(level & NORMAL || (verbose && level & DEBUG)) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}

void flog(const int level, const char *format, ...) {
    if(level & NORMAL || (verbose && level & DEBUG)) {
        va_list args;
        if (file_out) {
            va_start(args, format);
            vfprintf(file_out, format, args);
            va_end(args);
        }
        
        if ((level & FILE_ONLY) == 0) {
            va_start(args, format);
            vprintf(format, args);
            va_end(args);   
        }
    }
}