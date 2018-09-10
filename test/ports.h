#include <msp430.h>				

#define LED1 BIT0
#define LED2 BIT6
#define LED1_PORT P1OUT
#define LED2_PORT P1OUT
#define LED1_DIR P1DIR
#define LED2_DIR P1DIR

#define SWITCH1 BIT3
#define SWITCH1_PORT P1OUT
#define SWITCH1_READ P1IN
#define SWITCH1_REN P1REN
#define SWITCH1_DIR P1DIR
