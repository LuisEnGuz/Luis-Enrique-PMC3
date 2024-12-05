#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Alumno {
    char nombre[50];
    float promedio;
    char carrera[50];
};

int nuevoarchivo(char* ar);
int abrirarchivo(char* ar);
int guardararchivo(char* ar);
int buscarenarchivo(char* ar);

int main() {
    char* ar = "alumnos.dat";
    int i;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Nuevo Archivo\n");
        printf("2. Abrir Archivo\n");
        printf("3. Guardar Registro\n");
        printf("4. Buscar en Archivo\n");
        printf("5. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%i", &i);

        switch (i) {
            case 1:
                nuevoarchivo(ar);
                break;
            case 2:
                abrirarchivo(ar);
                break;
            case 3:
                guardararchivo(ar);
                break;
            case 4:
                buscarenarchivo(ar);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                break;
        }
    } while (i != 5);

    return 0;
}

int nuevoarchivo(char* ar) {
    FILE* ap = fopen(ar, "wb");
    if (ap != NULL) {
        printf("Archivo creado exitosamente: %s\n", ar);
        fclose(ap); 
    } else {
        printf("Error al crear archivo: %s\n", ar);
    }
    return 0;
}

int guardararchivo(char* ar) {
    FILE* ap = fopen(ar, "ab");
    if (ap == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para guardar.\n", ar);
        return 1;
    }

    struct Alumno alumno;
    printf("Introduce el nombre del alumno: ");
    getchar(); // hace lo mismo que el fflush
    fgets(alumno.nombre, sizeof(alumno.nombre), stdin);
    alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0'; 

    printf("Introduce el promedio: ");
    scanf("%f", &alumno.promedio);
    getchar(); 
    printf("Introduce la carrera: ");
    fgets(alumno.carrera, sizeof(alumno.carrera), stdin);
    alumno.carrera[strcspn(alumno.carrera, "\n")] = '\0';

    fwrite(&alumno, sizeof(struct Alumno), 1, ap);
    printf("Registro guardado exitosamente.\n");

    fclose(ap);
    return 0;
}

int abrirarchivo(char* ar) {
    FILE* archivo = fopen(ar, "rb");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para lectura.\n", ar);
        return 1;
    }

    struct Alumno alumno;
    printf("Contenido del archivo:\n");
    while (fread(&alumno, sizeof(struct Alumno), 1, archivo) == 1) {
        printf("Nombre: %s\n", alumno.nombre);
        printf("Promedio: %.2f\n", alumno.promedio);
        printf("Carrera: %s\n", alumno.carrera);
        printf("--------------------------\n");
    }

    fclose(archivo);
    return 0;
}

int buscarenarchivo(char* ar) {
    FILE* archivo = fopen(ar, "rb");
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para lectura.\n", ar);
        return 1;
    }

    char nombreBuscado[50];
    printf("Introduce el nombre a buscar: ");
    getchar(); 
    fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    struct Alumno alumno;
    bool encontrado = false;// esta la busque en un video y vi que el bool es com un verdadero o falso

    while (fread(&alumno, sizeof(struct Alumno), 1, archivo) == 1) {
        if (strcmp(alumno.nombre, nombreBuscado) == 0) {
            printf("Alumno encontrado:\n");
            printf("Nombre: %s\n", alumno.nombre);
            printf("Promedio: %.2f\n", alumno.promedio);
            printf("Carrera: %s\n", alumno.carrera);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un alumno con el nombre: %s\n", nombreBuscado);
    }

    fclose(archivo);
    return 0;
}

