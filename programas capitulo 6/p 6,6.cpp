#include<stdio.h>

const int max=50;
int lectura(float [][max], int, int);
int imprime(float [][max], int, int);
int intercambia(float [][max], int, int);
int main ()
{
int f,c;
    float mat[max][max];
     do
    {
         printf("ingrese numero de filas: ");
        scanf("%i", &f);
    } 
    while (f > max ||f < 1);
     do
    {
         printf("ingrese numero de columnas: ");
        scanf("%i", &c);
    } 
    while (c > max ||c < 1);
    lectura (mat, f, c);
    imprime (mat, f, c);
    intercambia(mat, f, c);
}
int lectura(float a[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf ("\n ingrese el elemento %i %i", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int intercambia(float a[][max], int f, int c)
{
    int i, j;
    float aux;
    for(i=0; i<(c/2); i++)
        for(j=0;j<c;j++)
        {
            aux= a[j][i];
            a[j][i]= a[j][c - i -1];
            a[j][c - i -1]= aux;
        }
}
int imprime(float a[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf("\nElemento %i %i: %5.2f",i+1,j+1,a[i][j]);
        }
}