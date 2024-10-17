#include<stdio.h>

const int pro = 12;
const int yea = 3;
const int mes = 8;

int lectura(float [pro][mes][yea], int, int, int);
int funcion1(float [pro][mes][yea], int, int, int);
int funcion2(float [pro][mes][yea], int, int, int);
int funcion3(float [pro][mes][yea], int, int, int);

int main()
{
    float llu[pro][mes][yea];
    lectura(llu, pro, mes, yea);
    funcion1(llu, pro, mes, 2);
    funcion2(llu, pro, mes, yea);
    funcion3(llu, mes, mes, yea);
}
int lectura(float a[][mes][yea], int f, int c, int p)
{
    
    int i, j, k;
    for(k=0;k<p;k++)
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
            {
                printf ("\nAño: %i \t Mes: %i \t Departamento: %i:",k+1, i+1, j+1);
                scanf ("%i", &a[i][j][k]);
            }
}
int funcion1(float a[][mes][yea], int f, int c, int p)
{
    int i, j;
    float sum = 0.0;
    for(i=0;i<f;i++)
    {
        sum=0;
        for(j=0;j<c;j++)
            sum += a[i][j][p-1];
    }
    printf("\nVentas de la empresa en el segundo año: %.2f",  sum);
}
int funcion2(float a[][mes][yea], int f, int c, int p)
{
    int i, j;
     float sum1 = 0, sum2 = 0, sum3 = 0;
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
            switch(j+1)
            {
                case 1: sum1 += a[i][j][p-1];
                break;
                case 2: sum2 += a[i][j][p-1];
                break;
                case 3: sum3 += a[i][j][p-1];
                break;
            }
            if (sum1>sum2)
                 if (sum1 > sum3)
                 {
                    printf ("\n Departamento con mayores ventas del año: Hilos");
                    printf("\nVentas: %.2f",  sum1);
                 }
                 else
                 {
                    printf ("\n Departamento con mayores ventas del año: licra");
                    printf("\nVentas: %.2f",  sum3);
                 }
                 else 
                 if(sum2 > sum3)
                 {
                    printf ("\n Departamento con mayores ventas del año: lanas");
                    printf("\nVentas: %.2f",  sum2);
                 }
                 else 
                 {
                    printf ("\n Departamento con mayores ventas del año: licra");
                    printf("\nVentas: %.2f",  sum3);
                 }
}
int funcion3(float a[][mes][yea], int f, int c, int p)
{
    int i, j, k, de, me, an;
    float ven = -1.0;
    for(k=0;k<p;k++)
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
            {
                if (a[i][j][k] > ven)
                {
                ven = a[i][j][k];
                de = j;
                me = i;
                an = k;
                }
            }
            printf ("\nAño: %i \t Mes: %i \t Departamento: %i:",an+1, me+1, an+1);
            printf("\nVentas: %.2f",  ven);
}