#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;
    printf("\nDesea ingresar una cadena de caracteres (s/n)? ");
    c = getchar();
    while (c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        fflush(stdin);
        gets(cad);
        i++;
        sum += atof(cad);
        printf("\nDesea ingresar otra cadena de caracteres (s/n)? ");
        c = getchar();
    }
    printf("Suma: %.2f", sum);
    printf("promedio: %.2f", sum/i);
}