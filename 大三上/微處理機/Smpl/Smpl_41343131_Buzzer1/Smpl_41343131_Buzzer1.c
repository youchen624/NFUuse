//
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

#define ULL unsigned long long
#define DELAY(x) DrvSYS_Delay(x)
// #define ms(t) (1000*(t))

#define RGB_BLUE 	12
#define RGB_RED 	14
#define RGB_GREEN 13

#define BUZZER 11

// reset
void reset() {
  // turn off all
  DrvGPIO_SetBit(E_GPB, BUZZER);
  DrvGPIO_SetBit(E_GPC, 12);
  DrvGPIO_SetBit(E_GPC, 13);
  DrvGPIO_SetBit(E_GPC, 14);
  DrvGPIO_SetBit(E_GPC, 15);
  DrvGPIO_SetBit(E_GPA, RGB_BLUE);
  DrvGPIO_SetBit(E_GPA, RGB_RED);
  DrvGPIO_SetBit(E_GPA, RGB_GREEN);
};


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
  // Buzzer
  DrvGPIO_Open(E_GPB, BUZZER, E_IO_OUTPUT);
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
	
	reset();
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
	// const int RGB_LEG_cycle[] = { RED, GREEN, BLUE };
  const int song[] = {5, 5, 5, 5, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 3};

  // 24

	int i = 0;	// use for cheap-timer
  int t = 0;  // use for cheap-timer
	int count = 0;
	int state = 0;
	ULL btick_ms = 0;
	// int L_LED = 0x07;
	UNLOCKREG();			   	// unlock register for programming
  DrvSYS_Open(48000000);// set System Clock to run at 48MHz (PLL with 12MHz crystal input)
	LOCKREG();				   	// lock register from programming

  Init_PINs();        		// Initialize LEDs (four on-board LEDs below LCD panel)

	while (1)				   // forever loop to keep flashing four LEDs one at a time
	{
		state = 0;
		for (i = 0; i < 22; ++i) {
      if (state)
        DrvGPIO_SetBit(E_GPB, BUZZER);	// off
      else
        DrvGPIO_ClrBit(E_GPB, BUZZER);	// on
      // delay
      for (t = 0; t < song[i]; ++t) {
        delay(80);
      }
      state = !state;
    }
    /*
		switch(state) {
			// NONE
			case 0: {
				LED_hex(0);
				RGB_LED(NONE);
			} break;
      
			// LED runing cycle as ****
			case 1: {
				if (i >= 1200) i = 0;
				LED_4(i/300);
			} break;
      
			// RGB LED cycle
			case 2: {
				if (i >= 1500) i = 0;
				RGB_LED(RGB_LEG_cycle[i/500]);
			} break;
			
			// spc
			case 3: {
				if (i >= 1600) i = 0;
				count = i / 100;
				
				LED_hex(count);
				if (count < 10)
        RGB_LED(GREEN);
				else if (count < 15)
        RGB_LED(YELLOW);
				else
        RGB_LED(RED);
			} break;
			default: break;
		}
    
		// sw
		if (!DrvGPIO_GetBit(E_GPB, 15)) {
			delay(40); btick_ms = 0;
			while (!DrvGPIO_GetBit(E_GPB, 15)) { if (++btick_ms > 800) break; delay(1); };
			delay(40);
      
			if (btick_ms < 800) {
				// short push
				i = 0;
				if (++state > 3) state = 1;
			} else {
				// long push
				state = 0;
				LED_hex(0);
				RGB_LED(NONE);
				while (!DrvGPIO_GetBit(E_GPB, 15));
				delay(40);
			}
		} else { delay(1); };
		++i; // ticking for timer
    */
	}
}

