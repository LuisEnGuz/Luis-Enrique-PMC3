#include<stdio.h>

const int max = 100;
int lectura(int , int);
int binaria(int *, int, int);

int main ()
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
int binaria(int a[], int t, int e)
{
    int ele, izq= 0, cen, der = t -1, ban = 0;
    while ((izq <= der) && (!ban))
    {
        cen = (izq + der) /2;
        if (e == a[cen])
        ban=cen;
        else
        if(e>a[cen])
        izq = cen +1;
        else 
        der = cen -1;
    }
    return (ban);
}