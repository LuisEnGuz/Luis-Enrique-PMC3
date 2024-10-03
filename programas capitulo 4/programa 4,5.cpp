#include<stdio.h>

int cubo(int);

void main(void)
{
int i;
for(i = 1; i<=10; i++)
printf("\nel cubo de I es %d", cubo(i));
}
int cubo(int k)
{
    return(k*k*k);
}