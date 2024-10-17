#include<stdio.h>

int lecturam(float [][12], int, int);
int lecturav(float *, int);
int f1(float [][12], int, int, float *, float *);
int f2(float [][12], int, int);
int f3(float *, int);

int main()
{
    float fon[5][12],pre[5],ren[5];
    lecturam(fon, 5, 12);
    lecturav(pre, 5);
    f1(fon, 5, 12, pre, ren);
    f2(fon, 5, 12);
    f3(pre, 5);
}
int lecturam(float a[][12], int f, int c)
{
     int i, j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
        {
            printf ("\nPrecio fondo de %i mes %i: ", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int lecturav(float a[][12], int t)
{
     int i;
     printf("\n");
    for(i=0;i<t;i++)
        {
            printf ("\nPrecio fondo de %i mes 31/12/2003: ", i+1);
            scanf ("%i", &a[i]);
        }
}
int f1(float a[][12], int f, int c, float b[], float v[])
{
    int i;
    printf("\nRENDIMIENTOS ANUALES DE LOS FONDOS");
    for(i=0;i<f;i++)
        {
            v[i]=(a[i][c-1] - b[i]/b[i]*100);
            printf ("\nFondo %i:  %.2f", i + 1,v[i]);
        }
}
int f2(float a[][12], int f, int c)
{
     int i, j;
    float sum, pro;
    printf("\nPROMEDIOS ANUALIZADOS DE LAS ACCIONDES DE LOS FONDOS");
    for(i=0;i<f;i++) 
        sum=0;
        for(j=0;j<c;j++)
            sum += a[i][j];
        pro = sum/c;
        printf ("\nFondo %i:  %.2f", i + 1, pro);
}
int f3(float a[], int f)
{
    float me = a[0], pe = a[0];
 int m = 0, p = 0, i;
 for (i=1; i<f; i++)
 {
 if (a[i] > me)
 {
 me = a[i];
 m= i;
 }
 if (a[i] < pe)
 {
 pe = a[i];
 p = i;
 }
 }
 printf("\n\nMEJOR Y PEOR FONDO DE INVERSION");
 printf("\nMejor fondo: %d\tRendimiento: %6.2f", m+1, me);
 printf("\nPeor fondo: %d\tRendimiento: %6.2f", p+1, pe);
}
