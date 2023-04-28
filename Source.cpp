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
}