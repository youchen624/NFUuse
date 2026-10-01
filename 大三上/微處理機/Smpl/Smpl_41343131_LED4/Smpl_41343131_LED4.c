//
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

// init
void Init_PINs()
{
	// LED
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);

	// RGB LED
	DrvGPIO_Open(E_GPA, RGB_RED, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, RGB_BLUE, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, RGB_GREEN, E_IO_OUTPUT);
	
	// SW button
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

void LED_4(int i) {
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


void LED_hex(int i) {
	DrvGPIO_SetBit(E_GPC, 12);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 15);
	
	if (i & 0x01)
		DrvGPIO_ClrBit(E_GPC, 12);
	if (i & 0x02)
		DrvGPIO_ClrBit(E_GPC, 13);
	if (i & 0x04)
		DrvGPIO_ClrBit(E_GPC, 14);
	if (i & 0x08)
		DrvGPIO_ClrBit(E_GPC, 15);
}

#define GREEN 0x03
#define RED 0x05
#define BLUE 0x06
#define NONE 0x07
#define YELLOW 0x01
/**
* RGB_LED(state);
 * 0x01 YELLOW
 * 0X07 NONE
 * 0x06 BLUE
 * 0x05 RED
 * 0x03 GREEN
*/
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
	int i;
	int count = 0;
	// int L_LED = 0x07;
	UNLOCKREG();			   	// unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz (PLL with 12MHz crystal input)
	LOCKREG();				   	// lock register from programming

  Init_PINs();        		// Initialize LEDs (four on-board LEDs below LCD panel)

	while (1)				   // forever loop to keep flashing four LEDs one at a time
	{
		LED_hex(count);
		if (count < 10)
			RGB_LED(GREEN);
		else if (count < 15)
			RGB_LED(YELLOW);
		else
			RGB_LED(RED);

		// sw
		if (!DrvGPIO_GetBit(E_GPB, 15)) {
			delay(40);
			while (!DrvGPIO_GetBit(E_GPB, 15));
			delay(40);
			++count;
			if (count >= 16) count = 0;
		};
	}
}