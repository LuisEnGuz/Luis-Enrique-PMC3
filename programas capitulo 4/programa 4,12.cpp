#include<stdio.h>

int mcd(int, int);

int main()
{

int nu1, nu2, res;
printf("ingresa los dos numeros:");
scanf("%d %d", &nu1, &nu2);
res = mcd(nu1, nu2);
printf("\nEl maximo comun divisor de %d y %d es: %d", nu1, nu2, res);
}
int mcd(int n1, int n2)
{
    int i;
    if (n1> n2)
    i = n1/2;
    else 
    i = n2/2;
    while ((n1 % i)||(n2 % i))
    i--;
    return i;

}