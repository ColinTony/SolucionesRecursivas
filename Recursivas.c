
/*
	Libreria ? : Recursivas
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se define las funciones para solucionar el problema
	de manera recursiva. 
*/

#include <stdio.h>
#include "Presentacion.h"
#include "Recursivas.h"
#include "Dibujar.h"
/*
	void Hanoi(int n, char comienzo, char aux, char fin,int *p,int *cont,int m)
	
	Descripcion y recibe : La funcion Hanoi recibiendo n=Problema de T. de Hanoi de tamaño n,comienzo=Palo inicio (A),aux=Palo auxiliar (B),fin=Palo final(c),
	p=Un arreglo de los 3 palos que ayuda a saber la cantidad de discos con los que cuentan cada palo,cont=Apuntador a entero
	que ayuda a saber cuantas instrucciones ha impreso el programa y asi poderlas mapear & m=Numero de disco total del problema original

	Observacion : Ninguna, parece que funciona de manera correcta aunque no he intentando con numeros muy grandes y verificar que el dibujo 
	se realice de manera correcta
*/
void Hanoi(int n, char comienzo, char aux, char fin,int *p,int *cont,int m)
{
	if (n==1)
	{
		MoverCursor(0,m+3+(*cont));	(*cont)++;
		printf ("Mover de torre %c a torre %c", comienzo, fin);
		p[comienzo=='A'?0:(comienzo=='B'?1:2)]=p[comienzo=='A'?0:(comienzo=='B'?1:2)]-1;
		p[fin=='A'?0:(fin=='B'?1:2)]++;
		BorrarDisco(1,comienzo=='A'?0:(comienzo=='B'?1:2),p[comienzo=='A'?0:(comienzo=='B'?1:2)]+1,m);
		DibujarDisco(1,fin=='A'?0:(fin=='B'?1:2),p[fin=='A'?0:(fin=='B'?1:2)],m);
		EsperarMiliSeg(500);// Tiempo de espera en cada movimiento
	}
	else
	{
		Hanoi(n-1, comienzo, fin, aux,p,cont,m); // Volvemos a llamar a hanoi
		MoverCursor(0,m+3+(*cont));	(*cont)++;
		printf("Mover de torre %c a torre %c", comienzo, fin);
		p[comienzo=='A'?0:(comienzo=='B'?1:2)]--;
		p[fin=='A'?0:(fin=='B'?1:2)]++;
		BorrarDisco(n,comienzo=='A'?0:(comienzo=='B'?1:2),p[comienzo=='A'?0:(comienzo=='B'?1:2)]+1,m);
		DibujarDisco(n,fin=='A'?0:(fin=='B'?1:2),p[fin=='A'?0:(fin=='B'?1:2)],m);
		EsperarMiliSeg(500);// Tiempo de espera en cada movimiento
		Hanoi(n-1, aux, comienzo, fin,p,cont,m);
	}
	return;
}
/*
	void mergesort(int a[],int i,int j)
	Recibe: arreglo de enteros, inicio y final de enteros
	
	Descripcion: Esta funcion lo que hace es las llamadas recursivas de la separacion del arreglo 
	Observacion : Ninguna, parece que funciona de manera correcta aunque no he intentando con numeros muy grandes y verificar que el dibujo 
	se realice de manera correcta
*/
void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2; 				// dividimos entre dos
        mergesort(a,i,mid);        	// llamada de la izquierde
        mergesort(a,mid+1,j);    	// llamada a mergesort para los elementos de la derecha
        merge(a,i,mid,mid+1,j);    	// Ordenamos
    }
}
 /*
	void merge(int a[],int i1,int j1,int i2,int j2)
	Recibe: arreglo de enteros, inicio y final del arreglo uno e inicio y final del arreglo dos
	Descripcion: Esta funcion lo que hace es las llamadas recursivas de la separacion del arreglo
	Observacion : Ninguna, parece que funciona de manera correcta aunque no he intentando con numeros muy grandes y verificar que el dibujo 
	se realice de manera correcta
*/
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //Arreglo temporal o auxiliar
    int i,j,k;
    i=i1;    //Iniciamos la lista 1
    j=i2;    //Inicio d ela lista 2
    k=0;
    
    while(i<=j1 && j<=j2)    // Mientras tengamos elementos en ambos
    {
        if(a[i]<a[j]) // ordenamos mayor y menor
            temp[k++]=a[i++];
        else	
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //Copiamos los elementos restantes de la primer lists
        temp[k++]=a[i++];
        
    while(j<=j2)    //Copiamos los elementos restantes de la segunda lista
        temp[k++]=a[j++];
        
    //Transferimos los leementos del arreglo temporal al array a ya ordenados
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
/*
	unsigned long long int Fibonacci(long long int n, numFibo *a)
	Recibe: long long para los numeros muy grandes  , y un apuntador a la estructura numFibo
	Descripcion:  La funcion Fibonacci recibe el valor n de la sucesion que se desea calcular y un apuntador a un tipo de dato numFibo
	(el apuntador numFibo = es un arreglo donde se encuentran guiardados los valores de la sucesion desde 0 a n.)
	La funcion regresa un entero largo correspondiente con el elemento que se encuentra en el lugar n de la sucesion.
	Observacion : El numero mas grande que se puede ingresar es n = 32510 (En mi computadora aguanto hasta 32504)
*/
unsigned long long int Fibonacci(long long int n, numFibo *a)
{
	if(a[n].dispo)           // Verificamos si n esta en el arreglo  
		return a[n].num;     // Si el valor que se desea encontrar se encuentra en el arreglo simplemente retorna el valor guardado con anterioridad.
	
	else if (n==0 || n==1)   //Caso base de la recursividad
	{
		a[n].num=n;         
		a[n].dispo=TRUE;         
		return n;
	}
	else  // Comienzo del paso recursivo
	{
		 // La funcion fibonacci(n) por definicion es calculada con la suma de los 2 terminos anteriores de n, es decir Fibonacci(n)=Fibonacci(n-1)+Fibonacci(n-2)
		a[n].num= Fibonacci(n-1,a) + Fibonacci(n-2,a);   
		// Al momento de calcular un valor lo guardamos en el arreglo y le asignamos el valor de su disponibilidad para que este puede ser encontrado o llamado al querer calcular algun
		// otro valor n de la serie de Fibonacci.
		a[n].dispo=TRUE;  
		return a[n].num;
	}
}
/*
	unsigned long long int Tribonacci(long long int n, numFibo *a)
	Recibe: long long para los numeros muy grandes  , y un apuntador a la estructura numFibo
	Descripcion:  La funcion Fibonacci recibe el valor n de la sucesion que se desea calcular y un apuntador a un tipo de dato numFibo
	(el apuntador numFibo = es un arreglo donde se encuentran guiardados los valores de la sucesion desde 0 a n.)
	La funcion regresa un entero largo correspondiente con el elemento que se encuentra en el lugar n de la sucesion.
	Observacion : El numero mas grande que se puede ingresar es n = 32510 (En mi computadora aguanto hasta 32504)
*/
unsigned long long int Tribonacci(long long int n, numFibo *a)
{
	if(a[n].dispo)           // Verificamos si n esta en el arreglo
		return a[n].num;     // Si el valor que se desea encontrar se encuentra en el arreglo simplemente retorna el valor guardado con anterioridad.
	else
	{
		// Casos base
		if (n == 0 || n == 1 || n == 2)
			return 0;
		if( n == 3)
			return 1;
		else // paso recursivo
		{
			// Comenzamos paso recursivo
			a[n].num= Tribonacci(n - 1,a) + Tribonacci(n - 2,a) + Tribonacci(n - 3,a);   
			// Al momento de calcular un valor lo guardamos en el arreglo y le asignamos el valor de su disponibilidad para que este puede ser encontrado o llamado al querer calcular algun
			// otro valor n de la serie de Fibonacci.
			a[n].dispo=TRUE;  
			return a[n].num;
		}
	}
}