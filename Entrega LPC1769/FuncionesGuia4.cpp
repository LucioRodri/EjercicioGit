#include "Header4.h"
//Funciones
void intercambiar_frecuencias(void)
{
	switch (tiempos)
	{
	case ms_100:
		if (GetPIN(keyxPRESSO2, 0) == 1)
		{
			tiempo = ms_300;
			led_time = 300;
		}
		break;
	case ms_300:
		if (GetPIN(keyxPRESSO2, 0) == 1)
		{
			tiempo = ms_500;
			led_time = 500;
		}
		break;
	case ms_500:
		if (GetPIN(keyxPRESSO2, 0) == 1)
		{
			tiempo = ms_1000;
			led_time = 1000;
		}
		break;
	case ms_1000:
		if (GetPIN(keyxPRESSO2, 0) == 1)
		{
			tiempo = ms_100;
			led_time = 100;
		}
		break;
	default:
		break;
	}
}

void init(void)
{
	RGB_LEDXpresso(ROJO, ON);
	tiempo = ms_100;
	return;
}