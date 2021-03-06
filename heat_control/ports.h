#ifndef _PORTS_H
#define _PORTS_H

#include <msp430.h>

#define RED_LED 1
#define GREEN_LED 2

#define LED1_PORT P1OUT
#define LED1_DIR P1DIR
#define LED1BIT (0x1)

#define LED2_PORT P1OUT
#define LED2_DIR P1DIR
#define LED2BIT BIT6

#define SWITCH1_DIR P1DIR
#define SWITCH1_IN P1IN
#define SWITCH1_BIT (1<<3)


#endif