#include<stdio.h>

int main()
{
    char cad[50];
    int res;
    FILE *ar;
    if ((ar = fopen("arc.text","w")) != NULL)
    {
        printf("Desea ingresar una cadena de caracteres? Si-1 No-0");
        scanf("%i", &res);
        while (res)
        {
            fflush(stdin);
            printf("ingrese la cadena: ");
            gets(cad);
            fputs(cad, ar);
        }
        printf("Desea ingresar otra cadena de caracteres? Si-1 No-0");
        scanf("%i", &res);
        if (res)
        {
            fputs("\n", ar);
        }
        fclose(ar);
    }
    else 
    printf("No se puede abrir el archivo");
}