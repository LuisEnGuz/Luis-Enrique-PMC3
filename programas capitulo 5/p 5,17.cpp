#include<stdio.h>

int main()
{
    int v1[4] ={1,3,5,7}, v2[4] = {2,4};
    int *ay, *ax;
    ax =  &v1[2];
    ay =  &v2[2];
    v2[2] = *(ax+1);
    v2[3] = *ax;
    ax = ax + 1;
    v1[0] =  *ax;
    printf("\nv1[0] = %i \t v1[1] = %i \t v1[2] = %i \t v1[3] = %i \t v2[0] = %i \t v2[1] = %i \t v2[2] = %i \t v2[3] = %i \t ",  v1[0], v1[1], v1[2], v1[3],v2[0], v2[1], v2[2], v2[3]);
    v1[2] = *ay;
    v1[1] = --*ay;
    ax = ax + 1;
    v1[3] =  *ax;
     printf("\nv1[0] = %i \t v1[1] = %i \t v1[2] = %i \t v1[3] = %i \t v2[0] = %i \t v2[1] = %i \t v2[2] = %i \t v2[3] = %i \t ",  v1[0], v1[1], v1[2], v1[3],v2[0], v2[1], v2[2], v2[3]);
}