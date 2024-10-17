#include <stdio.h>

const int max=50;

int cuadrado(int [][max], int);
int imprime(int [][max], int);

int main()
{
    int cma[max][max],tam;
     do
    {
         printf("ingrese tamaño del arreglo: ");
        scanf("%i", &tam);
    } while ((tam > max ||tam < 1) && (tam % 2));
    cuadrado(cma, tam);
    imprime(cma, tam);
}
int cuadrado(int a[][max], int n)
{
    int i = 1, fil = 0, col = n/2, num = n * n;
    while (i<=num)
    {
        a[fil][col]= i;
        if (i%n != 0)
        {
            fil = (fil - 1 + n) %n;
            col = (col + 1) % n;
        }
        fil++;
        i++;
    }
}
int imprime(int a[][max], int n)
{
    {
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        { 
            printf ("\nElemento %i : %.2f", i+1, j+1,a[i][j]);
        }
    }
}