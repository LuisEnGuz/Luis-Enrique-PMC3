#include<stdio.h>

int productoria(int);
void main(void)
{
    int num;
    do
    {
        printf("ingresa el numero del cual quieres calcular el producto: ");
        scanf("%d",num);
    }
    while( num > 100||num < 1 );
    printf("\nEl producto de %d es: %d",num, productoria(num));
}
int productoria(int n)
{
    int i, pro = 1;
    for(i =1; i <= n; i++)
    pro *= i;
    return (pro);
}