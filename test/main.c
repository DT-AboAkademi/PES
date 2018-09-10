
#include <msp430.h>				

#include "../eos/eos.h"
#include "../eos/uart.h"
#include "blink.h"


void WriteUart() {
    UART_Write("Hello world\r\n ");
}

int main(void) {

  WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

  SCH_Init();
  SetupBlink();
  UART_Init();

  SCH_AddTask(WriteUart, 400, 2000);
  SCH_AddTask(BlinkLed, 1000, 500);

  SCH_Start();


  //UART_Write("Started 2\n");


  while(1) {

    SCH_Dispatch();

    }

  return 0;
}
