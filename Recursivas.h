/*
	LIBRERIA: Cabecera para las soluciones recursivas
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: En esta parte solo definiremos las funciones
	que usaremos para las soliciones recursivas.

	OBSERVACIONES: Cada algoritmo resuelve el problema.

*/

//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO
//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

typedef struct numFibo{                              // DEFINIMOS UNA ESTRUCTURA CON UN ENTERO LARGO CON EL FIN DE GUARDAR LOS NUMEROS DE LA SUCESION  
	unsigned long long int num;					  		// QUE VAN DE 0<=I<=n. ADEMAS USA UN BIT DE VERIFICACION.
	boolean dispo;
} numFibo;

void Hanoi(int n, char comienzo, char aux, char fin,int *p,int *cont,int m);	// Funcion recursiva de hanoi
void mergesort(int a[],int i,int j);											// MergeSort
void merge(int a[],int i1,int j1,int i2,int j2);								// merge sort
unsigned long long int Fibonacci(long long int n, numFibo *a);   				//Declaracion Funcion Fibonacci
unsigned long long int Tribonacci(long long int n, numFibo *a);   				//Declaracion Funcion Fibonacci
