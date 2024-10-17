#include<stdio.h>

int lectura(int [][10], int);
int calcula(int [][10], float [], int);
float mod0(int [][10], int, int);
float mod1(int [][10], int);
float mod2(int [][10], int, int);
int imprime(float [10], int);

int main()
{
    int mat[10][10], tam;
    float vec[10];
    do
    {
         printf("ingrese tamaño de la matriz: ");
        scanf("%i", &tam);
    } while (tam > 10 ||tam < 1);
    lectura(mat,tam);
    calcula(mat, vec, tam);
    imprime(vec,tam);
}
int lectura(int a[][10], int n)
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf ("\nIngrese el elemento %i %i: ", i+1, j+1);
            scanf ("%i", &a[i][j]);
        }
}
int calcula(int a[][10], float b[], int n)
{
    int i;
    for(i=0;i<n;i++)
        switch (i%3)
        {
            case 1: b[i] = mod1 (a,i);
            break;
            case 2: b[i] = mod2 (a,i,n);
            break;
            default: b[i] = mod0(a,i,n);
        }
}
float mod0(int a[][10], int m, int k)
{
    int i;
    float pro = 1.0, sum = 0.0;
    for(i=0;i<m;i++)
    {
        pro *= a[i][k];
        sum += a[i][k];
    }
    return(pro/sum);
}
float mod1(int a[][10], int m, int k)
{
    int i;
    float sum = 0.0;
    for(i=0;i<m;i++)
    {
        sum += a[i][k];
    }
    return(sum);
}
float mod2(int a[][10], int m, int k)
{
    int i;
    float pro = 1.0;
    for(i=0;i<m;i++)
    {
        pro *= a[i][k];
    }
    return(pro);
}
int imprime(float b[], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            printf ("\nElemento %i : %.2f", i,b[i]);
        }
}