#include<stdio.h>
#include<ctype.h>

int main()
{
    char p1;
    printf("\nIngrese un caracter:");
    p1 = getchar();
    if (isdigit(p1))
    printf ("%c es un digito \n",p1);
    else
    printf ("%c no es un digito \n",p1);
    fflush(stdin);
    printf("\nIngrese un caracter:");
    p1 = getchar();
    if (islower(p1))
    printf ("%c es una letra minuscula\n",p1);
    else
    printf ("%c no es una letra minuscula \n",p1);
    fflush(stdin);
    printf("\nIngrese un caracter:");
    p1 = getchar();
    if (isalpha(p1))
        if(isupper(p1))
    printf ("%c es fue convertida de mayuscula a minuscula\n", tolower(p1));
    else
    printf ("%c es una letra minuscula \n",p1);
    else
    printf ("%c no es una letra minuscula \n",p1);
}