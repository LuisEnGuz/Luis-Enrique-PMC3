#include<stdio.h>

int lectura1(int [15][12]);
int lectura2(float *, int);
int funcion1(int [][12], int, int, float *, float *);
int funcion2(float *, int);
int funcion3(float *, int);

int main ()
{
    int fab[15][12];
    float cos[15], ven[15];
    lectura1(fab);
    lectura2(cos, 15);
    funcion1(fab, 15, 12, cos, ven);
    funcion2(ven, 5);
    funcion3(ven, 15);
}
int lectura1(int a[][12])
{
    int mes, pro, can;
    printf("\nIngrese mes, tipo de producto y cantidad vendida");
    scanf("%i %i %i", &mes, &pro, &can);
    while(mes!=-1 && pro!= -1 && can!=-1)
    {
        a[mes-1][pro-1] +=can;
        printf("\nIngrese mes, tipo de producto y cantidad vendida");
        scanf("%i %i %i", &mes, &pro, &can);
    }
}
int lectura2(float a[], int n)
{
    int i, j;
    for(i=0;i<n;i++) 
    {
        printf ("\n ingrese el costo del producto %i:", i+1);
        scanf ("%i", &a[i]);
    }
}
int funcion1(int a[][12], int f, int c, float v1[], float v2[])
{
    int j, sum, i;
    printf("\n");
    for(i=0;i<c;i++)
    {
        sum=0;
        for(j=0;j<c;j++)
            sum += a[i][j];
        v2[1]= v1[i] * sum;
        printf("\nTotal del ventas del producto: %i %8.2f",i+1, v2[i]);
    }
}
int funcion2(float a[], int c)
{
    int i;
    float sum = 0.0;
    for(i=0;i<c;i++) 
        sum += a[i];
    printf("\nTotal del ventas de la fabrica: %.2f",sum);
}
int funcion2(float a[], int c)
{
    int i, tpr = 0;
    float ven = a[0];
    for(i=0;i<c;i++)
        if(ven < a[i])
        {
            tpr = i;
            ven = a[i];
        }
   printf("\n\n tipo del producto mas vendido: %i \t ventas %.2f",tpr + 1, ven);
}