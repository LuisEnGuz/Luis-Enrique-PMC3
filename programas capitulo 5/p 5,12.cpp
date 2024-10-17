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
    int aux, l, i;
    for (i=0; i<t; i ++)
    {
        aux = a[i];
        l = i - 1;
        while((l>=0) && (aux < a[l]))
        {
            a[l+1]= a[l];
            l--;
        }
    }a[l + 1] =aux;
}