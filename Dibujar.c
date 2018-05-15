/*
	Libreria  : Dibujar
	AUTOR: Colin Heredia Luis Antonio
	VERSIÓN: 1.0

	DESCRIPCIÓN: Se declran la funcion para dibujar las torres
	y los discos de la torre de Hanoi
*/
#include <stdio.h>
#include <windows.h>
#include "Presentacion.h"
#include "Dibujar.h"

/*
	void DibujarDisco(int n,int x,int y,int m)
	Descripción: Dibuja los discos para la representacion
	Recibe: n(tamaño del disco) , x (numero de la torre) , y(altura) , m (numero total de discos)
	Devuelve: void.
*/
void DibujarDisco(int n,int x,int y,int m)
{
	int i;
	setColor(GRAY);// Cambiamos el color de los discos
	MoverCursor((x*(m*2+1)+m+1)-n,m+3-y);
	for(i=0;i<n*2+1;i++)
		printf("%c",219);
	
}
/*
	void BorrarDisco(int n,int x,int y,int m)
	Descripción: Imprime espacios vacios en los puntos dados para borrar el disco
	Recibe: n(tamaño del disco) , x (numero de la torre) , y(altura) , m (numero total de discos)
	Devuelve: void.
*/
void BorrarDisco(int n,int x,int y,int m)
{
	int i; // contador
	MoverCursor((x*(m*2+1)+m+1)-n,m+3-y);
	for(i=0;i<n*2+1;i++)
			if(i==n)
			printf("%c",186); // imprime ║ 
			else
			printf("%c",32);// imprime un espacio Alt + 32 
		
}
/*
	void InitHanoi(int n)
	Descripción: Dibuja la posicion inicial de la torre de hanoi.
	Dibuja los palos y los discos en el palo A
	Devuelve: void.
*/
void InitHanoi(int n)
{
	int j;
	int i;

	for(j=0;j<3;j++)   //DIBUJA LOS PALOS VACIOS
		for(i=0;i<n;i++)
			{
				setColor(RED); // ponemos los palos color rojo
				MoverCursor(j*(n*2+1)+n+1,n+2-i);
				printf("%c",186); // Dibuja ║ para simular el palo
			}
			for(i=0;i<n;i++)
				DibujarDisco(n-i,0,i+1,n); //DIBUJA LOS DISCOS INCIALES EN EL PALO 'A'
}

/*
	void setColor(int valorColor)
	Descripción: Realiza Dibuja las cajeras que pidio el usuario y el nombre del super mercado
	Recibe:  int con el valor del color deseado
	Devuelve: void.
	Observaciones : En este metodo se utilizan tipos de datos de la api de Windows
*/
void setColor(int valorColor)
{
	HANDLE hOut; // No tengo idea que haga el HANDLE , busque informacion y no se como funciona.

    //La función GetStdHandle devuelve un manipulador para el dispositivo estándar de entrada, salida o error.
    hOut = GetStdHandle(STD_OUTPUT_HANDLE); // dispositivo input, output o error (hexadecimal) vmaos a manipular la salida
 	// Establece los atributos de los caracteres escritos en el búfer de la pantalla de la consola mediante la función WriteFile o WriteConsole
 	// o repetidos por la función ReadFile o ReadConsole. Esta función afecta el texto escrito después de la llamada a la función.
    SetConsoleTextAttribute(hOut,valorColor); // le mandamos el puntero hacia el valor del color
    // Descripcion los codigos para los colores
    /*
    * 0x000 son punteros para los valores de los colores
    *FOREGROUND_BLUE 0x0001  color AZUL.
	*FOREGROUND_GREEN 0x0002 color VERDE.
	*FOREGROUND_RED 0x0004	color ROJO.
	*FOREGROUND_INTENSITY 0x0008 intensidad de color.
	BACKGROUND_BLUE 0x0010	ponemos un fondo azul
	* informacion obtenida de la documentacion de Windows https://docs.microsoft.com/en-us/windows/console/char-info-str
    */
}