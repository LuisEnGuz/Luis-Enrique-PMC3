#include<stdio.h>

void mayor(float, float, float);

int main()
{
int i;
float gol, pac, car, agol= 0, apac = 0, acar = 0;
for(i=1; i<=12; i++)
{
    printf("\n\ningrese las lluvias del mes %d",i);
    printf("Regiones golfo, pacifico y caribe: ");
    scanf("%f %f %f",&gol,&pac,&car );
    agol += gol;
    apac += pac;
    acar += car;
}
printf("\n\nPromedio de lluvias region del golfo: %6.2f", (agol/12));
printf("\n\nPromedio de lluvias region del golfo: %6.2f", (acar/12));
printf("\n\nPromedio de lluvias region del golfo: %6.2f", (apac/12));
}
void mayor(float r1, float r2, float r3)
{
    if(r1>r2)
    if(r1>r3)
    printf("\nregion con mayor promedio: region golfo .Promedio: %6.2f", r1/12);
    else
     printf("\nregion con mayor promedio: region caribe .Promedio: %6.2f", r3/12);
    else
    if(r2>r3)
    printf("\nregion con mayor promedio: region pacifico .Promedio: %6.2f", r1/12);
    else
    printf("\nregion con mayor promedio: region caribe .Promedio: %6.2f", r3/12);
}
