#include<stdio.h>

int main()
{
    int i, j, n, mat;
    float cal;
    FILE *ar;
    printf("\nIngrese  el numero de alumnos: ");
    scanf("%d", &n);
    if ((ar = fopen("arc.text","w")) != NULL)
    {
            fprintf(ar, "%d", n);
        for(i=0; i<n; i++)
        {
            printf("ingrese matricula del alumno", i+1);
            scanf("%i", &mat);
            fprintf(ar, "%i", mat);
            for (j=0; j<5; j++)
            {
                printf("\nCalificacion %d:", j+1);
                scanf("%.2f", cal);
                fprintf(ar, "%.2f", cal);
            }
        }
        fclose(ar);
    }
    else
    printf("No se puede abrir el archivo");
}