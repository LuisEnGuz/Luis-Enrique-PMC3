#include<stdio.h>
#include<string>

typedef struct 
{
    char cal[20];
    int num;
    char col[20];
    char cp[5];
    char ciu[20];
}domicilio;

typedef struct 
{
    char nom[20];
    int edad;
    char sexo;
    int con;
    domicilio dom;
    char tel[10];
}paciente;

int lectura(paciente *, int);
int f1(paciente *, int);
int f2(paciente *, int);
int f3(paciente *, int);

int main()
{
    paciente hospital[100];
    int tam;
    do
    {
        printf("ingrese el tamaño del arreglo: ");
        scanf("%i", &tam);
    } 
    while (tam > 100 || tam < 1);
    lectura(hospital, tam);
    f1(hospital,tam);
    f2(hospital,tam);
    f3(hospital,tam);
}
int lectura(paciente a[], int t)
{
    int i;
    for(i=0;i<t; i++)
    {
        printf("\n\tPaciente %d:", i+1);
        fflush(stdin);
        printf("Nombre :");
        scanf("%s", &a[i].nom);
        fflush(stdin);
        printf("Edad :");
        scanf("%i", &a[i].edad);
        printf("Nombre :");
        scanf("%s", &a[i].nom);
        printf("Sexo (f-m) :");
        scanf("%c", &a[i].sexo);
        printf("Condicion (1...5) :");
        scanf("%i", &a[i].con);
        fflush(stdin);
        printf("Calle :");
        scanf("%s", &a[i].dom.cal);
        printf("Numero :");
        scanf("%d", &a[i].dom.num);
        fflush(stdin);
        printf("Colonia :");
        scanf("%s", &a[i].dom.col);
        fflush(stdin);
        printf("Codigo postal :");
        scanf("%s", &a[i].dom.cp);
        fflush(stdin);
        printf("Ciudad :");
        scanf("%s", &a[i].dom.ciu);
        fflush(stdin);
        printf("Telefono :");
        scanf("%s", &a[i].tel);
    }
}
int f1(paciente a[], int t)
{
    int i,fem, mas, tot;
    for(i=0;i<t; i++)
        switch (a[i].sexo)
        {
            case 'f': fem++;
            break;
            case 'm': mas++;
            break;
        }
        tot = fem + mas;
        printf("\nPorcentaje de hombres: %.2f%", (float) mas/tot*100);
        printf("\nPorcentaje de mujeres: %.2f%", (float) fem/tot*100); 
}
int f2(paciente a[], int t)
{
    int i, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    for(i=0;i<t; i++)
        switch (a[i].con)
        {
            case 1: c1++;
            break;
            case 2: c2++;
            break;
            case 3: c3++;
            break;
            case 4: c4++;
            break;
            case 5: c5++;
            break;
        }
        printf ("\nNumero de pacientes con la condicion 1: %d", c1);
        printf ("\nNumero de pacientes con la condicion 2: %d", c2);
        printf ("\nNumero de pacientes con la condicion 3: %d", c3);
        printf ("\nNumero de pacientes con la condicion 4: %d", c4);
        printf ("\nNumero de pacientes con la condicion 5: %d", c5);
}
int f3(paciente a[], int t)
{
    int i;
     printf ("\nPacientes en estado grave");
    for(i=0;i<t; i++)
        if(a[i].con==5)
            printf("\nNombre %s\t telefono: %s",a[i].nom, a[i].tel);
}