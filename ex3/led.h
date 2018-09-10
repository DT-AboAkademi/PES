#ifndef _LED_H
#define _LED_H

#include <msp430.h>

#define LEDSTAT_OFF 0
#define LEDSTAT_ON 1
#define LEDSTAT_BLINK 2

#define RED_LED 1
#define GREEN_LED 2

#define LED_OFF 0
#define LED_ON 1


void Led_Init();
void Led_Update();
void Led_Set(tByte Led, tByte state);

#endif