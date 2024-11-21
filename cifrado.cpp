#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
main() //32-126 
{
	char frase[100];//declara cadena de caracteres
	int key;//declara variable entero
	int i,salto=0;
 
	while(1)//bucle infinito
	{
		system("cls");//borra la pantalla anterior, porque se va a repetir
		printf("Ingresa la frase a decifrar: ");//salida para usar el gets scanf s
		gets(frase); //scanf("%s",frase);
		do{
			printf("Inserisci la chiave di cifratura: ");
			scanf("%d",&key);//se ingresa el tipo de cifrado
		}while(key<1 || key>10);
		printf("\n\n----------------------------------\nFrase decifrata:\n");
 
		for(i=0; i<strlen(frase); i++,salto=0)//se abre un bucle for cuyo limite es la longitud de la frase
		{
			if(frase[i]<32+key)//utilizando la condicional se le da un salto de 95 al valor de los caracteres si reunen la condicion
			{
				salto=95;
			}
			printf("%c",frase[i]-key+salto);//se imprime el valor cambiado caracter por caracter al sumar el salto
		}
 
		printf("\n\n");
		system("pause");// comando para ordenar al sistema como si fuera la terminal, en este caso detiene el programa hasta que se presione una tecla
	}
}
