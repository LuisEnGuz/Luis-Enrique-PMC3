#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int minmay(char *cad);
int main()
{
    int i, n;
    char fra[20][50];
    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        printf ("\nIngrese la linea %i de texto:", i+1);
        fflush (stdin);
        gets(fra[i]);
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    minmay(fra[i]);
}
int minmay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;
     while (cadena[i] !='\0')
     {
        if(islower (cadena[i]))
            mi++;
        else
        if(isupper (cadena[i]))
            ma++;
        i++;
     }
printf("\n\nNumero de letras mayusculas: %i", mi);
printf("\nNumero de letras mayusculas: %i", ma);
}
