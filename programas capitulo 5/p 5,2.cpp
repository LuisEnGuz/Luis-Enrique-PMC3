#include<stdio.h>

void main()
{
    int ele[5]= {0};
    int i, vot;
    printf("Ingresa el primer voto (0 - para terminar): ");
    scanf("%i",&vot);
    while (vot)
    {
        if ((vot > 0) && (vot < 6))
        ele[vot-1]++;
        else
        printf("\nEl voto ingresado es incorrecto");
        scanf("%i",&vot);
    }
    printf("\n\nResultados de la eleccion\n");
    for(i = 0; i <= 4; i++ )
    printf ("\nCandidato %i: %i", i+1, ele[i]);
}