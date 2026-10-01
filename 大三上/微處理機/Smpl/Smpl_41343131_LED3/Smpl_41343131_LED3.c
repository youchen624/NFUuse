#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

#define DELAY(x) DrvSYS_Delay(x)
// #define ms(t) (1000*(t))

#define RGB_BLUE 	12
#define RGB_RED 	14
#define RGB_GREEN 13

// REAL DELAY w/ interpurt
void delay_pro(int ms, E_DRVGPIO_PORT port, int itpru_pin) {
	int i;
	for (i = 0; i < ms * 1000; ++i) {
		if (!DrvGPIO_GetBit(port, itpru_pin)) {
			while (DrvGPIO_GetBit(port, itpru_pin));
		}
		DELAY(1);
	}
}

// REAL DELAY
void delay(int ms) {
	int i;
	for (i = 0; i < ms; ++i) {
		DELAY(1000);
	}
}

void Init_LED()
{
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, RGB_RED, E_IO_OUTPUT);
	
	DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
	
	
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	/*
	DrvGPIO_ClrBit(E_GPA, RGB_BLUE);
	DrvGPIO_ClrBit(E_GPA, RGB_RED);
	DrvGPIO_ClrBit(E_GPA, RGB_GREEN);
	*/
}

void LED(int i) {
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	
	if (i == 0)
		DrvGPIO_ClrBit(E_GPC, 12);
	else if (i == 1)
		DrvGPIO_ClrBit(E_GPC, 13);
	else if (i == 2)
		DrvGPIO_ClrBit(E_GPC, 14);
	else if (i == 3)
		DrvGPIO_ClrBit(E_GPC, 15);
}
void RGB_LED(int i) {
	if (i & 0x01)
		DrvGPIO_SetBit(E_GPA, RGB_BLUE);
	else
		DrvGPIO_ClrBit(E_GPA, RGB_BLUE);
	
	if (i & 0x02)
		DrvGPIO_SetBit(E_GPA, RGB_RED);
	else
		DrvGPIO_ClrBit(E_GPA, RGB_RED);
	
	if (i & 0x04)
		DrvGPIO_SetBit(E_GPA, RGB_GREEN);
	else
		DrvGPIO_ClrBit(E_GPA, RGB_GREEN);
}


int main (void)
{
	int i = 0;
	int L_LED = 0x07;
	UNLOCKREG();			   // unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz (PLL with 12MHz crystal input)
	LOCKREG();				   // lock register from programming

  Init_LED();        // Initialize LEDs (four on-board LEDs below LCD panel)

	while (1)				   // forever loop to keep flashing four LEDs one at a time
	{
		// BLUE
		L_LED = 0x06; i = 0;
		while(1) {
			if (i >= 500) {
				i = 0;
				if (L_LED == 0x06) L_LED = 0x07;
				else L_LED = 0x06;
			}
			RGB_LED(L_LED);
			delay(1);
			if (!DrvGPIO_GetBit(E_GPB, 15)) {
				DELAY(4000);
				while (!DrvGPIO_GetBit(E_GPB, 15));
				break;
			}
			++i;
		}
		// GREEN
		L_LED = 0x03; i = 0;
		while(1) {
			if (i >= 500) {
				i = 0;
				if (L_LED == 0x03) L_LED = 0x07;
				else L_LED = 0x03;
			}
			RGB_LED(L_LED);
			delay(1);
			if (!DrvGPIO_GetBit(E_GPB, 15)) {
				DELAY(4000);
				while (!DrvGPIO_GetBit(E_GPB, 15));
				break;
			}
			++i;
		}

		// RED
		L_LED = 0x05; i = 0;
		while(1) {
			if (i >= 500) {
				i = 0;
				if (L_LED == 0x05) L_LED = 0x07;
				else L_LED = 0x05;
			}
			RGB_LED(L_LED);
			delay(1);
			if (!DrvGPIO_GetBit(E_GPB, 15)) {
				DELAY(4000);
				while (!DrvGPIO_GetBit(E_GPB, 15));
				break;
			}
			++i;
		}
	}
}