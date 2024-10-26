#include<stdio.h>
#include<iostream>
#include<ctype.h>
int i;
int main()
{
    int dec, cent, uni;
    char *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9; 
    char *p10, *p11, *p20, *p21, *p30, *p31, *p40, *p41, *p50, *p51, *p60, *p61, *p70, *p71, *p80, *p81, *p90, *p91;
    char *p100, *p110, *p200, *p300, *p400, *p500, *p600, *p700, *p800, *p900;
    p1= "uno";
    p2= "dos";
    p3= "tres";
    p4= "cuatro";
    p5= "cinco";
    p6= "seis";
    p7= "siete";
    p8= "ocho";
    p9= "nueve";
    p10= "diez ";
    p11= "diez y";
    p20= "veinte ";
    p21= "veinte y ";
    p30= "treinta ";
    p31= "treinta y ";
    p40= "cuarenta";
    p41= "cuarenta y ";
    p50= "cincuenta";
    p51= "cincuenta y ";
    p60= "sesenta";
    p61= "sesenta y ";
    p70= "setenta";
    p71= "setenta y ";
    p80= "ochenta";
    p81= "ochenta y ";
    p90= "noventa ";
    p91= "noventa y";
    p100= "cien ";
    p110= "ciento ";
    p200= "doscientos ";
    p300= "trescientos ";
    p400= "cuatrocientos ";
    p500= "quinientos ";
    p600= "seiscientos ";
    p700= "setecientos ";
    p800= "ochocientos ";
    p900= "novecientos ";
    printf("\nIngrese la cantidad que quiere convertir(de 1 a 999)");
    scanf("%i", &i);
    if (i>0 && i<=999)
    {
        uni= i%10; i= i/10;
        dec= i%10; i= i/10;
        cent= i%10;
                
        switch(cent)
        {
            case 1: if (dec == 0 &&uni == 0)
                printf ("%s", p100);
                else
                printf ("%s", p110);break;
            case 2: printf ("%s",p200); break;
            case 3: printf ("%s",p300); break;
            case 4: printf ("%s",p400); break;
            case 5: printf ("%s",p500); break;
            case 6: printf ("%s",p600); break;
            case 7: printf ("%s",p700); break;
            case 8: printf ("%s",p800); break;
            case 9: printf ("%s",p900); break;
        }
        switch(dec)
        {
            case 1: if (uni == 0)
                printf ("%s",p10);
                else
                printf ("%s",p11);break;
            case 2: if (uni == 0)
                printf ("%s",p20);
                else
                printf ("%s",p21);break;
            case 3: if (uni == 0)
                printf ("%s",p30);
                else
                printf ("%s",31);break;
            case 4:  if (uni == 0)
                printf ("%s",p40);
                else
                printf ("%s",p41);break;
            case 5:  if (uni == 0)
                printf ("%s",p50);
                else
                printf ("%s",p51);break;
            case 6:  if (uni == 0)
                printf ("%s",p60);
                else
                printf ("%s",p61);break;
            case 7:  if (uni == 0)
                printf ("%s",p70);
                else
                printf ("%s",p71);break;
            case 8:  if (uni == 0)
                printf ("%s",p80);
                else
                printf ("%s",p81);break;
            case 9:  if (uni == 0)
                printf ("%s",p90);
                else
                printf ("%s",p91);break;
        }
        switch(uni)
        {
            case 1: printf ("%s",p1);break;
            case 2: printf ("%s",p2); break;
            case 3: printf ("%s",p2); break;
            case 4: printf ("%s",p3); break;
            case 5: printf ("%s",p4); break;
            case 6: printf ("%s",p5); break;
            case 7: printf ("%s",p7); break;
            case 8: printf ("%s",p8); break;
            case 9: printf ("%s",p9); break;
        }
    }
    else 
    {
        printf("la cantidad ingresada es invalida");
    }
}
