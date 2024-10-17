#include<stdio.h>
const int tam = 100;
int imprime(int , int);
int primo(int , int *);

int main()
{
    int p[tam] = {1,2};
    int fla, j = 2, pri = 3;
    while (j <= tam)
    { 
        fla = 1;
        primo(pri, &fla);
        if (fla)
        {
            p[j] += 2;
            j++;
        }
        pri += 2;
    }
    imprime(p,tam);
}
int primo(int a, int *b)
{
    int di = 3;
    while (*b && (di < (a/2)))
    {
        if ((a %  di)==0)
        *b = 0;
        di++;
    }
}
int imprime(int primos[], int t)
{
    int i;
    for(i=0; i<t; i++)
    printf("\nPrimos[%i]: %i", i, primos[i]);
}