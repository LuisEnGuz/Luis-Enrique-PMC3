#include<stdio.h>

int multiplo(int, int);
 
int main()
{

int nu1, nu2, res;
printf("ingresa los dos numeros:");
scanf("%d %d", &nu1, &nu2);
res = multiplo(nu1, nu2);
if(res)
printf("\n el segundo numero es multiplo del primero");
else
printf("\n el segundo numero no es multiplo del primero");
}
int multiplo(int n1, int n2)
{
    int res;
    if ((n2 % n1)==0)
    res = 1;
    else
    res = 0;
}
