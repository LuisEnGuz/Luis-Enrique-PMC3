#include<stdio.h>

void rango (int);

int ra1=0;
int ra2=0;
int ra3=0;
int ra4=0;
int ra5=0; 

void main()
{
    float cal;
    printf("ingresa la primera calificacion del alumno: ");
    scanf("%d",&cal);
    while(cal != -1)
    {
        rango(cal);
        printf("ingresa la calificacion del alumno:");
        scanf("%f", &cal);
    }
    printf("\n0..3.99 = %d",ra1);
    printf("\n4..5.99 = %d",ra2);
    printf("\n6..7.99 = %d",ra3);
    printf("\n8..8.99 = %d",ra4);
    printf("\n9..10   = %d",ra5);
}
void rango(int val)
{
    if (val<4)
    ra1++;
    else
    if (val < 6)
    ra2++;
    else
    if (val < 8)
    ra3++;
    else
    if (val < 9)
    ra4++;
    else
    ra5++;
}
