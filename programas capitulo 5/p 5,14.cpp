#include<stdio.h>
#include<math.h>

const int max = 100;
int lectura(int* , int);
float media(int *, int);
float varianza(int *, int, float);
float desviacion(float);
int frecuencia(int *, int, int*);
int moda(int *, int);


int main ()
{
    int tam, mod, alu[max], fre[11] = {0};
    float med, var, des;
     do
    {
         printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam>max || tam < 1);
    lectura(alu,tam);
    med = media(alu,tam);
    var = varianza(alu, tam, med);
    des = desviacion(var);
    frecuencia(alu, tam, fre);
    mod = moda(fre, 11);
    printf ("\nMedia:           %.2f", med);
    printf ("\nVariacion:           %.2f", var);
    printf ("\nDesviacion:           %.2f", des);
    printf ("\nModa:           %d", mod);
}
int lectura(int a[], int t)
{
    int i;
    for (i=0; i<t; i++)
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &a[i]);
    }
}
float media(int a[], int t)
{
    int i;
    float sum = 0.0;
    for (i=0; i<t; i++)
    {
        sum+=a[i];
        return(sum/t);
    }
}
float varianza(int a[], int t, float m)
{
    int i;
    float sum = 0.0;
    for (i=0; i<t; i++)
    {
        sum+=pow((a[1] -m),2);;
        return(sum/t);
    }
}
float desviacion(float v)
{
    return (sqrt(v));
}
int frecuencia(int a[], int p, float b[])
{
    int i;
    for (i=0; i<p; i++)
    b[a[i]]++;
}
int moda(int a[], int t)
{
     int i, mod= 0, val = a[0];
    for (i=0; i<t; i++)
    if (mod>a[i])
    {
        mod = i;
        val = a[i];
    }
    return (mod);
}