#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    int min, max, costg;
    float gal, vg;
     float l = 3.785411784;
     printf ("ingrese el minimo de litros de consumo: ");
     scanf("%i",&min);
     printf("ingrese el maximo de  litros su consumo: ");
     scanf("%i", &max);
     printf("Ingrese el costo del galon: ");
     scanf("%i",&costg);
     if (min < max)
     {
        for (i = min; i <= max; i++)
        {
         gal = i;
         gal = (gal/l)/100;
         vg = gal * costg;
         printf("\n El precio del por kilometros es: %5.10f ",vg);

        }

     }
     else
        printf("ingrese el valor de los litros correctamente");
        return 0;
}
