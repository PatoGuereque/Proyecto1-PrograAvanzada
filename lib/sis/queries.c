#include <stdlib.h>
#include <string.h>
#include "sis.h"

void print_students(student_t *students, int n) {
    ilog_header(NORMAL);
    
    for (int i = 0; i < n; i++) {
        ilog_student(NORMAL, students+i);
    }
}

void handle_query_input(student_t *students, int n) {
    char *query_type = malloc(26 * sizeof(char));
    scanf("%25s", query_type);

    if (strcasecmp(query_type, "Kardex") == 0 || strcasecmp(query_type, "Fecha_estimada_graduacion") == 0) {
        flog((NORMAL | FILE_ONLY), "Query: %s ", query_type);
        student_t *student = get_student_stdin(students, n);

        if (student) {
            if (*query_type == 'K' || *query_type == 'k') {
                flog(NORMAL, "Kardex de %s\n", student->name);
                flog(NORMAL, "Materia A: %d\n", student->grade.grade1);
                flog(NORMAL, "Materia B: %d\n", student->grade.grade2);
                flog(NORMAL, "Materia C: %d\n", student->grade.grade3);
                flog(NORMAL, "Materia D: %d\n", student->grade.grade4);
                flog(NORMAL, "Promedio: %.2f\n\n", student->grade.average);
            } else {
                flog(NORMAL, "Fecha estimada de graduación de %s: %s\n\n", student->name, student->grad_date);
            }
        }
    } else if (strcasecmp(query_type, "Numero_alumnos") == 0 || strcasecmp(query_type, "Nombre_alumnos") == 0) {

    } else {
        ilog(NORMAL, "Query inválido\n");
    }

    free(query_type);
}