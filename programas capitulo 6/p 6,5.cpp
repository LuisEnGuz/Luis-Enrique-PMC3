#include<stdio.h>

const int max=50;
const int exa=4;

int funcion1(float [max][exa], int);
int funcion2(float [max][exa], int);
int lectura(float [max][exa], int);

int main()
{
    int nal;
    float alu[max][exa];
     do
    {
         printf("ingrese numero de alumnos del grupo: ");
        scanf("%i", &nal);
    } 
    while (nal > max ||nal < 1);
    lectura(alu, nal);
    funcion1(alu, nal);
    funcion2(alu, nal);
}
int lectura(float a[][exa], int n)
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<exa;j++)
        {
            printf ("\n ingrese la calificacion %i del alumno %i", j+1, i+1);
            scanf ("%i", &a[i][j]);
        }
}
int funcion1(float a[][exa], int t)
{
    int i, j;
    float sum, pro;
    for(i=0;i<t;i++)
    {
        sum = 0;
        for(j=0;j<exa;j++)
            sum += a[i][j];
            pro = sum / exa;
            printf("\nEl promedio del alumno %i es: %5.2f",i+1, pro);
    }
}
int funcion2(float a[][exa], int t)
{
    int i, j, may;
    float sum, pro, mpro = 0;
    printf("\n");
    for(j=0;j<exa;j++)
    {
        sum = 0;
        for(i=0;i<t;i++)
            sum += a[i][j];
        pro = sum / t;
        if(pro> mpro)
        {
            mpro = pro;
            may = j;
        }
        printf("\nEl promedio del examen %i es: %f",j+1, pro);
    }
printf("\nEl examen con mayor promedio es: %i \t Promedio %5.2f",may+1, mpro);
}