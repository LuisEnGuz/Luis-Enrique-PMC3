#include<stdio.h>
#include<string.h>

int main()
{
    int i;
    char* cad0 = "hola mexico";
    char cad1[20] = "hola guatemala";
    char cad2[20] = "hola venezuela";
    char cad3[20] = "hola mexico";
    char *c, c3;
    i = strcmp(cad1,cad0);
    printf("\nResultado de la comparacion entre cad1 a cad0: %i\n", i);
    i = strcmp(cad0,cad2);
    printf("\nResultado de la comparacion entre cad0 a cad2: %i\n", i);
    i = strcmp(cad0,cad1);
    printf("\nResultado de la comparacion entre cad0 a cad1: %i\n", i);
    i = strlen(cad0);
    printf("\nLongitud de la cad0: %i\n", i);
    i = strlen(cad1);
    printf("\nLongitud de la cad1: %i\n", i);
    c = strchr(cad1,'g');
    if(c!= NULL)
    {
        c3 = *c;
        printf ("\nEl valor de c3 es: %c", c3);
    }
    c = strchr(cad2,'v');
    if(c!= NULL)
    {
        c3 = *c;
        printf ("\nEl valor de c3 es: %c", c3);
    }
}