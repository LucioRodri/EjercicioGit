#include "Header.h"
/*
1-a) Realizar un programa que pida ingresar por teclado los coeficientes de un polinomio de grado 2 y que a travez
	 de una funcion imprima en pantalla cuantas raices reales tiene el polinomio
			int cant_roots(int a, int b, int c);
	# Se debe crear un archivo header.h donde se guardaran los prototipos de las funciones, includes y defines
	  a usar de ser necesarios
	# Se debe crear un archivo main.c donde se codificara el programa y un archivo funciones.c donde se guardaran
	  las funciones necesarias
*/
int cant_roots(int a, int b, int c)
{
	int determinante = (b * b) - (4 * a * c);
	if (determinante == 0)
	{
		std::cout << "Tiene una raiz real doble\n";
		return 1;
	}
	if (determinante > 0)
	{
		std::cout << "Tiene dos raices reales\n";
		return 2;
	}
	else
	{
		std::cout << "No tiene raices reales\n";
		return 0;
	}
}