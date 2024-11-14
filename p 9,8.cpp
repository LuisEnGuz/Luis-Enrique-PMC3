#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;

int escribe(FILE *);

int main()
{
    FILE *ar;
    if ((ar = fopen("ad1.dat","w")) != NULL)
    escribe(ar);
    else
    printf ("\nEl archivo no se puede abrir");
    fclose(ar);
}
int escribe(FILE * ap)
{
    alumno alu;
    int i = 0, r;
    printf("\nDesea ingresar informacion sobre los alumnos? Si-1 No-0");
    scanf("%i", &r);
    while(r)
    {
    i++;
    printf("Ingrese la matricula del alumno:");
    scanf("%i", &alu.matricula);
    fflush(stdin);
    printf ("ingrese el nombre del alumno: ");
    gets(alu.nombre);
    printf ("ingrese la carrera del alumno: ");
    scanf("%i", &alu.carrera);
    printf ("ingrese el promedio del alumno: ");
    scanf("%f", &alu.promedio);

    fwrite(&alu, sizeof(alumno),1,ap);
    printf("\nDesea ingresar informacion sobre otro alumno? Si-1 No-0");
    scanf("%i", &r);
    }
}