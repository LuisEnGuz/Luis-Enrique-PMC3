#include<stdio.h>

const int pro = 24;
const int yea = 10;
const int mes = 12;

int lectura(float [pro][mes][yea], int, int, int);
int funcion1(float [pro][mes][yea], int, int, int);
int funcion2(float [pro][mes][yea], int, int, int);
int funcion3(float [pro][mes][yea], int, int, int);

int main()
{
    float llu[pro][mes][yea];
    lectura(llu, pro, mes, yea);
    funcion1(llu, pro, mes, yea);
    funcion2(llu, pro, mes, yea);
    funcion3(llu, 18, mes, 5);
}
int lectura(float a[][mes][yea], int f, int c, int p)
{
    
    int i, j, k;
    for(k=0;k<p;k++)
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
            {
                printf ("\nAño: %i \t Provincia: %i \t Mes: %i:",k+1, i+1, j+1);
                scanf ("%i", &a[i][j][k]);
            }
}
int funcion1(float a[][mes][yea], int f, int c, int p)
{
     int i, j, k, emay = -1;
     float ellu = -1.0 , sum;
    for(k=0;k<p;k++)
    {
        sum=0;
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
                sum += a[i][j][k];
            sum/= p*c;
            if (sum> ellu)
            {
                ellu = sum;
                emay = i;
            }
    }
    printf("\nProvincia con mayor registro de lluvias: %d", emay +1);
    printf("\nRegistro: %.2f",ellu);
}
int funcion2(float a[][mes][yea], int f, int c, int p)
{
    int i, j, k, emen;
     float ellu = 1000 , sum;
    for(k=0;k<p;k++)
    {
        sum=0;
        for(i=0;i<f;i++)
            for(j=0;j<c;j++)
                sum += a[i][j][p-1];
            sum/=c;
            if (sum< ellu)
            {
                ellu = sum;
                emen = i;
            }
    }
    printf("\nProvincia con menor registro de lluvias: %d", emen +1);
    printf("\nRegistro: %.2f",ellu);
}
int funcion3(float a[][mes][yea], int f, int c, int p)
{
    int j, emes= -1;
    float ellu = -1.0;
    for(j=0;j<c;j++)
    {
         if (a[f - 1][j][p-1] > ellu)
            {
                ellu = a[f - 1][j][p-1];
                emes = j;
            }
    }
    printf("\nMes: %d Lluvias: %.2f", emes +1, ellu);
}
