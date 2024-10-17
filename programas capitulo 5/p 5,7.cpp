#include<stdio.h>

int lectura(int *, int);
int imprime(int *, int );
int elimine(int *, int *);

void main()
{
    int tam, arre[100];
    do
    {
       printf("Ingrese el tamaño del arreglo");
       scanf("%i",&tam); 
    } while (tam > 100 || tam < 1);
    lectura(arre,tam);
    imprime(arre,tam);
    elimine(arre, &tam);
}
int lectura(int a[], int t)
{
     int i;
    printf("\n");
    for(i=0; i<t; i++)
    {
        printf("ingrese el elemento %i: ", i+1);
        scanf("%i", &a[i]);
    }
}
int imprime(int a[] ,int t)
{
    int i;
    for(i=0; i<t; i++)
        printf ("\nA[%i]: %i", i + 1, a[i]);
}
int elimina(int a[] ,int *t)
{
    int i = 0, k, l;
    while (i < (*t-1))
    {
        k=+1;
        while (k <= (*t-1))
        {
            if (a[i] == a[k])
            {
                for (l = k; l < (*t-1); l++)
                a[l] = a[l+1];
                *t= *t-1;
            }else 
            k++;
        }
        i++;
    }
}
