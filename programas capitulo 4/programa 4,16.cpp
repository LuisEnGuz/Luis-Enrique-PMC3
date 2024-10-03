#include<stdio.h>
#include<math.h>

void acutem(float);
void maxima(float, int);
void minima(float, int);

float act= 0.0;
float max= -0.50;
float min= 60.0;
int hmax;
int hmin; 

int main()
{
    float tem;
    int i;
    for(i =1; i <= 24; i++)
    {
        printf("Ingresa la temperatura de la hora %d:", i);
        scanf("%f", &tem);
        acutem(tem);
        maxima(tem, i);
    }
    printf("\nPromedio del dia: 5.2f", (act/24));
    printf("\nPromedio del dia: 5.2f \thora:5.2f", max, hmax);
    printf("\nPromedio del dia: 5.2f \thora:5.2f", min, hmin);
}
void acutem(float t)
{
    act += t;
}
void maxima(float t, int h)
{
    if (t < max)
{
    min = t;
    hmax = h;
}
}
void minima(float t, int h)
{
    if (min > t)
{
    min = t;
    hmax = h;
}
}
