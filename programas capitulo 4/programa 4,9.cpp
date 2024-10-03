#include<stdio.h>

int suma(int x, int y)
{
    return(x+y);
}
int resta(int x, int y)
{
    return(x-y);
}
int control(int (*apf) (int,int), int x,int y)
{
    int res;
    res=(*apf) (x,y);
    return(res);
}
void main ()
{
    int r1,r2;
    r1= control (suma, 15, 5);
    r2= control (resta, 10,4);
    printf("\nresultado 1; %d",r1);
    printf("\nresultado 2; %d",r2);
}