#include <stdlib.h>
#include <stdio.h>
#include "types.h"

void ilog_header(const int level) {
    ilog(level, "id   Nombre               Carrera Ciudad Origen        Est. Grad.   A   B   C   D\n");
}

void ilog_student(const int level, const student_t *student) {
    ilog(
        level,
        "%-4d %-20s %-7s %-20s %-12s %-3d %-3d %-3d %-3d\n", 
        student->id, 
        student->name, 
        student->major, 
        student->city, 
        student->grad_date, 
        student->grade.grade1, 
        student->grade.grade2, 
        student->grade.grade3, 
        student->grade.grade4
    );
}

void flog_student(const int level,const student_t *student) {
    flog(
        level,
        "%-4d %-20s %-7s %-20s %-12s %-3d %-3d %-3d %-3d\n", 
        student->id, 
        student->name, 
        student->major, 
        student->city, 
        student->grad_date, 
        student->grade.grade1, 
        student->grade.grade2, 
        student->grade.grade3, 
        student->grade.grade4
    );
}