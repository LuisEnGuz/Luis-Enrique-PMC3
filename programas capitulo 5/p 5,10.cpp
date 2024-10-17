#include<stdio.h>

const int max = 100;
int lectura(int , int);
int busca(int *, int, int);

int main()
{
    int res, ele, tam, vec[max];
    do
    {
         printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam>max || tam < 1);
    lectura(vec, tam);
    printf("ingrese el tamaño del arreglo: ");
    scanf("%i", &ele);
    res = (vec, tam, ele);
    if (res)
    printf ("El elemento se encuentra en la posicion %d del arreglo", res);
    else
    printf ("El elemento no se encuentra en el arreglo");
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
int busca(int a[], int t, int e)
{
    int i = 0, ban = 0, res;
    while ((i < t) && (e >= a[i]) && !ban)
    if (a[i] == e)
    ban++;
    else
    i++;
    if (ban)
    res = i +1;
    else 
    res = ban;
    return (res);
}