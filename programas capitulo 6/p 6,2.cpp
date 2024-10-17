#include<stdio.h>

const int max=50;
int suma(int [][max], int [][max], int [][max], int, int);
int lectura(int [][max], int, int);
int imprime(int [][max], int, int);

int main()
{
    int ma[max][max], mb [max][max], mc[max][max];
    int fil, col;
    do
    {
         printf("ingrese el numero de filas de los arreglos: ");
        scanf("%i", &fil);
    } 
    while (fil>max || fil < 1);
do
    {
         printf("ingrese el numero de columnas de los arreglos: ");
        scanf("%i", &col);
    } 
    while (col>max || col < 1);
printf ("\nLectura del arreglo mb\n");
lectura(mb, fil, col);
suma(ma, mb, mc, fil, col);
printf("\nImpresion del arreglo mc\n");
imprime(mc, fil, col);
}
int lectura(int a[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf ("\nIngrese el elemento %i %i:", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int suma(int m1[][max], int m2[][max], int m3[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m3[j][i]= m1[j][i] + m2[j][i];
}
int imprime(int a[][max], int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf("\nElemento %i %i: %i",i,j,a[i][j]);
        }
}