# Proyecto #1

## Instrucciones:
* Crea un repositorio privado (GitHub) para tu proyecto, realiza commits/push constantemente, es importante ver el historial de como fuiste avanzando en tu proyecto
* Comparte el link a tu repositorio al usuario @LuisAndresCastilloH
* Graba un video donde expliques tu procedimiento y resultado de tu programa.
* Sube a Canvas en la sección Proyectos (en la liga Proyecto1) los archivos.c, .h, Makefiles y el link a tu video.
  * NO SUBIR comprimidos (tar, zip, etc)

---

Debes crear una aplicación para tener registro de los estudiantes inscritos en el presente ciclo escolar. La información se encuentra en dos archivos: archivo1, archivo2
- Debes pasar los nombres de los archivos como argumentos a tu aplicación (ej.: ./app arch.txt arch2.txt)
o Los nombres de los archivos se deben leer de los argumentos.
- Debes pasar toda la información de los estudiantes a memoria dinámica. Cuida de usar lo mínimo de memoria en tu programa. Se evaluará tu diseño de solución para usar el mínimo de memoria.
o Se recomienda usar structs
- Tu programa debe poder interpretar queries estructurados para dar respuesta a las siguientes consultas. La implementación de estos queries debe estar en una función o funciones que posteriormente serán compiladas y ligadas a tu aplicación como bibliotecas dinámicas.
- Listado que queries
  * “Kardex <estudiante_id>”
  * “Fecha_estimada_graduacion <estudiante_id>”
  * “Numero_alumnos <nombre_carrera> <ciudad_origen>”
  * “Numero_alumnos <nombre_carrera>”
  * “Numero_alumnos *”
  * “Nombre_alumnos <operador> <numero>”: Debe regresar la lista de alumnos cuyo promedio cumpla con la condición. Operador: <, >, ==, !=

- Si el usuario ingresa un query invalido debes infórmale
- Tu programa debe tener una opción para mostrar toda la información de todos los estudiantes
- Tu programa debe tener un menú con las posibles opciones a ejecutar
  * ej.: 1. Mostrar estudiantes, 2. Hacer consulta, …
- Tu aplicación debe tener la opción de mostrar ayuda (-h), la opción de verbose (-v) que muestra cómo se van ejecutando distintas partes de tu programa y la opción de escribir a archivo (-o <nombre_archivo>) que consiste en escribir los queries y respuestas consultadas al archivo provisto
  * Estas opciones se usan al momento de ejecutar tu aplicación
- Realiza un Makefile o varios si es necesario.
- Haz una estructuración de tu proyecto (diferentes carpetas, etc.)
- Ejemplos de ejecución de tu aplicación:
  * ./app archivo_1.txt archivo_2.txt
  * ./app archivo_1.txt test.txt -h
    * Si la opción -h es provista, lo único que debe hacer es mostrar la ayuda
  * ./app archivo_1.txt, hola.txt adios.txt -v -o salida.txt


## Estructura de archivos:

----

### Archivo 1

|Id_alumno | nombre_alumno | Carrera | Ciudad origen | Fecha estimada graduacion|
| --- | --- | --- | --- | --- |
| 123 | Abril Sanchez | ITC | Mty | 26/05/20221|
| 456 | Genaro Luna | ISD | Saltillo | 11/10/2026 |
| 912 | Enrique Lopez | LIN | Torreon | 26/05/2022 |
| 987 | Juan Hernandez | LAF | CDMX | 26/05/2022 |
| 431 | Ana alvarez | IMT | Guadalajara | 1/05/2025 |
| 908 | Jose Garza | IIS | Veracruz | 26/05/2024 |
| 176 | Carolina Sada | IDS | Cancun | 11/12/2021 |
| 901 | Gabriel Castro | IMD | Merida | 26/05/2023 |

<details>
  <summary>Archivo1.txt</summary>

  ```txt
Id_alumno 	nombre_alumno 	Carrera 	Ciudad origen 	Fecha estimada graduacion 
123 	Abril Sanchez 	ITC 	Mty 	26/05/2022 
456 	Genaro Luna 	ISD 	Saltillo 	11/10/2026 
912 	Enrique Lopez 	LIN 	Torreon 	26/05/2022 
987 	Juan Hernandez 	LAF 	CDMX 	26/05/2022 
431 	Ana alvarez 	IMT 	Guadalajara 	1/05/2025 
908 	Jose Garza 	IIS 	Veracruz 	26/05/2024 
176 	Carolina Sada 	IDS 	Cancun 	11/12/2021 
901 	Gabriel Castro 	IMD 	Merida 	26/05/2023 
  ```
  
</details>

### Archivo 2

| id_alumno | materia A | materia B | materia C | materia D |
| --- | --- | --- | --- | --- |
| 431 | 90 | 100 | 85 | 70 |
| 456 | 95 | 87 | 91 | 89 |
| 176 | 91 | 76 | 97 | 71 |
| 901 | 97 | 99 | 96 | 60 |
| 123 | 96 | 89 | 89 | 100 |
| 908 | 89 | 77 | 87 | 100 |
| 912 | 71 | 99 | 76 | 90 |
| 987 | 60 | 100 | 99 | 90 |

<details>
  <summary>Archivo2.txt</summary>

  ```txt
id_alumno 	materia A 	materia B 	materia C 	materia D 
431 	90 	100 	85 	70 
456 	95 	87 	91 	89 
176 	91 	76 	97 	71 
901 	97 	99 	96 	60 
123 	96 	89 	89 	100 
908 	89 	77 	87 	100 
912 	71 	99 	76 	90 
987 	60 	100 	99 	90 
  ```
  
</details>


**IMPORTANTE**: No se sabe el número de alumnos (la cantidad de líneas de los archivos es desconocida)