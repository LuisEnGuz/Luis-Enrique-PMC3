#include<stdio.h>
#include<stdlib.h>

int main(){

float x= 0.0;
float b= 0.0;
int cont= 0;
printf("Calcula la raiz de: ");
scanf ("%f",&x);
b = x;
while (!(b==(x/b))){

    cont++;
    b = 0.5 * (b+(x/b));
printf("\nEl valor de b[%i] %f",cont,b);
}
printf("\nRaiz cuadrada de %f es: %f",x,b);
return 0;
}
