
/*
	EQUIPO: Colin
	DESCRIPCION: Contiene el menu de los tres problemas que se deben solucionar de manera REcursiva
	el primero es un programa basado en la serie de fibonacci que calcula el numero n que corresponde a la 
	sucesion de fibonacci. Siendo n el n-esimo termino a calcular de la serie.
	El segundo se trata de la serie Tribonacci la cual es pararecida al fibonacci; solo que en esta ocacion
	se realiza la suma de los tres terminos anteriores a n.
	El tercero es la solucion a la torre de hanoi , representada de manera grafica en la consola( usando caracteres)
	el cuarto se trata del ordenamiento por mezcla o fusion , el cual se realiza el ordenamiento de numeros enteros

	OBSERVACIONES: El valor maximo de n que el programa puede recibir es n=32504 y n debe ser estrictamente mayor o igual 0 (para fibbonacci y tribonacci)
	Otra cosa que debemos resaltar es ejecutar con dos clicks la practica04.exe ya que se vera de mejor manera la torre de hanoi

	Compilacion : gcc .\Practica04.c .\Presentacion.c .\Dibujar.c .\Recursivas.c -o PRACTICA04 o ejecutar compilar.bat
*/


#include <stdio.h>
#include <stdlib.h>

#include "Presentacion.h"
#include "Recursivas.h"
#include "Dibujar.h"
// Esta funcion solo nos dira si el usuario quiere continuar en el menu o ya no
boolean isContinue()
{
	boolean isContinue = FALSE; // saber si quiere continuar en el menu 
	int opc;
	puts("\n \n \n Teclea la opcion que desees");
	printf("Deseas regresar al menu de recursividad? \n 1-.SI \n 2-.NO \n");
	scanf("%i",&opc);
	// si quisi continuar se cambia a verdaero
	if(opc == 1)
		isContinue=TRUE; // si es 1 entonces quiere continuar , si no se mantiene en FASLE

	return isContinue; // regresamos
}

int  main()
{
	int opc; 
// -------------------Variables para la torre de hanoi------------------//
// torres indices A,B,C
	char  comienzo = 'A';
	char  aux='B';
	char  fin='C';
// palos y contadores
	int n,i,j;
	int cont=1;
	int palos[3]={0,0,0};
// ---------------------------------------------------------------------//

// -------------------Variables PAra MERGESORT------------------//
	int a[30]; // usa las variables n de torre de hanoi y el contador  i;
// ---------------------------------------------------------------------// 
	
// -------------------Variables PAra Fiboonacci y Tribonnaci------------------//
	
	numFibo *numeros;	// apuntador a la estructura que guarda el long long
	long long int numero;		// numero introduccido por el usuario y ahremos uso del contador i

// ---------------------------------------------------------------------// 
	
	boolean continuar = TRUE; // sera verdadero hasta que el usuario ya no quiera

	while(continuar)
	{
		setColor(WHITE);
		// Vemos que simulacion ejecutar
		puts("\n |------------------------------< MENU DE IMPLEMENTACIONES RECURSIVAS >------------------------------| "); // puts agrega un salto de linea.
		printf("%s\n", " (1) Fibonacci \t (2) Tribonacci \t (3) Torre hanoi \t (4) Merge sort");

		scanf("%i",&opc);
		// ejecutamos la opcion seleccionada
		switch(opc)
		{
			case 1:
				// fibonacci
				puts("Ingrese el valor n termino ");
				scanf("%llu",&numero);
				// pedimos la memoria necesaria
				numeros=(numFibo*)malloc((numero+1)*sizeof(numFibo)); // de nuestra estructura numFibo
				// Comprobamos que nos hayan dado la memoria suficiente
				if(numeros==NULL)
				{
					puts("ERROR: NO SE PUDO ASIGNAR MEMORIA");
					exit(1);
				}
				for(i=0;i<=numero;i++)
					numeros[i].dispo=0; // mandamos falso
				setColor(YELLOW);
				printf ("\n Fibonacci (%llu) = %llu ", numero, Fibonacci(numero,numeros));
				
			break;
			
			case 2:
				// tribonacci
				puts("Ingrese el valor n termino ");
				scanf("%llu",&numero);
				// pedimos la memoria necesaria
				numeros=(numFibo*)malloc((numero+1)*sizeof(numFibo)); // de nuestra estructura numFibo
				// Comprobamos que nos hayan dado la memoria suficiente
				if(numeros==NULL)
				{
					puts("ERROR: NO SE PUDO ASIGNAR MEMORIA");
					exit(1);
				}
				for(i=0;i<=numero;i++)
					numeros[i].dispo=0; // mandamos falso
				setColor(CYAN);
				printf ("\n Tribonacci (%llu) = %llu ", numero, Tribonacci(numero,numeros));
				
			break;

			case 3:
				// Torre hanoi
				puts("Ingresa el numero de discos que tendra.");
				scanf("%d",&n);
				palos[0] = n; // primer posicion con el numero de discos
				// Limpiamos la pantalla para dibujar 
				BorrarPantalla();
				// dibujamos los palos vacios y el estado inicial
				InitHanoi(n);

				MoverCursor(0,n+3); // movemos cursor
				puts("MOVIMIENTOS REALIZADOS: "); // 
				EsperarMiliSeg(1000);

				// llamamos al algoritmo recursivo
				Hanoi(n, comienzo, aux, fin,palos,&cont,n);
				MoverCursor(0,n+3+cont);// movemos el cursor

			break;
			
			case 4:
				// Merge sort
				puts("Ingresa numero de elementos :");
			    scanf("%d",&n);
			    printf("Ingresa el arreglo de numeros enteros:");
			    
			    for(i=0;i<n;i++)
			        scanf("%d",&a[i]); // ingresando los elementos
			        
			    mergesort(a,0,n-1); // llamaos a mergeSort
			    
			    printf("\n Arreglo ordenado :");
			    for(i=0;i<n;i++)
			        printf("%d-",a[i]);
			break;

			default:
				puts("\n No has elegido ninguna opcion correcta");
			break;
		}

		continuar = isContinue();
	
	} // mientras el usiario quiera continuar se regresara al menu
	
	return 0;
}