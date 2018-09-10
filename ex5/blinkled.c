
#include <msp430.h>				
#include "ports.h"
#include "blink.h"
#include "eos.h"

extern tByte gState;

void BlinkLed() {


 if (gState == ERROR_SLAVE) {
    // Blink red, green of
     LED1_PORT ^= LED1;
     LED2_PORT &= ~LED2;
 } else {
    // Blink green, red off
     LED2_PORT ^= LED2;
     LED1_PORT &= ~LED1;
 }
}


void SetupBlink() {

  LED1_PORT |= LED1;
  LED2_PORT &= ~LED2;

  LED1_DIR |= LED1;
  LED2_DIR |= LED2;
  
  LED1_PORT &= ~LED1;
  LED2_PORT |= LED2;

}





