#include<stdio.h>
#include<string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    float cal[5];
}alumno;

int lectura(alumno, int t);
int f1(alumno *, int tam);
int f2(alumno *, int tam);
int f3(alumno *, int tam);

int main()
{
    alumno arre[50];
    int tam;
    do
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam > 50 || tam < 1);
    lectura(arre, tam);
    f1(arre,tam);
    f2(arre,tam);
    f3(arre,tam);
}
int lectura(alumno a[], int t)
{
    int i,j;
    for(i=0;i<t; i++)
    {
        printf("Ingrese los datos del alumno %d:",i+1);
        printf("Ingrese la matricula del alumno :");
        scanf("%i", &a[i].matricula);
        fflush(stdin);
        printf ("ingrese el nombre del alumno : ");
        gets(a[i].nombre);
        for(j=0;j<5;j++)
        {
            printf("Ingrese la calificacion del alumno :");
            scanf("%i", &a[i].cal[j]);
        }
    }
}

int f1(alumno a[], int t)
{
    int i,j;
    float sum, pro;
    for(i=0;i<t; i++)
    {
        printf("\nMatricula del alumno: %d", a[i].matricula);
        sum = 0.0;
        for(j=0;j<5;j++)
            sum = sum + a[i].cal[j];
        pro = sum/5;
        printf("\t\tPromedio: %.2f",pro);
    }
}

int f2(alumno a[], int t)
{
    int i;
    printf("Alumno con calificacion en la tercera materia mayor a 9:");
    for(i=0;i<t; i++)
    {
        if(a[i].cal[2]>9)
            printf("\nMatricula del alumno: %d", a[i].matricula);
    }
}
int f3(alumno a[], int t)
{
    int i;
    float sum, pro;
    for(i=0;i<t; i++)
        sum = sum + a[i].cal[3];
    pro = sum/t;
    printf("\t\tPromedio de la materia 4: %.2f",pro);
    
}