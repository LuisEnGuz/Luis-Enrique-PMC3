#include<stdio.h>

const int tam = 50;

int lectura(int *, int);
int frecuencia(int *, int , int *, int );
int impresion(int *, int );
int mayor(int *, int);

void main()
{
    int cal[tam], fre[6] = {0};
    lectura(cal, tam);
    frecuencia(cal, tam, fre, 6);
    printf("Frecuencia de calificaciones\n");
    impresion(fre, 6);
    mayor(fre, 6);
}
int lectura(int vec[] ,int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        printf("ingrese la calificacion -0.5 del alumno %i: ", i+1);
        scanf("%i", &vec[i]);
    }
}
int impresion(int vec[] ,int t)
     {
     int i;
        for(i=0; i<t; i++)
        printf ("\nVEC[%i]: %i", i + 1, vec[i]);
     }
 int frecuencia(int a[], int b[], int p[], int t)
{
    int i;
    for(i=0; i<t; i++)
    if((a[1] >= 0) && (a[1] < 6))
    b[a[i]]++;
}
int mayor(int *x, int t)
{
    int i, mfre = 0, mval = x[0];
    for(i=0; i<t; i++)
    if (mval < x[i])
    {
        mfre = i;
        mval = x[i];
    }
    printf("\n\nMayor frecuencia de calificaciones: %d \tvalor: %d",mfre, mval);
}

