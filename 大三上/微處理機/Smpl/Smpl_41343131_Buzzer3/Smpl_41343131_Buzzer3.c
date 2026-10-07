//
#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

#define ULL unsigned long long
#define DELAY(x) DrvSYS_Delay(x)
// #define ms(t) (1000*(t))

#define RGB_BLUE 12
#define RGB_RED 14
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

// REAL DELAY
void delay(int ms)
{
  int i;
  for (i = 0; i < ms; ++i)
  {
    DELAY(1000);
  }
};



/**
 * delay_pro
 * @returns {int 1|0}
 * - 1 meaning end by a button pressed;
 * - 0 meaning end by the time's up;
 */
int delay_pro(int ms) {
  while(ms--) {
    if (!DrvGPIO_GetBit(E_GPB, 15))
    {
      reset();
      delay(40);  // debouncing
      // until
      while (!DrvGPIO_GetBit(E_GPB, 15)) delay(1);
      return 1;
    }
    delay(1);
  }
  return 0;
};


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

  // reset
  reset();
}

void LED_4(int i)
{
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

void LED_hex(int i)
{
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
#define WHITE 0x00
/**
 * RGB_LED(state);
 * 0x01 YELLOW
 * 0X07 NONE
 * 0x06 BLUE
 * 0x05 RED
 * 0x03 GREEN
 */
void RGB_LED(int i)
{
  if (i & 0x01)
    DrvGPIO_SetBit(E_GPA, RGB_BLUE);  // off
  else
    DrvGPIO_ClrBit(E_GPA, RGB_BLUE);  // on

  if (i & 0x02)
    DrvGPIO_SetBit(E_GPA, RGB_RED);
  else
    DrvGPIO_ClrBit(E_GPA, RGB_RED);

  if (i & 0x04)
    DrvGPIO_SetBit(E_GPA, RGB_GREEN);
  else
    DrvGPIO_ClrBit(E_GPA, RGB_GREEN);
}

// play music-1
void sing()
{
  int i = 0;   // use for cheap-timer
  int t = 0;   // use for cheap-timer
  int t_s = 0; // user for cheap-timer
  int state = 0;
  const int song[] = {5, 5, 5, 5, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 3};

  for (i = 0; i < 22; ++i)
  {
    if (state) {
      // off
      DrvGPIO_SetBit(E_GPB, BUZZER);
      RGB_LED(RED);
    } else {
      // on
      DrvGPIO_ClrBit(E_GPB, BUZZER);
      RGB_LED(GREEN);
    }
    // delay
    for (t = 0; t < song[i]; ++t)
    {
      for (t_s = 0; t_s < 80; ++t_s)
      {
        if (!DrvGPIO_GetBit(E_GPB, 15))
        {
          reset();
          delay(40);
          while (!DrvGPIO_GetBit(E_GPB, 15)) delay(1);
          return;
        }
        delay(1);
      }
    }
    state = !state;
  }
	
  // end song
	reset();
  for (i = 0; i < 3; ++i) {
    RGB_LED(WHITE);
    if (delay_pro(500)) return;
    RGB_LED(NONE);
    if (delay_pro(500)) return;
  }
};



int main(void)
{
  // const int RGB_LEG_cycle[] = { RED, GREEN, BLUE };
  // 24

  int i = 0;   // use for cheap-timer
  int t = 0;   // use for cheap-timer
  int t_s = 0; // user for cheap-timer
  int count = 0;
  int state = 0;
  ULL btick_ms = 0;
  // int L_LED = 0x07;
  UNLOCKREG();           // unlock register for programming
  DrvSYS_Open(48000000); // set System Clock to run at 48MHz (PLL with 12MHz crystal input)
  LOCKREG();             // lock register from programming

  Init_PINs(); // Initialize LEDs (four on-board LEDs below LCD panel)

  while (1) // forever loop to keep flashing four LEDs one at a time
  {
    sing();
  }
}

