#include "HeaderEmbebidos.h"


int32_t SumarArray(int16_t* x, int16_t xn) {
    int32_t suma = 0;
    for (int i = 0; i < xn; i++) {
        suma += x[i];
    }
    return suma;
}

int16_t MultiplicarSat(int16_t n1, int16_t n2) {
    int32_t resultadoTemporal = static_cast<int32_t>(n1) * static_cast<int32_t>(n2);
    if (resultadoTemporal > SATMAX) {
        return SATMAX;
    }
    else if (resultadoTemporal < SATMIN) {
        return SATMIN;
    }
    else {
        return static_cast<int16_t>(resultadoTemporal);
    }
}

inline int16_t MultiplicarSatInline(int16_t n1, int16_t n2) {
    int32_t resultadoTemporal = static_cast<int32_t>(n1) * static_cast<int32_t>(n2);
    if (resultadoTemporal > SATMAX) {
        return SATMAX;
    }
    else if (resultadoTemporal < SATMIN) {
        return SATMIN;
    }
    else {
        return static_cast<int16_t>(resultadoTemporal);
    }
};

uint16_t CuentaAcceso() {
    static uint16_t contador = 0;
    return ++contador;
}
