#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/logger/logger.h"
#include "../lib/sis/sis.h"

int main(int argc, char **argv) {
    char *out_file_name = NULL;
    int c;
    opterr = 0;

    while ((c = getopt(argc, argv, "hvo:")) != -1) {
        if (c == 'h') {
            printf("Uso: %s [BANDERAS...] <archivo1> <archivo2>\n", *argv);
            printf("Proyecto 1: Carga tablas de calificaciones y estudiantes para consultar de\n");
            printf("manera agrupada la información.\n");
            printf("\n");
            printf("Argumentos del programa:\n");
            printf("\n");
            printf("  <archivo1>     El archivo de los estudiantes\n");
            printf("  <archivo2>     El archivo de las calificaciones de los estudiantes\n");
            printf("\n");
            printf("Banderas del programa:\n");
            printf("\n");
            printf("  -h             Muestra esta ayuda del programa\n");
            printf("  -v             Activa el modo verbose de la aplicación\n");
            printf("  -o <archivo>   Imprime los queries y los resultados de los queries en\n");
            printf("                 el archivo proporcionado\n");
            printf("\n");
            printf("Ejemplos:\n");
            printf("  app -h                           # Despliega la ayuda\n");
            printf("  app a1.txt a2.txt                # Utiliza los archivos a1, a2\n");
            printf("  app a1.txt a2.txt -v -o out.txt  # Utiliza los archivos a1 y a2, activa\n");
            printf("                                     el modo verbose y redirecciona la\n");
            printf("                                     salida al archivo dado\n");
            printf("\n");
            printf("La ejecucuón del programa no toma ninguna bandera activa por defecto.\n");
            return 0;
        }

        if (c == 'v') {
            set_verbose(VERBOSE_ON);
        } else if (c == 'o') {
            out_file_name = optarg;
        } else if (c == '?') {
            if (optopt == 'o') {
                fprintf(stderr, "Opción -%o requiere un argumento!.\n", optopt);;
            } else if (isprint(optopt)) {
                fprintf(stderr, "Opción desconocida `-%c'.\n", optopt);;
            } else {
                fprintf(stderr, "Caracter inválido `\\x%x'.\n", optopt);
            }
            return 1;
        } else {
            break;
        }
    }

    if (argc - optind != 2) {
        printf("Uso: %s [BANDERAS...] <archivo1> <archivo2>\n", *argv);
        printf("Para consultar la ayuda utiliza: %s -h\n", *argv);
        return 1;
    }

    // argv[optind] - archivo1
    // argv[optind + 1] - archivo2

    return 0;
}