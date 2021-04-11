#include "sis.h"

void print_students(student_t *students, int n) {
    ilog_header(NORMAL);
    
    for (int i = 0; i < n; i++) {
        ilog_student(NORMAL, students+i);
    }
}