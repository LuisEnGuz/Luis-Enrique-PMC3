#include<stdio.h>
#include<string.h>

typedef struct
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
}domicilio;

struct empleado
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;
};
int lectura(struct empleado *a)
{
    printf("Ingrese el nombre del empleado:");
    scanf("%s", &(*a).nombre);
    fflush(stdin);
    printf ("ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf ("ingrese el sueldo del empleado: ");
    scanf("%f", &(*a).sueldo);
    fflush(stdin);
    printf ("ingrese la direccion del empleado: ");
    printf("\ncalle\n");
    gets(a->direccion.calle);
    printf("\nnumero\n");
    scanf("%i", &(*a).direccion.numero);
    fflush(stdin);
    printf("\ncodigo postal\n");
    scanf("%i", &a->direccion.calle);
    fflush(stdin);
    printf("\nlocalidad\n");
    gets(a->direccion.localidad);
}
int main()
{
    struct empleado e0={"arturo", "compras", 15500.75, "san Jeronimo", 120, 3490, "toluca"};

    struct empleado *e1, *e2, e3, e4;

    e1= new (struct empleado);
    printf("Ingrese el nombre del empleado:");
    scanf("%s", &(*e1).nombre);
    fflush(stdin);
    printf ("ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf ("ingrese el sueldo del empleado: ");
    scanf("%f", &(*e1).sueldo);
    fflush(stdin);
    printf ("ingrese la direccion del empleado: ");
    printf("\ncalle\n");
    gets(e1->direccion.calle);
    printf("\nnumero\n");
    scanf("%i", &(*e1).direccion.numero);
    fflush(stdin);
    printf("\ncodigo postal\n");
    scanf("%i", &e1->direccion.calle);
    fflush(stdin);
    printf("\nlocalidad\n");
    gets(e1->direccion.localidad);

    printf("Ingrese el nombre del empleado:");
    scanf("%s", &e3.nombre);
    fflush(stdin);
    printf ("ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf ("ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    fflush(stdin);
    printf ("ingrese la direccion del empleado: ");
    printf("\ncalle\n");
    gets(e3.direccion.calle);
    printf("\nnumero\n");
    scanf("%i", &e3.direccion.numero);
    fflush(stdin);
    printf("\ncodigo postal\n");
    scanf("%i", &e3.direccion.calle);
    fflush(stdin);
    printf("\nlocalidad\n");
    gets(e3.direccion.localidad);

    e2= new (struct empleado);
    lectura(e2);

    lectura(&e4);
    printf ("\nDatos del empleado 1: \n");
    printf("%d \t %s \t %s \t %.2f \t %s", e1->nombre, e1->departamento,e1->sueldo, e1->direccion.calle, e1->direccion.numero,e1->direccion.cp, e1->direccion.localidad);
    printf ("\nDatos del empleado 4: \n");
    printf("%d \t %s \t %s \t %.2f \t %s", e4.nombre, e4.departamento,e4.sueldo, e4.direccion.calle, e4.direccion.numero,e4.direccion.cp, e4.direccion.localidad);
}