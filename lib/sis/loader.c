#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "../logger/logger.h"

void load_data(student_t **students, int *n, char *file1, char *file2) {
    int num_students = 0;
    student_t *data = *students = malloc(10*sizeof(student_t));

    FILE *f1 = fopen(file1, "r");

    while (!feof(f1)) {
        student_t student;
        fscanf(f1, "%d %s %s %s %s %s", &student.id, student.name, student.last_name, student.major, student.city, student.grad_date);
        ilog(DEBUG, "[*] Loaded %d %s %s\n", student.id, student.name, student.last_name);
        *(data + num_students) = student;
        num_students++;
    }

    fclose(f1);

    int num_grades = 0;
    FILE *f2 = fopen(file2, "r");

    while (!feof(f2)) {
        int id;
        fscanf(f2, "%d", &id);
        grade_t *grades;

        // could be improved by implementing a hash map
        for (int i = 0; i < num_students; i++) {
            if ((data + i)->id == id) {
                grades = &((data + i)->grade);
                break;
            }
        }

        if (!grades) {
            fprintf(stderr, "Could not find student with id %d\n", id);
            free(data);
            exit(1);
        }

        fscanf(f2, "%d %d %d %d", &grades->grade1, &grades->grade2, &grades->grade3, &grades->grade4);
        ilog(DEBUG, "[*] Loaded grades for student %d\n", id);
        num_grades++;
    }

    if (num_students != num_grades) {
        fprintf(stderr, "Grade and student size mismatch! Got %d students and %d grades\n", num_students, num_grades);
        free(data);
        exit(1);
    }

    fclose(f2);
}