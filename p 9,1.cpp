#include<stdio.h>

int main()
{
    char p1;
    FILE *ar;
    ar = fopen("arc.text", "w");
    if (ar != NULL)
    {
        while((p1 = getchar())!='\n')
        fputc(p1, ar);
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}