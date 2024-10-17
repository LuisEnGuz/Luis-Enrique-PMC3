#include<stdio.h>

const int tam=10;

int lectura(int [][tam], int);
int imprime(int [][tam], int);

int main()
{
    int mat[tam][tam];
    lectura(mat, tam);
    imprime(mat, tam);
}
int lectura(int a[][tam], int f)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<f;j++)
        {
            printf ("\nIngrese el elemento %i %i:", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int imprime(int a[][tam], int f)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<tam;j++)
            if(i == j)
               printf("\nDiagonal %i %i: %i",i,j,a[i][j]);
}