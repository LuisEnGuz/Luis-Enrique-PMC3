#include<stdio.h>

int f1(int , int *);

int a =3;
int b =7;
int c =4;
int d =2;

int main()
{

a = f1 (c, &d);
printf("\n %i %i %i %i", a, b, c, d);
c = 3;
c = f1 (a, &c);
printf("\n %i %i %i %i", a, b, c, d);
}
int f1(int x, int *y)
{
int a; 
a = x * *y;
b += *y;
printf("\n %i %i %i %i", a, b, c, d);
y--;
return (c);
}