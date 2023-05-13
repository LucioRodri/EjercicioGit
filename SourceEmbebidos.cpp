#include "HeaderEmbebidos.h"
#include <iostream>

uint16_t contador = 0;

int main() {
    //Punta 1
    int16_t array1[] = { 6, 6, 3, 2, 5 };
    int16_t array2[] = { -2, 0, 1, 0, 3 };
    int32_t resultado;

    resultado = SumarArray(array1, 5);
    std::cout << "El resultado del array1 es: " << resultado << std::endl;

    resultado = SumarArray(array2, 5);
    std::cout << "El resultado del array2 es: " << resultado << std::endl;

    //Punto 5
    CuentaAcceso();
    CuentaAcceso();
    CuentaAcceso();
    contador = CuentaAcceso();

    // Imprimo valores pedidos
    std::cout << "Veces que se llamo la funcion: " << contador << std::endl;
    std::cout << "Dirección de memoria de contador_global: " << &contador << std::endl;

    return 0;
}





