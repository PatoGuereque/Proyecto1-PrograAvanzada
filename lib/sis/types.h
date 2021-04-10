#ifndef _SIS_TYPES_H
#define _SIS_TYPES_H

typedef struct {

    int student_id;
    int grade1;
    int grade2;
    int grade3;
    int grade4;

} grade_t;

typedef struct {
    
    int id;
    char *name;
    char *major;
    char *city;
    char *grad_date;
    grade_t grade;

} student_t;

#endif