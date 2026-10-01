// 
// Smpl_GPIO_LED4_macro : GPC12 ~ 15 to control on-board LEDs
//                        low-active output to control Red LEDs
//
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"


#define RGB_BLUE 	12
#define RGB_RED 	13
#define RGB_GREEN 14

// Initial GPIO pins (GPC 12,13,14,15) to Output mode  
void Init_LED()
{
	DrvGPIO_Open(E_GPA, RGB_BLUE, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, RGB_RED, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPA, RGB_GREEN, E_IO_OUTPUT);
	
	
	DrvGPIO_SetBit(E_GPA, RGB_BLUE);
	DrvGPIO_SetBit(E_GPA, RGB_RED);
	DrvGPIO_SetBit(E_GPA, RGB_GREEN);
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
	int i;
	UNLOCKREG();			   // unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz (PLL with 12MHz crystal input)
	LOCKREG();				   // lock register from programming

  Init_LED();        // Initialize LEDs (four on-board LEDs below LCD panel)

	while (1)				   // forever loop to keep flashing four LEDs one at a time
	{
	  for (i = 0; i < 8; ++i)	 {
			RGB_LED(i);
			DrvSYS_Delay(500000);
		}
	}
}















