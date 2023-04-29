#include "Header.h"


int main()
{
    int a, b, c, result;
    std::cout << "Ingrese el coeficiente cuadrado de su polinomio:\n";
    std::cin >> a;
    std::cout << "Ingrese el coeficiente lineal de su polinomio:\n";
    std::cin >> b;
    std::cout << "Ingrese el coeficiente independiente de su polinomio:\n";
    std::cin >> c;
    result = cant_roots(a, b, c);
    //Punto b

    double* raices = calcularRaices(a, b, c);

    if (isnan(raices[0]) || isnan(raices[1])) {
        std::cout << "No existen raices reales\n";
    }
    else if (raices[0] == raices[1]) {
        std::cout << "La raiz es: \n" << raices[0];
    }
    else {
        std::cout << "Las raices son: \n" << raices[0] << " y " << raices[1];
    }
    //Punto c
    double* raices = imaginary_value_roots(a, b, c);

    if (isnan(raices[0]) || isnan(raices[1])) {
        std::cout << "No existen raices imaginaria\n";
    }
    else {
        std::cout << "La parte real de la raiz es: \n" << raices[0];
        std::cout << "La parte imaginaria de la raiz es: \n" << raices[1];
    }

    //Punto d
    float resultado = value_depend(a, b, c, 3);
    std::cout << "El resultado del polinomio para x = 3 es: \n" << resultado;

    //Punto e
    double* raices = value_independ(a, b, c, 2);

    if (isnan(raices[0]) || isnan(raices[1])) {
        std::cout << "No existen raices reales\n";
    }
    else if (raices[0] == raices[1]) {
        std::cout << "La raiz es: \n" << raices[0];
    }
    else {
        std::cout << "Las raices son: \n" << raices[0] << " y " << raices[1];
    }

    //Punto f
    char opcion;

    while (true) {
        // Solicitar los coeficientes del polinomio
        std::cout << "Ingrese el primer coeficiente: \n";
        std::cin >> a;

        std::cout << "Ingrese el segundo coeficiente: \n";
        std::cin >> b;

        std::cout << "Ingrese el tercer coeficiente: \n";
        std::cin >> c;

        // Solicitar la opción deseada
        std::cout << "Seleccione una opción: \n";
        std::cout << "'a' - Cantidad de raíces\n";
        std::cout << "'b' - Valor de raíces\n";
        std::cout << "'c' - Valor del polinomio en x\n";
        std::cout << "'d' - Valor del polinomio en y\n";
        std::cout << "Ingrese '0' para salir\n";
        std::cin >> opcion;

        // Verificar la opción seleccionada
        switch (opcion) {
        case 'a':
            // Calcular la cantidad de raíces del polinomio
            // ...
            break;
        case 'b':
            // Calcular el valor de las raíces del polinomio
            // ...
            break;
        case 'c':
            // Calcular el valor del polinomio en un punto x
            // ...
            break;
        case 'd':
            // Calcular el valor del polinomio en un punto y
            // ...
            break;
        case '0':
            // Salir del loop
            std::cout << "Saliendo del programa...";
            return 0;
        default:
            // Opción no válida
            std::cout << "Opción no válida. Por favor, seleccione una opción válida.";
            break;
        }
    }

    delete[] raices;
    return 0;
}