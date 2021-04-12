#include <stdlib.h>
#include <string.h>
#include "sis.h"

void print_students(student_t *students, int n) {
    ilog_header(NORMAL);
    
    for (int i = 0; i < n; i++) {
        ilog_student(NORMAL, students+i);
    }
}


int match_any(student_t *student, void *major, void *city) {
    return 1;
}

int match_operator(student_t *student, void *operator, void *n) {
    char op = *((char*)operator);

    if (op == '>') {
        return student->grade.average > *((int*)n);
    } else if (op == '<') {
        return student->grade.average < *((int*)n);
    } else if (op == '=') {
        return student->grade.average == *((int*)n);
    } else if (op == '!') {
        return student->grade.average != *((int*)n);
    } else {
        return 0;
    }
}

int match_major_city(student_t *student, void *major, void *city) {
    if (strcasecmp(student->major, (char*) major) != 0) {
        return 0;
    }

    return city == NULL || strcasecmp(student->city, (char*) city) == 0;
}

void handle_query(student_t *students, int n, char *query_type) {
    char *buf = malloc(80 * sizeof(char));
    fgets(buf, 80, stdin);
    flog((NORMAL | FILE_ONLY), "Query: %s%s", query_type, buf);

    int (*filter)(student_t*, void*, void*) = NULL;
    void *p1 = NULL;
    void *p2 = NULL;

    char *arg1 = malloc(10 * sizeof(char));
    char *arg2 = NULL;
    int bytes_read = 0;
    sscanf(buf, "%s%n", arg1, &bytes_read);
    ilog(DEBUG, "[*] First query param: '%s'\n", arg1);

    if (*arg1 == '*') {
        filter = &match_any;
    } else if (strcmp(arg1, ">") == 0 || strcmp(arg1, "<") == 0 || strcmp(arg1, "!=") == 0 || strcmp(arg1, "==") == 0) {
        int n = 0;
        sscanf(buf + bytes_read, "%d", &n);
        p1 = arg1;
        p2 = &n;
        filter = match_operator;
        ilog(DEBUG, "[*] Second query param: '%d'\n", n);
    } else {
        p1 = arg1;
        arg2 = malloc(20 * sizeof(char));

        if (sscanf(buf + bytes_read, "%s", arg2) <= 0) {
            free(arg2);
            arg2 = NULL;
        } else {
            p2 = arg2;
        }
        filter = match_major_city;
        ilog(DEBUG, "[*] Second query param: '%s'\n", arg2);
    }

    student_t *curr = students;
    int print_names = strcasecmp(query_type, "Nombre_alumnos") == 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((*filter)(curr, p1, p2)) {
            count++;

            if (print_names) {
                flog(NORMAL, "%s\n", curr->name);
            }
        }
        curr++;
    }

    if (!print_names) {
        flog(NORMAL, "Encontrados: %d\n\n", count);
    } else {
        if (!count) {
            flog(NORMAL, "n/a\n");
        } else {
            flog(NORMAL, "\n");
        }
    }

    free(buf);
    free(arg1);

    if (arg2) {
        free(arg2);
    }
}

void handle_query_input(student_t *students, int n) {
    char *query_type = malloc(26 * sizeof(char));
    ilog(NORMAL, "Ingrese el query\n> ");
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
        handle_query(students, n, query_type);
    } else {
        ilog(NORMAL, "Query inválido\n");
    }

    free(query_type);
}