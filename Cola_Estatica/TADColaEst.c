/*
IMPLEMENTACION DE LA LIBRERIA DEL TAD COLA ESTATICA (TADColaEst.h)
AUTOR: LMSG 2021
VERSION: 1.0

DESCRIPCION: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos estatica cuando
se le asigna una cantidad fija de memoria para esa estructura 
antes de la ejecucion del programa.

COMPILACION PARA GENERAR EL CODIGO OBJETO: gcc -c TADColaEst.c
*/

//LIBRERAS
#include "TADColaESt.h"
#include <stdlib.h>
#include <stdio.h>

//DEFINICION DE FUNCIONES

/*
void Initialize(cola *c);
Descripcion: Inicializar cola (Iniciar una cola para su uso)
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: El usuario a creado una cola y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(cola * c)
{
	c->frente = -1;
	c->final = -1;
	c->num_elem=0;
	return;
}

/*
void Queue(cola * c, elemento e);
Descripcion: Recibe una cola y agrega un elemento al final de ella.
Recibe: cola *c (Referencia a la cola "c" a operar) elemento e (Elemento a encolar)
Devuelve:
Observaciones: El usuario a creado una cola y ha sido inicializada y c tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Queue(cola * c, elemento e)
{
	//Si la cola esta vacia (Cambian ambos indice del frente y final)
	if (c->num_elem==0)
	{
		c->frente++;
		c->final++;
		c->elementos[c->final] = e;		
		c->num_elem++;
	}
	//Si la cola aun no se desborda (Cambia solo el indice del final)
	else if(c->num_elem<MAX_ELEMENT)
	{
		c->final++;
		c->elementos[c->final] = e;
		c->num_elem++;
	}
	//La cola se desborda (ERROR: Desbordamiento de cola)
	else
	{
		printf("\nERROR: (Queue) Desbordamiento de cola");
		exit(1);
	}	
	return;
}

/*
elemento Dequeue(cola * c);
Descripcion: Recibe una cola y devuelve el elemento que se encuentra al
frente de esta, quitandolo de la cola.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve: elemento (Elemento desencolado)
Observaciones: El usuario a creado e inicializado una cola, ademas la cola tiene 
elementos, si no es asi se genera un error y se termina el programa. (Subdesboramiento de Cola)
*/
elemento Dequeue(cola * c)
{
	elemento e;//Elemento a retornar 

	int i;
	
	//Si la cola esta vacia (Subdesbordamiento de cola)
	if(c->num_elem==0)
	{
		printf("\nERROR: (Dequeue) Subdesbordamiento de cola");
		exit(1);
	}
	//Si la cola tiene elementos
	else
	{
		//Guardar el elemento a retornar
		e = c->elementos[c->frente];
		
		//Recorrer los elementos del arreglo (Avanzar los elementos de la cola)
		for (i = c->frente; i < c->final; i++)
		{
			c->elementos[i] = c->elementos[i + 1];
		}
		
		//Restar uno al indice que indica el final de la cola
		c->final--;
		
		//Decrementar el numero de elementos en la cola
		c->num_elem--;
		
		//Si la cola queda vacia 
		if(c->num_elem==0)
		{
			Initialize(c); //Inicilizar la cola (c->frente = c->final =-1 c->num_elem=0)
		}
	}
	
	//Retornar al elemento
	return e;
}

/*
boolean Empty(cola * c);
Descripcion: Recibe una cola y TRUE si la cola esta vacia y FALSE en caso contrario
Recibe: cola *c (Referencia a la cola "c" a verificar)
Devuelve: boolean TRUE O FALSE
Observaciones: El usuario a creado una cola y la cola fue correctamente inicializada
*/
boolean Empty(cola * c)
{
	return (c->num_elem==0) ? TRUE : FALSE;
}

/*
elemento Front(cola * c);
Descripcion: Recibe una cola y devuelve el elemento que se encuentra al frente de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del frente de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Front(cola * c)
{
	return c->elementos[c->frente];
}

/*
elemento Final(cola * c);
Descripcion: Recibe una cola y devuelve el elemento que se encuentra al final de esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: elemento del final de la cola
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
tiene elementos de lo contrario devolvera ERROR. *No se modifica el TAD
*/
elemento Final(cola * c)
{
	return c->elementos[c->final];
}

/*
int Size(cola * c);
Descripcion: Recibe una cola y devuelve el numero de elemento que se encuentran en esta.
Recibe: cola *c (Referencia a la cola "c")
Devuelve: int (Tama??o de la cola)
Observaciones: El usuario a creado una cola,la cola fue correctamente inicializada, esta 
*No se modifica el TAD
*/
int Size(cola * c)
{
	return c->num_elem;
}

/*
void Element(cola * c, int i);
Descripcion: Recibe una cola y un numero de elemento de 1 al tama??o de la cola y retorna el elemento de esa posicion.
Devuelve: elemento en la posicion i de la cola
Observaciones: El numero i debera estar entre 1 y el tama??o de la cola, si esta es vacia o mas peque??a se provoca un error.
*/
elemento Element(cola * c, int i)
{
	elemento r;
	if (i>0&&i<=Size(c))
	{
		r=c->elementos[i-1];
	}
	else
	{
		printf("\nERROR: (Element) Se intenta acceder a elemento inexistente");
		exit(1);
	}
	return r;
}

/*
void Destroy(cola * c);
Descripcion: Recibe una cola y la libera completamente.
Recibe: cola *c (Referencia a la cola "c" a operar)
Devuelve:
Observaciones: La cola se destruye y se inicializa.
*/
void Destroy(cola * c)
{
	Initialize(c);	//Inicilizar la cola (c->frente = c->final =-1 c->num_elem=0)
}