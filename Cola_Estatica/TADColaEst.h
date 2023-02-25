/*
LIBRERIA: Cabecera de el TAD COLA ESTATICA
AUTOR: LMSG 2021
VERSION: 1.0

DESCRIPCION: TAD cola o Queue.
Estructura de datos en la que se cumple:
Los elementos se insertan en un extremo (el posterior) y 
la supresiones tienen lugar en el otro extremo (frente).

OBSERVACIONES: Hablamos de una Estructura de datos estatica cuando
se le asigna una cantidad fija de memoria para esa estructura 
antes de la ejecucion del programa.
*/

//DEFINICIONES DE CONSTANTES
#define MAX_ELEMENT 100
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	int n;
	//***
	//***
	//***
} elemento;

//Definir una cola (Se modela con una estructura que incluye un arreglo estatico de "elemento",
//de MAX_ELEMENT de longitud, asi como dos subindices para controlar el frente y final dela cola)
typedef struct cola
{
	elemento elementos[MAX_ELEMENT];
	int frente;
	int final;
	int num_elem;
} cola;

//DECLARACION DE FUNCIONES
void Initialize(cola * c);			//Inicializar cola (Initialize): Recibe una cola y la inicializa para su trabajo normal.
void Queue(cola * c, elemento e);	//Encolar (Queue): Recibe una cola y agrega un elemento al final de ella. 
elemento Dequeue(cola * c);			//Desencolar (Dequeue): Recibe una cola y remueve el elemento del frente retornandolo.
boolean Empty(cola * c);			//Es vacia (Empty): Recibe la cola y devuelve verdadero si esta esta vacia.
elemento Front(cola * c);			//Frente (Front): Recibe una cola y retorna el elemento del frente.	
elemento Final(cola * c);			//Final (Final): Recibe una cola y retorna el elemento del final.
elemento Element(cola *c, int i); 	// Recibe una cola y un numero de elemento de 1 al tamaño de la cola y retorna el elemento de esa posicion.
int Size(cola *c);					//Tamaño (Size): Retorna el tamaño de la cola
elemento Element(cola * c, int i);	//Recibe una cola y un numero de elemento de 1 al tamaño de la cola y retorna el elemento de esa posicion
void Destroy(cola * c);				//Eliminar cola (Destroy): Recibe una cola y la libera completamente.