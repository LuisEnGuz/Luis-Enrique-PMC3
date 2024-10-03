#include<stdio.h>

int a, b, c, d;

int funcion1(int, int *, int *);
int funcion2(int *, int);

int main()
{

int a;
a = 1;
b = 2;
c = 3;
d = 4;
printf("\n %i %i %i %i", a, b, c, d);
a = funcion2 (&a, c);
printf("\n %i %i %i %i", a, b, c, d);
}
int funcion1(int r, int *b, int *c)
{ 
int d; 
a = *c;
d= a + 3 + *b;
if (r)
{
    *b = 2 + *b;
    *c= *c + 4;
    printf("\n %i %i %i %i", a, b, c, d);
}
else
{
    *b= 5 + *b;
    *c= *c + 4;
    printf("\n %i %i %i %i", a, b, c, d);
}
}
int funcion2(int *d, int c)
{
int b; 
a = 1; 
b = 7;
funcion1(-1, d, &b);
 printf("\n %i %i %i %i", a, b, c, d);
 c += 3;
 (*d) += 2; 
  printf("\n %i %i %i %i", a, b, c, d);
}
