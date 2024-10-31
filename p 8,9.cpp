#include<stdio.h>
#include<string.h>

typedef struct  
{
    char zona[20];
    char calle[20];
    char colo[20];
}ubicacion;

typedef struct
{
    char clave[5];
    float scu;
    float ste;
    char car[50];
    ubicacion ubi;

    float precio;
    char dispo;
}propiedades;

int lectura(propiedades , int);
int f1(propiedades *, int);
int f2(propiedades *, int);

int main()
{
    propiedades propie[100];
    int tam;
    do
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam > 100 || tam < 1);
    lectura(propie, tam);
    f1(propie,tam);
    f2(propie,tam);
}

int lectura(propiedades a[], int t)
{
    int i;
    for(i=0;i<t; i++)
    {
        printf("\n\tIngrese datos de la propiedad %d:", i+1);
        fflush(stdin);
        printf("Clave :");
        scanf("%s", &a[i].clave);
        fflush(stdin);
        printf("superficie cubierta :");
        scanf("%f", &a[i].scu);
        printf("Superficie terreno :");
        scanf("%f", &a[i].ste);
        printf("Caracteristicas :");
        fflush(stdin);
        scanf("%s", &a[i].car);
        printf("Zona :");
        scanf("%i", &a[i].ubi.zona);
        fflush(stdin);
        printf("Calle :");
        scanf("%s", &a[i].ubi.calle);
        printf("Colonia :");
        scanf("%d", &a[i].ubi.colo);
        fflush(stdin);
        printf("Precio:");
        scanf("%f", &a[i].precio);
        printf("Disponibilidad  :");
        scanf("%c", &a[i].dispo);
        
    }
}

int f1(propiedades a[], int t)
{
    int i;
    printf("\n\tListado de propiedades para venta en miraflores");
    for(i=0;i<t; i++)
        if((a[i].dispo == 'v') && (strcmp(a[i].ubi.zona, "Miraflores")==0))
            if ((a[i].precio >= 450000) || (a[i].precio < 650000))
            {
                printf("\nClave de la propiedad\n");
                puts(a[i].clave);
                printf("superficie cubierta :", a[i].scu);
                printf("Superficie terreno :", a[i].ste);
                printf("Caracteristicas :");
                puts(a[i].car);
                printf("Calle :");
                puts(a[i].ubi.calle);
                printf("Colonia :");
                puts(a[i].ubi.colo);
                printf("Precio :", a[i].precio);
                
            }
}
int f1(propiedades a[], int t)
{
    int i;
    float ls, li;
    char zon[20];

    printf("\n\tListado de propiedades para renta");
    printf("Ingrese zona geogarfica");
    fflush(stdin);
    scanf("%s", &zon);
    printf("Limite inferior del precio ");
    scanf("%f", &li);
    printf("Limite superior del precio");
    scanf("%f", &ls);
    for(i=0;i<t; i++)
    {
        printf("\nClave de la propiedad\n");
                puts(a[i].clave);
                printf("superficie cubierta :", a[i].scu);
                printf("Superficie terreno :", a[i].ste);
                printf("Caracteristicas :");
                puts(a[i].car);
                printf("Calle :");
                puts(a[i].ubi.calle);
                printf("Colonia :");
                puts(a[i].ubi.colo);
                printf("Precio :", a[i].precio);
    }
}