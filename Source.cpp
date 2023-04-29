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

    delete[] raices;
    return 0;
}