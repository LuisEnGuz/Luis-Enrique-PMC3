#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;

int modifica(FILE *);

int main()
{
    FILE *ar;
    if ((ar = fopen("ad1.dat","r+")) != NULL)
    modifica(ar);
    else
    printf ("\nEl archivo no se puede abrir");
    fclose(ar);
}
int modifica(FILE * ap)
{
    int d;
    alumno alu;
    printf ("\nIngresa el numero de registro que desea modificar");
    scanf("%i", &d);
    fseek(ap, (d-1)*sizeof(alumno),0);
    fread(&alu, sizeof(alumno),1,ap);
    
    printf ("ingrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);

    fseek(ap, (d-1)*sizeof(alumno),0);
    fwrite(&alu, sizeof(alumno),1,ap);
}