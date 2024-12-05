#include <stdio.h>
#include <stdlib.h>//se abre librerias
#include <string.h>
#include <stdbool.h>//esta libreria permite el uso del comando bool que se define mas adelante 

struct Alumno {
    char nombre[50];//declara la estructura alumno con las indicaciones del mandato, que se utilizara para los archivos
    float promedio;
    char carrera[50];
};

int nuevoarchivo(char* ar);//funcion que crea el archivo
int abrirarchivo(char* ar);//funcion que abre archivo
int guardararchivo(char* ar);//funcion que guardar archivo
int buscarenarchivo(char* ar);//funcion abrir archivo

int main() {
    char* ar = "alumnos.dat";//se nombra el archivo y se declara una variable que permitira el uso del while
    int i;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Nuevo Archivo\n");
        printf("2. Abrir Archivo\n");
        printf("3. Guardar Registro\n");
        printf("4. Buscar en Archivo\n");
        printf("5. Salir\n");
        printf("Selecciona una opcion: ");//se presentan las opciones del menu y se indidca como llamarlas
        scanf("%i", &i);

        switch (i) {//el switch funciona como el menu y dependiendo de la opcion selecionada llama a a la funcion correspondiente
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
    } while (i != 5);// el do while  repetira el menu cada vez que la opcion no sea 5, si es 5 funciona la opcion salir y se cierra el bucle cerrando el programa

    return 0;//indica q termina el programa
}

int nuevoarchivo(char* ar) //como se menciono previamente esta funcion crea un nuevo archivo y devuelve ar que es la variable que recive el nombre del archivo
{
    FILE* ap = fopen(ar, "wb");//se crea archivo de escritura que sobrescribe sobre cualquier archivo existente con la variable ar
    if (ap != NULL) {
        printf("Archivo creado exitosamente: %s\n", ar);//se indica que se crea el archivo en caso de que if no sea nulo de lo contrario significa que no hay archivo y se indica
        fclose(ap); 
    } else {
        printf("Error al crear archivo: %s\n", ar);
    }
    return 0;
}

int guardararchivo(char* ar)  //como se menciono previamente esta funcion guarda un archivo y devuelve ar que es la variable que recive el nombre del archivo
{
    FILE* ap = fopen(ar, "ab");//se abre un archivo de adiccion binaria q permite agregar al archivo previo sin sobreescribir lo que staba previamente, y al ser binario lo imprime tal como se codifico
    if (ap == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para guardar.\n", ar);/* yo busque como hacer esta funcion por internet y se usa fprintf porque permite dirigir la salido por el directorio stdder,
		 espcifcamente utilizado para expresar errores*/
        return 1;//return 0 indica que no error, por lo tanto return numero indica que hay error en este caso puede ser que el archivo ya exista....
    }

    struct Alumno alumno;//se declara una variable alumno de la estructura alumno que se utilizara para pedir los datos de la estructura
    printf("Introduce el nombre del alumno: ");
    getchar(); // hace lo mismo que el fflush
    fgets(alumno.nombre, sizeof(alumno.nombre), stdin);//lee el nombre del alumno se usa fgets ya que contraio a gets limita lo que solicita, pero incluye un salto al final 
    alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0'; //elimina el salto

    printf("Introduce el promedio: ");
    scanf("%f", &alumno.promedio);//lee el promedio
    getchar(); 
    printf("Introduce la carrera: ");
    fgets(alumno.carrera, sizeof(alumno.carrera), stdin);//lee la carrera
    alumno.carrera[strcspn(alumno.carrera, "\n")] = '\0';

    fwrite(&alumno, sizeof(struct Alumno), 1, ap);//escribe  los datos de la estructura en el arhivo
    printf("Registro guardado exitosamente.\n");// se indica que se guardo

    fclose(ap);//se cierra el archivo
    return 0;
}

int abrirarchivo(char* ar) //como se menciono previamente esta funcion abre un archivo y devuelve ar que es la variable que recive el nombre del archivo
{
    FILE* archivo = fopen(ar, "rb");//se abre un archivo el archivo de lectura binaria
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para lectura.\n", ar);// se verifica el archivo y notifica si no funciona
        return 1;
    }

    struct Alumno alumno;//se cra una variable alumno que solicita las informaciones de la estructura
    printf("Contenido del archivo:\n");
    while (fread(&alumno, sizeof(struct Alumno), 1, archivo) == 1)//se abre un bucle el cual presenta las informaciones solicitadas siempre y cuando haya un archivo q las presente
	{
        printf("Nombre: %s\n", alumno.nombre);
        printf("Promedio: %.2f\n", alumno.promedio);
        printf("Carrera: %s\n", alumno.carrera);
        printf("--------------------------\n");
    }

    fclose(archivo);//cierra el archivo
    return 0;
}

int buscarenarchivo(char* ar) //como se menciono previamente esta funcion busca en el archivo y devuelve ar que es la variable que recive el nombre del archivo
{
    FILE* archivo = fopen(ar, "rb");// abre y verifica archivo de lectura binario
    if (archivo == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s para lectura.\n", ar);
        return 1;
    }

    char nombreBuscado[50];// en caso de que si abra el archivo crea una variable para buscar de cadena de caracter para buscar el nombre
    printf("Introduce el nombre a buscar: ");
    getchar(); 
    fgets(nombreBuscado, sizeof(nombreBuscado), stdin);//se solicita el nombre a buscar
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    struct Alumno alumno;
    bool encontrado = false;// esta la busque en un video y vi que el bool es como un verdadero o falso, o sea junto con el while esta define si el nombre ingresado esta en el archivo

    while (fread(&alumno, sizeof(struct Alumno), 1, archivo) == 1)//mientras haya un archivo
	 {
        if (strcmp(alumno.nombre, nombreBuscado) == 0)// strcmp compara el nombre buscado con el archivo si este se encuentra el bucle proseguir de lo contrario ocurre lo siguiente
		 {
            printf("Alumno encontrado:\n");
            printf("Nombre: %s\n", alumno.nombre);
            printf("Promedio: %.2f\n", alumno.promedio);
            printf("Carrera: %s\n", alumno.carrera);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) //bool define a encntrado como falso si crmp lo encuentra pues es verdadero de lo contrario sigue siendo falso y por lo tanto el nombre se encontro.
	{
        printf("No se encontró un alumno con el nombre: %s\n", nombreBuscado);
    }

    fclose(archivo);//cierra el archivo
    return 0;
}

