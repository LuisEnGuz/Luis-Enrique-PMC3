#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//Hanoi: consiste en un juego donde movemos una cantidad de discos en tres columnas donde se forma una piramide con los discos mas grandes debajo.
/*Si aplicamos esto con 3 discos conseguiremos formar la piramide en 7 movimientos con esto podemos concluir que para determinar la cantidad de moviemientos para n cantidad de discos 
utilizamos la formula An=2A(n-1)+1*/
 void imprime( int *, int , int , int  ); //funcion que devuelve parametros de: un puntero tipo entero y tres variables tipo entero y sirve para dar forma al tablero
 void mueveDisco( int *, int , int , int , int , int  );//funcion que devuelve parametros de: un puntero tipo entero y cinco variables tipo entero y sirve para definir el movimiento de los discos en columnas
 void hanoi( int *, int , int , int , int , int , int , int  );//funcion que devuelve parametros de: un puntero tipo entero y siete variables tipo entero y define el algoritmo de hanoi
 void delay(int tiempo);//funcion que devuelve parametro de variable tipo entero y define una pausa
 
 int main()
{
    int fil=3, col, *tablero = NULL;//Declara fila teniendo el valor de 3 por las 3 torres, col que funcionaria como  numero de discos y tablero que es igual a nulo para que no tome un valor no deseado.
    int f, c, disc=1, ultNum;
 
 
    printf( "Indique el numero de discos: " );
    scanf( "%i", &col ); //se pide los discos en col
 
 
    tablero = (int *)malloc( sizeof(int)*fil*col );//con malloc se utiliza la cantidad de discos para asignar la cantidad de memoria que el puntero tablero utilizara.
 
 

    for( f=0; f < fil; f++ )//ciclo de filas
        for( c=col-1; c >= 0; c-- )//ciclo de columnas
            if( f==0 )
            {
                tablero[col*f+c] = disc;// en la primera fila va colocando los valores impares, en la memoria se puede usar tablero[fil][col] ya que se almacenan igual en la memoria, pero requiere codificar la matrix de forma mas complicada.
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;// esto significa que las demas fias estaran vacias
 
    ultNum = disc;//se le asigna el valor del disco a ultnum, el valor de disc va variando pero el de ultnumn ya que solo toma el valor de disc cuando acaba el ciclo
 

    system("cls");// se usa para limpiar la pantalla, en este caso permite que se muestre como va cambiando la piramide ya que reinicia cada vez que hace un movimiento
    imprime( tablero, fil, col, ultNum );//llama a la funcion imprime q se menciono previamente que da forma al tablero inicial y que cls muestra los cambios
    delay(6);//se llama a la funcion delay que da una pausa para que los cambios se puedan analizar a mas detalle
 
 

    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 ); //se encarga de ir reproduciendo los cambios utilizandi la formula del hanoi
};

void imprime( int *tab, int fil, int col, int ultNum )//se abre la funcion imprime
{
 
    int f, c;//declaracion de variables
    int i, esp;
 
 
    for( c=col-1; c >= 0; c-- )//ciclo columnas
    {
        for( f=0; f < fil; f++ )//ciclo filas
        {
            esp = ( ultNum - tab[col*f+c] )/2;/*el valor de ultnum va de derecha a izquierda y basicamente consiste en encontrar la diferncia entre el disco mas grande y el disco en cuestion
			se divide entre 2 para centrar el disco*/
 

            for( i=0; i < esp; i++ ) //pone espacio
                printf( " " );
 

            for( i=0; i < tab[col*f+c]; i++ )//pone disco
                printf( "*" );
 

            for( i=0; i < esp; i++ )//pone espacio nuevamente
                printf( " " );
 
            printf( "\t" );//espacio lateral
        };
 
        printf( "\n" );//espacio vertical
    };
 
 
};
 
 
void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )// abre la funcio de mover disco con dos parametros nuevos fila de origen y de destino
{

 
 
    int cO=col-1, cD=col-1;// define variables de columna de origen y destino
 
 

    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )//busca desde arriba abajo para encontrar el primer disco si la posicion es 0 decrece
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;
 

    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )// busca de arriba abajo para selecionar donde se movera el disco
    {
        cD--;
    };
 

    tab[col*filDest+cD+1] = tab[col*filOrig+cO];//iguala a co al valor de el destino con la columnna 
    tab[col*filOrig+cO] = 0;// resetea devolviendo el tablero a 0
 

    imprime( tab, fil, col, ultNum ); //imprime la torre cambiada
};
 
 
void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )//abre la funcion hanoi con 7 parametros
{
    
 
 
    if( disc==1 )//condicional con dependiendo de cuantos discos se moveran
    {

        system("cls");//limpia
        mueveDisco( tab, fil, col, ultNum, O, D );// llama a la funcion mueve disco donde filorig y fildest ahora son o y d y a funciona como la torre auxiliar
        if(col<=5) delay(4);//define las pausas dependiendo de que tan grande son las torres'
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
    }
    else
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );//mueve disc -1 a auxiliar utilizando d como auxiliar
 
        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );/*esto mueve el disco mas grande (que se va disminuyendo porque conforme vas moviendo discos tienes menos discos a mover) 
		directamente  a la torre destino y los discc-1 a la auxiliar*/
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
 
        hanoi( tab, fil, col, disc-1, ultNum, A, O, D ); //mueve disc-1 de la auxiliar a destino utilizando o como auxiliar
    };
 
};
 
void delay(int tiempo)//en resumen crea un bucle q no hace nada desperdiciando el tiempo del pc
{
 
    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }
 
}
 

