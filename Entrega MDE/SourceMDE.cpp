/*
2) Realizar una rutina de antirrebote con estados de PULSADO y SUELTO.
4) Agregar a la rutina anterior el estado de MANTENIDO.
*/

volatile uint32_t SysTicks = 0;
extern volatile uint32_t SysTicks;
volatile uint8_t timeout;
volatile int pulsado;
estados_blinky estados;

typedef enum {
	PULSADO,
	SUELTO,
	MANTENIDO
}estados_blinky;

//FUNCION DE INTERRUPCION DE SYSTICK
void SysTick_Handler(void)
{
	SysTicks++;
	return;
}

void init(void)
{
	estados = PULSADO;
	timeout = 0;
	return;
}

void mde(void)
{
	switch (estados)
	{
	case PULSADO:
		if (timeout == 1)
		{
			if (GetPIN(KEYXpresso2, 1) == 0)     //Pregunta si el pulsador está presionado
			{
				presionado = 1;     //La variable cambia de valor
			}
			if (GetPIN(KEYXpresso2, 1) == 1 && presionado == 1)
			{
				//Realiza la acción deseada
				presionado = 0;
				estados = PRESIONADO;
				timeout = 0;
			}
			
		}
		break;
	case PRESIONADO: //no necesitaria un antirrebote si es el estado PRESIONADO
		if (timeout == 1 && estados == PULSADO)
		{
			estados = SUELTO;
			timeout = 0;
		}
		if (timeout == 1 && estados == SUELTO)
		{
			estados = PULSADO;
			timeout = 0;
		}
		break;
	case SUELTO:
		if (timeout == 1)
		{
			if (GetPIN(KEYXpresso2, 1) == 1)     //Pregunta si el pulsador está presionado
			{
				presionado = 1;     //La variable cambia de valor
			}
			if (GetPIN(KEYXpresso2, 1) == 0 && presionado == 1)
			{
				//Realiza la acción deseada
				presionado = 0;
				estados = MANTENIDO;
				timeout = 0;
			}
		}
		break;
	default:
		init();
		break;
	}

	return;

}

int main(void)
{
	init();
	while (1)
	{
		mde();
	}
	return 0;
}