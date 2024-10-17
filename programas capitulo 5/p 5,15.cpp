#include<stdio.h>

int main()
{
    int x = 5, y =8, v[5] ={1,3,5,7,9};
    int *ay, *ax;
    ay = &y;
    x = *ay;
    *ay = v[3], v[2];
    printf("\nX %i \t Y = %d \t v[0] = %i \t v[1] = %i \t v[2] = %i \t v[3] = %i \t v[4] = %i \t", x, y, v[0], v[1], v[2], v[3], v[4]);
    ax = &v[ v[0] * v[1]];
    x = *ax ;
    y = *ax * v[1];
    *ax = *ay - 3;
     printf("\nX %i \t Y = %d \t v[0] = %i \t v[1] = %i \t v[2] = %i \t v[3] = %i \t v[4] = %i \t", x, y, v[0], v[1], v[2], v[3], v[4]);
    

}


