#include<stdio.h>

int main()
{
    int v1[4] ={2,3,4,9}, v2[4] = {6};
    int *ay, *ax;
    ax =  &v1[3];
    ay =  &v2[2];
    v1[v2[0]-v1[2]]= *ay;
    *ay = *ax - v1[0];
    printf("\nv1[0] = %i \t v1[1] = %i \t v1[2] = %i \t v1[3] = %i \t v2[0] = %i \t v2[1] = %i \t v2[2] = %i \t v2[3] = %i \t ",  v1[0], v1[1], v1[2], v1[3],v2[0], v2[1], v2[2], v2[3]);
     v2[1] = ++*ax;
     v2[3] = (*ay)++;
     *ax += 2;
     printf("\nv1[0] = %i \t v1[1] = %i \t v1[2] = %i \t v1[3] = %i \t v2[0] = %i \t v2[1] = %i \t v2[2] = %i \t v2[3] = %i \t ",  v1[0], v1[1], v1[2], v1[3],v2[0], v2[1], v2[2], v2[3]);
}
