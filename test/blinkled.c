
#include <msp430.h>				
#include "ports.h"
#include "blink.h"
#include "eos.h"

extern tByte gState;

void BlinkLed() {

    // Blink green, red off
     LED2_PORT ^= LED2;
}


void SetupBlink() {

  // Set leds to output
  LED1_DIR |= LED1;
  LED2_DIR |= LED2;

  // Led red on, led green on
  LED1_PORT &= ~LED1;
  LED2_PORT |= LED2;

}





