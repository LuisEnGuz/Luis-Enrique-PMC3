#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
main() //32-126
{
	char frase[100];//declara cadena de caracteres
	int key;//
	int i,salto=0;
 
	while(1)
	{
		system("cls");
		printf("Ingresa la frase a cifrar: ");
		gets(frase); //scanf("%s",frase);
		do{
			printf("Inserisci la chiave di cifratura: ");
			scanf("%d",&key);
		}while(key<1 || key>10);
		printf("\n\n----------------------------------\nFrase cifrata:\n");
 
		for(i=0; i<strlen(frase); i++,salto=0)//se abre un bucle for cuyo limite es la longitud de la frase
		{
			if(frase[i]>126-key)
			{
				salto=95;
			}
			printf("%c",frase[i]+key-salto);//se imprime el valor cambiado caracter por caracter al restar el salto
		}
 
		printf("\n\n");
		system("pause");// comando para ordenar al sistema como si fuera la terminal, en este caso detiene el programa hasta que se presione una tecla
	}
}
