#include<stdio.h>

void main()
{
    int i, num, cue=0;
    int arre[100];
    for (i = 0; i < 100; i++)
    {
        printf ("Ingrese el elemento %d del arreglo: ", i + 1);
        scanf ("%i", &arre[i]);
    }
    printf("\n\nIngrese el numero que va a buscar del arreglo ");
    scanf ("%i",&num);
    for (i = 0; i < 100; i++)
    {
        if (arre[i] == num)
        {
            cue++;
        }
    printf("\n\nEl %i se encuentra %i de veces en el arreglo ", num, cue);
}