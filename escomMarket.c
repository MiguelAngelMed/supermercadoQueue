//      INSTITUTO POLITÉCNICO NACIONAL
//      ESCUELA SUPERIOR DE COMPUTO - Algoritmos y Estructuras de Datos
//      Práctica 4 - TAD- Cola
//      Profesora: Sánchez García Luz María
//      Grupo: 2CM5
//      Integrantes: 
//                   -Rendón Lechuga Diego
//                   -Medina de Jesús Miguel Angel
//                   -Ramirez Inzunza Pedro Miguel 


#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "Cola_Estatica\TADColaEst.h"   //Implementacion estatica dew
//#include "Cola_Dinamica\TADColaDin.h"  //Implentacion dinamica del TAD Cola
//#include "Cola_Circular\TADColaEst.h" //Implementacion del TAD Cola de tipo cirular


//Tiempo de atención de las cajeraa en ms
#define TIEMPO_BASE 10    //Tiempo base en ms
#define TIEMPO_CAJERA1 8  //Tiempo base en ms * 8
#define TIEMPO_CAJERA2 9  //Tiempo base en ms * 9
#define TIEMPO_CAJERA3 10 //Tiempo base en ms * 10
#define TIEMPO_CAJERA4 11 //Tiempo base en ms * 11
#define TIEMPO_CAJERA5 12 //Tiempo base en ms * 12

//Tiempo de llegada de los clientes en ms
#define TIEMPO_CLIENTE 2 //Tiempo base en ms * 2

//Numero de cajeras
#define MAX_CAJERAS 5


int main(){
    
    //Declaramos un arreglo de colas para crar a cada caja del supermercado
    cola cajeras[MAX_CAJERAS];
    elemento market;
    
    //Inicializamos las colas 
    for(int i=0; i<MAX_CAJERAS; i++)
        Initialize(&cajeras[i]);
 
    unsigned int tiempo=0;
    unsigned int num_Cliente=0;
    unsigned int num_ClientesAtendidos=0;
    int fila=1;
    srand(time(NULL));

    printf("\n Bienvenido a ESCOM market \n\n");

    while (1){
        Sleep(TIEMPO_BASE);
        tiempo++;

        /*
          Si se han atendido a menos de 100 cajas las cajas deben seguir
          atendiendo.

           Las cajas deberan cerrar cuando se halla atendido al ultimo cliente
           esto se cumple cuando el numero del ultimo cliente es diferente al 
           numero del ultimo cliente atendido. 
        */
        if (num_ClientesAtendidos<=100  || num_Cliente!=num_ClientesAtendidos){
            
            printf("\n  %c ATENCION EN CAJAS %c \n",178,178);
            
            /*
               Si es tiempo de atencion en alguna de las cajas se muestra el proceso, de lo contrario
               se muestra que las cajas estan atendiendo
            */
            if( (tiempo%TIEMPO_CAJERA1 == 0) || (tiempo%TIEMPO_CAJERA2 == 0) ||
                (tiempo%TIEMPO_CAJERA3 == 0) || (tiempo%TIEMPO_CAJERA4 == 0) || (tiempo%TIEMPO_CAJERA5 == 0) ){
                //Cajera 1
                if (tiempo % TIEMPO_CAJERA1 == 0){
                    if (!Empty(&cajeras[0])){
			    	   market = Dequeue(&cajeras[0]);
			    	   printf("\n  -El cliente %d  fue atendido en la caja 1", market.n);
                       num_ClientesAtendidos++;
			        }
			        else{
			    	   printf("\n  -No hay alguien por atender en la caja 1");
			        }
                    
                }
        
                //Cajera 2
                if (tiempo % TIEMPO_CAJERA2 == 0){
                    if (!Empty(&cajeras[1])){
			    	   market = Dequeue(&cajeras[1]);
			    	   printf("\n  -El cliente %d  fue atendido en la caja 2", market.n);
                       num_ClientesAtendidos++;
			        }
			        else{
			    	   printf("\n  -No hay alguien por atender en la caja 2");
			        }
                    
                }
        
                //Cajera 3
                if (tiempo % TIEMPO_CAJERA3 == 0){	 
                    if (!Empty(&cajeras[2])){
			    	   market = Dequeue(&cajeras[2]);
			    	   printf("\n  -El cliente %d  fue atendido en la caja 3", market.n);
                       num_ClientesAtendidos++;
			        }
			        else{
			    	   printf("\n  -No hay alguien por atender en la caja 3");
			        }
                    
                }
        
                //Cajera 4
                if (tiempo % TIEMPO_CAJERA4 == 0){	 
                    if (!Empty(&cajeras[3])){
			    	   market = Dequeue(&cajeras[3]);
			    	   printf("\n  -El cliente %d  fue atendido en la caja 4", market.n);
                       num_ClientesAtendidos++;
			        }
			        else{
			    	   printf("\n  -No hay alguien por atender en la caja 4");
			        }
                    
                }
        
                //Cajera 5
                if (tiempo % TIEMPO_CAJERA5 == 0){	 
                    if (!Empty(&cajeras[4])){
			    	   market = Dequeue(&cajeras[4]);
			    	   printf("\n  -El cliente %d  fue atendido en la caja 5", market.n);
                       num_ClientesAtendidos++;
			        }
			        else{
			    	   printf("\n  -No hay alguien por atender en la caja 5");
			        }
                    
                }
            }
            else{
                printf("\nLas cajas estan atendiendo :)\n");
            }
            
            printf("\n\n");
        }
        else{
            printf("\n\n   El mercado a cerrado :)");
            printf("\n   Se atendieron a %d clientes",num_ClientesAtendidos);
            break; //rompe el ciclo while infinito para cerrar el supermercado 
        }

        



        /*Cada cierto van formandose al azar los clientes, al atender a 100 clientes
          ya no se puede formar ni un cliente más*/
        if (num_ClientesAtendidos<=100){

            if (tiempo % TIEMPO_CLIENTE == 0){
                printf("\n  %c CLIENTE ENTRANDO A CAJAS ",175);
                num_Cliente++;
                market.n = num_Cliente;

                //variable = limite inferior + rand()%(limite superior - limite inferior +1)
                fila =  1 + rand()%(5-1+1);
                Queue(&cajeras[fila-1],market);
                printf("\n      -El cliente: %d se formo en la caja numero: %d",market.n,fila);            
            }

            printf("\n\n");
        
        }
        
       

        /*
          Si es tiempo de atención de atención de alguna cajera o de llegada de un cliente
          se mostraran los clientes que estan formados en las cajas, de lo contrario se
          duplicarian las mismas salidas y no tendria sentido mostrarlo de esa manera

          El primer ciclo for recorre el arreglo de pilas y el segundo for va constultando
          los elementos dentro de las colas y así moestrar todos sus elementos.
        */ 
       if( (tiempo%TIEMPO_CAJERA1 == 0) || (tiempo%TIEMPO_CAJERA2 == 0)
            || (tiempo%TIEMPO_CAJERA3 == 0) || (tiempo%TIEMPO_CAJERA4 == 0)
            || (tiempo%TIEMPO_CAJERA5 == 0) || (tiempo % TIEMPO_CLIENTE == 0) ){
    
            printf("\n  %c ESTADO DE LAS CAJAS %c \n",176,176);
            for (int i=0; i<MAX_CAJERAS; i++){

               printf("\n -Hay %d clientes en la caja %d\n  ",Size(&cajeras[i]),i+1);
               
               for (int j=1; j <= Size(&cajeras[i]); j++){
                   market = Element(&cajeras[i],j);
                   printf(" [  %d  ] ,",market.n);
                }

            }

            printf("\n\n"); 
        }

        
        //Cuando se hallan atendido a 100 clientes no se permitira que se formen más clientes 
        if (num_ClientesAtendidos == 100)
            printf("\n :) NADIE MAS SE PUEDE FORMAR EN LAS CAJAS :)\n");
    
                
		 
	}
    
    printf("\n\n");
    system("pause");
    return 0;
}

