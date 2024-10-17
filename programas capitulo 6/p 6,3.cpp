#include<stdio.h>

const int f = 8, c = 2, p = 5;
int funcion1(int [][c][p], int, int, int);
int funcion2(int [][c][p], int, int, int);
int funcion3(int [][c][p], int, int, int);
int lectura(int [][c][p], int, int, int);

int main ()
{
    int uni[f][c][p];
    lectura(uni, f, c, p);
    funcion1(uni, f, c, p);
    funcion2(uni, f, c, p);
    funcion3(uni, 6, c, p);
}
int lectura(int a[][c][p], int fi, int co, int pr)
{
    int i, j, k;
    for(k=0;k<pr;k++)
        for(i=0;i<fi;i++)
            for(j=0;j<co;j++)
            {
                printf ("\nAño: %i \t Carrera: %i \t Semestre: %i:",k+1, i+1, j+1);
                scanf ("%i", &a[i][j][k]);
            }
        
}
int funcion1(int a[][c][p], int fi, int co, int pr)
{
    int i, j, k, may = 0, ao = -1, sum;
    for(k=0;k<pr;k++)
    {
        sum=0;
        for(i=0;i<fi;i++)
            for(j=0;j<co;j++)
                sum += a[i][j][k];
            if (sum>may)
            {
                may = sum;
                ao = k;
            }
    }
    printf("\nAño con mayor ingreso de alumnos: %i Alumnos: %d",ao+1, may);
}
int funcion1(int a[][c][p], int fi, int co, int pr)
{
    int i, j, k, may = 0, car = -1, sum;
    for(i=0;i<fi;i++)
    {
        sum=0;
        for(j=0;j<co;j++)
            sum += a[i][j][pr -1];
        if (sum>may)
            {
                may = sum;
                car = i;
            }
    }
        printf("\nLa carrera con mas alumnos: %i Alumnos: %d",car+1, may);
}
int funcion1(int a[][c][p], int fi, int co, int pr)
{
    int i, j, k, may = 0, ao = -1, sum;
    for(k=0;k<pr;k++)
    {
        sum=0;
        for(i=0;i<fi;i++)
            for(j=0;j<co;j++)
                sum += a[fi - 1][j][k];
            if (sum>may)
            {
                may = sum;
                ao = k;
            }
    }
    printf("\nAño con mayor ingreso de alumnos: %i Alumnos: %d",ao+1, may);
}