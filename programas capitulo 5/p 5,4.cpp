#include<stdio.h>

const int max = 10;
int imprime(int vec[] ,int t);
int lectura(int vec[] ,int t);
int producto(int *x, int *y, int *z, int t);

void main()
{
    int ve1[max], ve2[max], ve3[max];
    lectura(ve1, max);
    lectura (ve2, max);
    producto(ve1, ve2, ve3, max);
    printf ("Producto de los vectores");
    imprime(ve3, max);

}
int lectura(int vec[] ,int t)
{
    int i;
    printf("\n");
    for(i=0; i<t; i++)
    {
        printf("ingrese el elemento %i: ", i+1);
        scanf("%i", &vec[i]);
    }
}
int imprime(int vec[] ,int t)
     {
     int i;
        for(i=0; i<t; i++)
        printf ("\nVEC[%i]: %i", i + 1, vec[i]);
     }
int producto(int *x, int *y, int *z, int t)
{
    int i;
    for(i=0; i<t; i++)
    z[i]= x[i] * y[i];
}
    