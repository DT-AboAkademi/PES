#ifndef _LED_H
#define _LED_H

#include <msp430.h>

#define LEDSTAT_OFF 0
#define LEDSTAT_ON 1
#define LEDSTAT_BLINK 2

void Led_Init(tWord Interval);
void Led_Update();
void Led_Setstat(tByte a);

#endif