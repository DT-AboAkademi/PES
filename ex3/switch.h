#ifndef _SWITCH_H
#define _SWITCH_H
#include <msp430.h>

#define PRESSED 1
#define NOT_PRESSED 0

void Switch_Init();
tByte Switch_GetStat();

#endif
