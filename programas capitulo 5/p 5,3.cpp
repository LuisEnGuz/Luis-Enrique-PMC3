#include<stdio.h>

int main()
{
    int x = 3, y = 7, z[5] = {2, 3, 4, 6, 8};
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);
    int *ix;
    ix = &x;
    y = *ix;
    *ix = 1;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    ix = &z[2];
    y = *ix;
    *ix = 15;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    x = *ix + 5;
    *ix = *ix - 5;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);
    ++*ix;
    *ix += 1;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    x = *(ix + 1);
    y = *ix;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    ix = ix + 1;
    y = *ix;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    ix = ix + 4;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);

    ix = &x;
    ix = ix + 1;
    x = *ix;
    printf("\nX %i \t Y = %d \t Z[0] = %i \t Z[1] = %i \t Z[2] = %i \t Z[3] = %i \t Z[4] = %i \t", x, y, z[0], z[1], z[2], z[3], z[4]);
}