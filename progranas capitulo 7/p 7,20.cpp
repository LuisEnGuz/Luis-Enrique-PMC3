#include<stdio.h>

int main()
{
    char p1;
    printf("\nIngrese un caracter:");
    p1 = getchar();

    if (p1 > 96 && p1 < 123)
    {
        printf("La minuscula de su caracteres es");
        putchar(p1 - 32);
    }
    else if (p1 > 64 && p1 < 91)
    {
        printf("La mayuscula de su caracteres es");
        putchar( p1 + 32);
    }
    else if (p1 = 165)
    {
        printf("La minuscula de su caracteres es");
        putchar(p1 - 1);
    }
    else if (p1 = 164)
    {
        printf("La minuscula de su caracteres es");
        putchar(p1 + 1);
    }
}
