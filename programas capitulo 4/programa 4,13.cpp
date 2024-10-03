#include<stdio.h>
#include<math.h>

void parimp(int, int *, int *);

void main()
{
    int i, n, num, par = 0, imp = 0;
    printf("ingresa el numero de datos:");
    scanf("%d",&n);
    for(i =1; i <= n; i++)
    {
        printf("ingresa el numero de %d:", i);
        scanf("%d",&num);
    }
}
void parimp(int num, int *p, int *i)
{
    int res;
    res = pow(-1, num);
    if (res > 0)
    *p += 1;
    else
    if (res<0);
    *i+=1;
}
