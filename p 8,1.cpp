#include<stdio.h>
#include<string.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};


int main()
{
    struct alumno a1={120,"maria", "contabilidad", 8.9, "Queretaro"}, a2, a3;
    char nom[20], car[20], dir[20];
    int mat;
    float pro;
    printf("Ingrese la matricula del alumno 2:");
    scanf("%i", &a2.matricula);
    fflush(stdin);
    printf ("ingrese el nombre del alumno 2: ");
    gets(a2.nombre);
    printf ("ingrese la carrera del alumno 2: ");
    gets(a2.carrera);
    printf ("ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);
    printf ("ingrese la direccion del alumno 2: ");
    gets(a2.direccion);
    printf("Ingrese la matricula del alumno 3:");
    scanf("%i", &mat);
    a3.matricula=mat;
    fflush(stdin);
    printf ("ingrese el nombre del alumno 3: ");
    gets(nom);
    strcpy(a3.nombre, nom);
    printf ("ingrese la carrera del alumno 3: ");
    gets(car);
    strcpy(a3.nombre, car);
    printf ("ingrese el promedio del alumno 3: ");
    scanf("%f", &pro);
    a3.promedio=pro;
    fflush(stdin);
    printf ("ingrese la direccion del alumno 3: ");
    gets(dir);
    strcpy(a3.direccion, dir);

    printf ("\nDatos del alumnno 1: \n");
    printf ("%i\n",a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf ("%.2f\n",a1.promedio);
    puts(a1.direccion);
    printf ("\nDatos del alumnno 1: \n");
    printf ("%i\n",a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf ("%.2f\n",a2.promedio);
    puts(a2.direccion);

    printf ("\nDatos del alumnno 3: \n");
    printf("%d \t %s \t %s \t %.2f \t %s", a3.matricula, a3.nombre,a3.carrera, a3.promedio, a3.direccion);
}