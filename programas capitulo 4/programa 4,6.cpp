#include<stdio.h>

int f1(int *);

void main(void){

int i, k=4;
for(i = 1; i<=3; i++)
{
    printf("Valor de K antes de llamar a la funcion de f1; %d",++k);
    printf("Valor de K despues de llamar a la funcion de f1; %d", f1(&k));
}
}
int f1(int *R)
{
    *R += *R;
}


