//Variables externas
volatile uint32_t led_time;

//Direcciones de memoria

volatile uint32_t* PINSEL_1 = (volatile uint32_t*)0x4002C004UL; 	// - configurar entrada como GPIO
volatile uint32_t* PINSEL_4 = (volatile uint32_t*)0x4002c010UL;	// - configurar entrada como GPIO

volatile uint32_t* PINMODEO_OD_0 = (volatile uint32_t*)0x4002C068UL; 	// - configurar el modo electrico del pin
volatile uint32_t* PINMODEO_OD_2 = (volatile uint32_t*)0x4002c070UL;	// - configurar el modo electrico del pin

volatile uint32_t* FIODIR_0 = (volatile uint32_t*)0x2009C000UL;	// - configurar si es entrada (0) o salida (1)
volatile uint32_t* FIODIR_2 = (volatile uint32_t*)0x2009c040UL;	// - configurar si es entrada (0) o salida (1)

//DIR DE MEMORIA DE REGISTROS DE LECTURA/ESCRITURA DE LOS PINS:
volatile uint32_t* FIOPIN_0 = (volatile uint32_t*)0x2009C014UL;	// - configurar el estado del pin o leer el estado del pin
volatile uint32_t* FIOPIN_2 = (volatile uint32_t*)0x2009C054UL;	//

//Inicialización de perifericos
void Inicializar_KIT(void)
{
	//LED
	// quiero PONER 00 bit 12 y 13 para el P0,22
	ApagarBit(PINSEL_1, 12);
	ApagarBit(PINSEL_1, 13);
	// quiero PONER 0 el bit 22 para el P0,22
	ApagarBit(PINMODEO_OD_0, 22);
	// quiero PONER 1 el bit 22 para el P0,22
	EncenderBit(FIODIR_0, 22);
	// quiero PONER 1(OFF)/0(ON) el bit 22 para el P0,22
	InvertirBit(FIOPIN_0, 22);

	//KEY
	// quiero PONER 00 bit 20 y 21 para el P2,10
	ApagarBit(PINSEL_4, 20);
	ApagarBit(PINSEL_4, 21);
	// quiero PONER 0 el bit 22 para el P2,10
	ApagarBit(PINMODEO_OD_2, 22);
	// quiero PONER 0 el bit 10 para el P2,10
	ApagarBit(FIODIR_2, 10);
	// quiero LEER el estado del pin P2,10
	ConsultarBit(FIOPIN_2, 10);
}


//Funciones
void intercambiar_frecuencias (void)
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
		tiempo = ms_100;
		break;
	}
}

void init(void)
{
	RGB_LEDXpresso(ROJO, ON);
	tiempo = ms_100;
	return;
}

//Main
int main(void)
{
	init();
	Inicializar_KIT();
	while (1)
	{
		intercambiar_frecuencias();
	}
	return 0
}