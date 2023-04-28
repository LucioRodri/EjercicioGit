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

/*
* 1-b) Realizar una funcion que calcule los valores de las raices en caso de existir de un polinomio de grado 2
			void value_roots(int a, int b, int c, int cant_roots, float *root1, float *root2);
	# El main debera solo imprimir las raices y el tipo
*/

double* calcularRaices(double a, double b, double c)
{
	double* raices = new double[2];
	double discriminante = b * b - 4 * a * c;

	if (discriminante > 0) {
		raices[0] = (-b + sqrt(discriminante)) / (2 * a);
		raices[1] = (-b - sqrt(discriminante)) / (2 * a);
	}
	else if (discriminante == 0) {
		raices[0] = -b / (2 * a);
		raices[1] = raices[0];
	}
	else {
		raices[0] = NAN;
		raices[1] = NAN;
	}

	return raices;
}
