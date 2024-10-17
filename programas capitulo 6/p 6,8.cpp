#include<stdio.h>

const int max=50;
int lectura(int [][max], int, int);
int imprime(int [][max], int, int);
int traspuesta(int [][max],int [][max], int, int);

int main()
{
    int mat[max][max], tra [max][max];
    int fil, col; 
    do
    {
         printf("ingrese numero de filas: ");
        scanf("%i", &fil);
    } while (fil > max ||fil < 1);
    do
    {
         printf("ingrese numero de columnass: ");
        scanf("%i", &col);
    } while (col > max ||col < 1);
    lectura(mat, fil, col);
    traspuesta(mat, tra, fil, col);
    imprime(tra, col, fil);
}
int lectura(int a[][max], int c, int f)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf ("\nIngrese el elemento %i %i: ", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int traspuesta(int m1[][max],int m2[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m2[j][i]= m1[i][j];
}
int imprime(int a[][max], int c, int f)
{
     int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf ("\nElemento %i %i: %i", i+1, j+1,a[i][j]);
        }
}