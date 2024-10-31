#include<stdio.h>
#include<string>

typedef struct 
{
    char mat[20];
    int pro;
}matpro;

typedef struct 
{
    char nom[20];
    int matri;
    matpro cal[5];
}alumno;

int lectura(alumno, int t);
int f1(alumno *, int tam);
int f2(alumno *, int tam);
int f3(alumno *, int tam);

int main()
{
    alumno alu[50];
    int tam;
    do
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam > 50 || tam < 1);
    lectura(alu, tam);
    f1(alu,tam);
    f2(alu,tam);
    f3(alu,tam);
}

int lectura(alumno a[], int t)
{
    int i,j;
    for(i=0;i<t; i++)
    {
        printf("Ingrese los datos del alumno %d:",i+1);
        printf("Ingrese la matricula del alumno :");
        scanf("%i", &a[i].matri);
        fflush(stdin);
        printf ("ingrese el nombre del alumno : ");
        gets(a[i].nom);
        for(j=0;j<5;j++)
        {
            printf("\nMateria :");
            fflush(stdin);
            gets(a[i].cal[j].mat);
            printf("\nPromedio :");
            scanf("%i", &a[i].cal[j].pro);
        }
    }
}
int f1(alumno a[], int t)
{
    int i,j;
    float sum;
    for(i=0;i<t; i++)
    {
        printf("\nMatricula del alumno: %d", a[i].matri);
        sum = 0.0;
        for(j=0;j<5;j++)
            sum = sum + a[i].cal[j].pro;
        sum = sum/5;
        printf("\t\tPromedio: %.2f",sum);
    }
}
int f2(alumno a[], int t)
{
    int i;
    printf("Alumno con calificacion en la tercera materia mayor a 9:");
    for(i=0;i<t; i++)
    {
        if(a[i].cal[2].pro >9)
            printf("\nMatricula del alumno: %d", a[i].matri);
    }
}
int f3(alumno a[], int t)
{
    int i;
    float sum=0.0;
    for(i=0;i<t; i++)
        sum = sum + a[i].cal[3].pro;
    sum = sum/t;
    printf("\t\tPromedio de la materia 4: %.2f",sum);
    
}
