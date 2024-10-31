#include<stdio.h>
#include<string.h>

typedef struct 
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
}producto;

int lectura(producto *, int);
int ventas(producto *, int);
int reabastecimiento(producto *, int);
int nuevos_productos(producto *, int *);
int inventario(producto *, int);

int main()
{
    producto inv[100];
    int tam, ope;
    do
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } while (tam>100||tam<1);
    lectura(inv,tam);
    printf("\nIngrese operacion a realizar. \n\t\t1 - ventas \n\t\t 2 - rebastecimiento \n\t\t 3 - nuevos productos \n\t\t 4 - inventario \n\t\t 0 - salir:");
    scanf("%d", &ope);
    while (ope)
    {
        switch (ope)
        {
            case 1: ventas(inv, tam);
            break;
            case 2: reabastecimiento(inv, tam);
            break;
            case 3: nuevos_productos(inv, &tam);
            break;
            case 4: inventario(inv, tam);
            break;
        };
        printf("\nIngrese operacion a realizar. \n\t\t1 - ventas \n\t\t 2 - rebastecimiento \n\t\t 3 - nuevos productos \n\t\t 4 - inventario \n\t\t 0 - salir:");
        scanf("%d", &ope);
    }
}

int lectura(producto a[], int t)
{
    int i;
    for (i=0; i<t; i++)
    {
        printf("\nIngrese informacion del producto %i",i+1);
        printf("\n\tClave: ");
        scanf("%i", &a[i].clave);
        fflush(stdin);
        printf("\n\tNombre: ");
        gets(a[i].nombre);
        printf("\n\tPrecio: ");
        scanf("%i", &a[i].precio);
        printf("\n\tExistencia: ");
        scanf("%i", &a[i].existencia);
    }
}

int ventas(producto a[], int t)
{
    int cla, can, i, res;
    float tot, par;
    printf("\nIngrese clave del producto -0 para terminar");
    scanf("%i", &cla);
    tot = 0.0;
    while(cla)
    {
        printf("\tcantidad: ");
        scanf("%d", &can);
        i = 0;
        while((i < t) && (a[i].clave < cla))
            i++;
        if ((i == t) || (a[i].clave < cla))
            printf("\nLa clave del producto es incorrecta");
        else
            if(a[i].existencia >= can)
            {
                a[i].existencia -= can;
                par = a[i].precio * can;
                tot += par;
            }    
            else
            {
                printf("\nNo existe la cantidad solicitada. solo hay %i", a[i].existencia);
                printf("\nLos lleva 1- si o 0- no?: ");
                scanf("%d", &res);
                if (res)
                {
                    par = a[i].precio * a[i].existencia;
                    a[i].existencia = 0;
                    tot += par;
                }
            }
            printf("\nIngrese la siguiente clave del producto -0 para terminar");
            scanf("%i", &cla);
    }
    printf("\nTotal de la venta: %f", tot);
}

int reabastecimiento(producto a[], int t)
{
    int cla, can, i;
    printf("\nIngrese clave del producto -0 para terminar");
    scanf("%i", &cla);
    while(cla)
    {
        i=0;
        while((i < t) && (a[i].clave < cla))
            i++;
        if ((i == t) || (a[i].clave < cla))
            printf("\nLa clave del producto es incorrecta");
        else
            {
                printf("\nCantidad :");
                scanf("%i", &can);
                a[i].existencia += can;
            }
            printf("\nIngrese la siguiente clave del producto -0 para terminar");
            scanf("%i", &cla);    
    }
}
int nuevos_productos(producto a[], int *t)
{
    int cla, j, i;
    printf("\nIngrese clave del producto -0 para terminar");
    scanf("%i", &cla);
    while((*t < 30) && (cla))
    {
        i=0;
        while((i < *t) && (a[i].clave < cla))
            i++;
        if (i == *t)
        {
        a[i].clave = cla;
        printf("\n\tNombre: ");
        gets(a[i].nombre);
        printf("\n\tPrecio: ");
        scanf("%i", &a[i].precio);
        printf("\n\tExistencia: ");
        scanf("%i", &a[i].existencia);
        *t = *t + 1;
        }
        else
            if(a[i].clave == cla)
                printf("\nEl producto ya se encuentra en el inventario");
            else
            {
                for(j=*t; j>i; j--)
                    a[j] = a[j-1];
                a[i].clave = cla;
                printf("\n\tNombre: ");
                gets(a[i].nombre);
                printf("\n\tPrecio: ");
                scanf("%i", &a[i].precio);
                printf("\n\tExistencia: ");
                scanf("%i", &a[i].existencia);
                *t = *t + 1;
            }
            printf("\nIngrese la siguiente clave del producto -0 para terminar");
            scanf("%i", &cla);
    }
    if (*t ==30)
        printf("\nYa no hay espacio para incorporar nuevos productos");
}
int inventario(producto a[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        printf("\n\tClave: %d",a[i].clave);
        printf("\n\tNombre: %s",a[i].nombre);
        printf("\n\tPrecio: %i",a[i].precio);
        printf("\n\tExistencia: %i",a[i].existencia);
    }
}