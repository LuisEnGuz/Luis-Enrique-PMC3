#include<stdio.h>

int mad(int);

int main()
{
int num, res;
printf("ingresa el numero:");
scanf("%d", &num);
res = mad(num);
printf("el mayor divisor de %d es: %i");
}
int mad(int n1)
{
int i = (n1 / 2);
while(n1 % i)
i--;
return (i);
}