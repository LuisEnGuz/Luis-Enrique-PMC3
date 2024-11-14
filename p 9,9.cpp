#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;

int lee(FILE *);

int main()
{
    FILE *ar;
    if ((ar = fopen("ad1.dat","r")) != NULL)
    lee(ar);
    else
    printf ("\nEl archivo no se puede abrir");
    fclose(ar);
}
int lee(FILE * ap)
{
    alumno alu;
    fread(&alu, sizeof(alumno),1,ap);
    while(!feof(ap))
    {
    printf("matricula %i", alu.matricula);
    printf ("ingrese la carrera: %i ", alu.carrera);
    printf ("promedio: %.2f \t", alu.promedio);
    puts(alu.nombre);
    fread(&alu, sizeof(alumno),1,ap);
    }
}