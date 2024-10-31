#include<stdio.h>
#include<string.h>

union datos
{
    char celular[15];
    char correo[20];
};

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
}alumno;

int lectura(alumno a);

int main()
{
    alumno a0, a1={120,"Maria", "contabilidad", 8.9, "5-158-40-50"}, a2, a3;
    printf("Alumno 2\n");
    printf("Ingrese la matricula del alumno 2:");
    scanf("%i", &a2.matricula);
    fflush(stdin);
    printf ("ingrese el nombre del alumno 2: ");
    gets(a2.nombre);
    fflush(stdin);
    printf ("ingrese la carrera del alumno 2: ");
    gets(a2.carrera);
    printf ("ingrese el promedio del alumno 2: ");
    scanf("%f", a2.promedio);
    fflush(stdin);
    printf ("ingrese el correo electronico de alumno2: ");
    gets(a2.personales.correo);

    printf("alumno 3\n");
    lectura(&a3);

    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);
    puts(a1.personales.correo);

    strcpy(a0.personales.correo, "hgimenez@hotmail.com");

    puts(a0.personales.celular);
    puts(a0.personales.correo);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a3.personales.celular);
    puts(a2.personales.correo);

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);
    puts(a3.personales.correo);
}
int lectura(alumno *a)
    {
    printf("Ingrese la matricula del alumno:");
    scanf("%i", &(*a).matricula);
    fflush(stdin);
    printf ("ingrese el nombre del alumno: ");
    gets(a->nombre);
    fflush(stdin);
    printf ("ingrese la carrera del alumno: ");
    gets((*a).carrera);
    printf ("ingrese el promedio del alumno: ");
    scanf("%f", &(*a).promedio);
    fflush(stdin);
    printf ("ingrese el celular del alumno: ");
    fflush(stdin);
    gets(a->personales.celular);
    }