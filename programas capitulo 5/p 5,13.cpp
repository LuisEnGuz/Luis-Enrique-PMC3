#include<stdio.h>

const int max = 100;
int lectura(int* , int);
int ordena(int *, int);
int imprime(int *, int);
int main ()
{
    int tam, vec[max];
    do
    {
         printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam>max || tam < 1);
    ordena(vec,tam);
    lectura(vec,tam);
    imprime(vec,tam);
}
int lectura(int a[] , int t)
{
    int i;
    for(i=0; i<t; i ++)
    {
        printf("ingrese el elemento del arreglo: ");
        scanf("%i", &a[1]);
    }
}
int imprime(int a[] , int t)
{
    int i;
        for(i=0; i<t; i++)
        printf ("\na[%i]: %i", i + 1, a[i]);
}
int ordena(int a[], int t)
{
    int j, men, i, l;
    for(i=0; i<t; i++)
     for(i=0; i< (t-1) ; i++)
     {
        for(j=(i+1); j<t; j++)
        if (a[j] < men)
        {
            men = a[j];
            l = j;
        }
        a[l] = a[i];
        a[i] = men;
        men = a[i];
     }
}