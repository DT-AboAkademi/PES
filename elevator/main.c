//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.2|-->LED
//
//  J. Stevenson
//  Texas Instruments, Inc
//  July 2011
//  Built with Code Composer Studio v5
//***************************************************************************************

#include <msp430.h>

#include "eos.h"
#include "blink.h"
#include "uart.h"
#include "sensors.h"

tByte gState=0x7a;
extern const tByte gMode;


int main(void) {

  WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

  SetupBlink();
  UART_Init();
  S_Init();  // Initialize sensor systems
  //SetupSwitch();

  SCH_Init();

  SCH_AddTask(BlinkLed, 0, 200);
  SCH_Addtask(S_Pressure, 0, 500);

  SCH_Start();

  while(1) {

    SCH_Dispatch();
    }

  return 0;
}
