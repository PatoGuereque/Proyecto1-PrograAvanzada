#ifndef _SIS_TYPES_H
#define _SIS_TYPES_H 1
#include "../logger/logger.h"

typedef struct {

    int student_id;
    int grade1;
    int grade2;
    int grade3;
    int grade4;

} grade_t;

typedef struct {
    
    int id;
    char name[20];
    char major[4];
    char city[21];
    char grad_date[11];
    grade_t grade;

} student_t;

#endif