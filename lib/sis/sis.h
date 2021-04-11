#ifndef _SIS_H
#define _SIS_H 1

#include "types.h"

void load_data(student_t **data, int *n, char *file1, char *file2);
void print_students(student_t *students, int n);
void handle_query_input(student_t *students, int n);
student_t* get_student_stdin(student_t *students, int n);
void ilog_header(const int level);
void ilog_student(const int level, const student_t *student);
void flog_student(const int level,const student_t *student);

#endif