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

/*
* 1-c) Realizar una funcion que calcule las raices imaginarias de un polinomio de grado 2 si las tuviera
			void imaginary_value_roots(int a, int b, int c, float *real_p, float *img_p);
	# El main debera solo imprimir las raices y el tipo
	*/
double* imaginary_value_roots(int a, int b, int c)
{
	double* raices = new double[2];
	double discriminante = b * b - 4 * a * c;

	if (discriminante < 0) {
		raices[0] = (-b / (2 * a));
		raices[1] = sqrt(discriminante * -1);
	}
	else {
		raices[0] = NAN;
		raices[1] = NAN;
	}

	return raices;
}
/*
1-d) Realizar una funcion que dado un polinomio de grado 2  y el valor de una variable independiente (x) calcule el valor
	 de la variable dependiente (y) y la devuelva como parametro
			float value_depend(int a, int b, int c, int x);
			*/
float value_depend(int a, int b, int c, int x)
{
	float resultado = x * x * a + x * b + c;
	return resultado;
}

/*
1-e) Realizar una funcion que dado un polinomio de grado 2  y el valor de una variable dependiente(y) calcule el valor
	 de la variable independiente (x) y la devuelva como parametro
			float value_independ(int a, int b, int c, int y);
			*/

double* value_independ(int a, int b, int c, int y)
{
	c = c - y;
	double discriminante = b * b - 4 * a * c;
	double* raices = new double[2];

	if (discriminante > 0) {
		raices[0] = (-b + sqrt(discriminante)) / (2 * a);
		raices[1] = (-b - sqrt(discriminante)) / (2 * a);
	}

	else {
		raices[0] = NAN;
		raices[1] = NAN;
	}

	return raices;
}

/*
1-f) Hacer un programa con menu que pida ingresar por teclado los 3 coeficientes del polinomio y lo que quiere calcular
		'a' - Cantidad de racies
		'b' - Valor de racies (cuales sean)
		'c' - Valor del polinomio en x
		'd' - Valor del polinomio en y
	# El programa debe estar dentro de un loop infinito que se cortara solo si el usuario ingresa '0' o una opcion no
	  valida e informara porque se cerro.
*/
