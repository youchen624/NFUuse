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

/*
## 真唐 THIS IS A FALSE TABLE / FROM PPT / **SHOULD NOT TRUST**
| GPE | S | fake | real | &t | hex |
| 0 | 1 | A | g | 1 | |
| 1 | 2 | B | f | 2 | |
| 2 | 3 | C | a | 4 | |
| 3 | 4 | D | b | 8 | |
| 4 | 5 | E | e | 16 | 0x10 |
| 5 | 6 | F | d | 32 | 0x20 |
| 6 | 7 | G | c | 64 | 0x40 |
| 7 | 8 | H | p | 128 | 0x80 |

REAL REAL
1:c
2:p
4:f
8:a
16:b
32:d
64:e
128:g

REAL REAL
* --a-- *
|       |
f       b
|       |
* --g-- *
|       |
e       c
|       |
* --d-- p

3210.
*/

const unsigned char SEG_num[10] = {
    0x7D, // 0
    0x11, // 1
    0xF8, // 2
    0xB9, // 3
    0x95, // 4
    0xAD, // 5
    0xED, // 6
    0x19, // 7
    0xFD, // 8
    0xBD  // 9
};
// DO NOT USE #FAKE by PPT
int SEG_num_FUCK[] = {
    0x82, // 0
    0xEE, // 1
    0x07, // 2
    0x46, // 3
    0x6A, // 4
    0x52, // 5
    0x12, // 6
    0xE6, // 7
    0x02, // 8
    0x62, // 9
};
void SEG_on(int n, int seg)
{
  int i;
  int t = 0x01;
  for (i = 0; i < 4; ++i)
  {
    DrvGPIO_ClrBit(E_GPC, (i + 4));
  }
  DrvGPIO_SetBit(E_GPC, seg + 4);

  for (i = 0; i < 8; ++i, t *= 2)
  {
    if (SEG_num[n] & t)
      DrvGPIO_ClrBit(E_GPE, i);
    else
      DrvGPIO_SetBit(E_GPE, i);
  }
};
void SEG_off()
{
  int i;
  for (i = 0; i < 4; ++i)
  {
    DrvGPIO_ClrBit(E_GPC, (i + 4));
  }
};

// reset
void reset()
{
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
int delay_pro(int ms)
{
  while (ms--)
  {
    if (!DrvGPIO_GetBit(E_GPB, 15))
    {
      reset();
      delay(40); // debouncing
      // until
      while (!DrvGPIO_GetBit(E_GPB, 15))
        delay(1);
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
    DrvGPIO_SetBit(E_GPA, RGB_BLUE); // off
  else
    DrvGPIO_ClrBit(E_GPA, RGB_BLUE); // on

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
    if (state)
    {
      // off
      DrvGPIO_SetBit(E_GPB, BUZZER);
      RGB_LED(RED);
    }
    else
    {
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
          while (!DrvGPIO_GetBit(E_GPB, 15))
            delay(1);
          return;
        }
        delay(1);
      }
    }
    state = !state;
  }

  // end song
  reset();
  for (i = 0; i < 3; ++i)
  {
    RGB_LED(WHITE);
    if (delay_pro(500))
      return;
    RGB_LED(NONE);
    if (delay_pro(500))
      return;
  }
};

int main(void)
{
  // const int RGB_LEG_cycle[] = { RED, GREEN, BLUE };
  // 24

  const int id[] = {3, 1, 3, 1};
  // const int tttt[] = {3, 2, 1, 0};

  int i = 0;   // use for cheap-timer
  int t = 0;   // use for cheap-timer
  int t_s = 0; // user for cheap-timer
  int st = 0;  // button press-time
  int r = -1;   // rotation
  int count = 0;
  int state = 0;
  ULL btick_ms = 0;
  // int L_LED = 0x07;
  UNLOCKREG();           // unlock register for programming
  DrvSYS_Open(48000000); // set System Clock to run at 48MHz (PLL with 12MHz crystal input)
  LOCKREG();             // lock register from programming

  Init_PINs(); // Initialize LEDs (four on-board LEDs below LCD panel)
  // debounce enable (buildin)
  // DrvGPIO_SetDebounceTime(5, 1);
  // DrvGPIO_EnableDebounce(E_GPB, 15);

  while (1) // forever loop to keep flashing four LEDs one at a time
  {
    // 3131
    for (i = 0; i < 4; ++i) {
      for (t = ((r>0) ? 0:3); 0 <= t && t < 4; t += r) {
        SEG_on(id[i], t);
        // delay per state
        for (t_s = 0; t_s < 400; ++t_s) {
          if (!DrvGPIO_GetBit(E_GPB, 15)) {
            delay(10);
            while(!DrvGPIO_GetBit(E_GPB, 15)) delay(1);
            if (++st >= 2) {
              st = 0;
              r *= -1;
            }
          }
          delay(1);
        }
      }
    }
    // for (t = 0; t < 125; ++t)
    // {
      // for (i = 3; i >= 0; --i)
      // {
      //   SEG_on(id[i], i);
      //   delay(1);
      // }
    // }
    //
    // for (i = 3; i >= 0; --i)
    // {
    //   SEG_on(id[i], i);
    //   // LED_4(tttt[t]);
    //   delay(500);
    // }
    SEG_off();
    reset();
    // delay(500);
  }
}
