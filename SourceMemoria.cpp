#include "HeaderMemoria.h"
extern "C" void* edata;

int main() {
    // Punto 1
    std::cout << "Suma: " << (void*)(&Suma) << std::endl;
    std::cout << "Main: " << (void*)(&main) << std::endl;
    std::cout << "Contenido de etext: " << (void*)(&etext) << std::endl;

    //Punto 2
    int32_t var = 42;
    std::cout << "Dirección de edata: " << &edata << std::endl;
    std::cout << "Dirección de var: " << &var << std::endl;
    static int32_t varGlobal = 23;
    std::cout << "Dirección de varGlobal: " << &varGlobal << std::endl;

    //Punto 3
    std::cout << "El valor de end es: " << &end << std::endl;
    return 0;
}