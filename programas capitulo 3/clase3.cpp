#include<stdio.h>
#include<stdlib.h>

int main(){

int num=0;
int num2=0;
int i = 0;
for(;i <=10; i++)
{
    num = i;
    num2 = num * num;
    printf("\nEl cuadrado de NUM[%i] es:%i",num,num2);

}
printf("\n\n------------------------\n\n");
i=0;
while(i <= 10)
{
    num = i;
    num2 = num * num;
    printf("\nEl cuadrado de NUM[%i] es:%i",num,num2);
i++;
}

printf("\nEl programa finalizo");
return 0;

}
