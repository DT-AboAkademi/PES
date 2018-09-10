/* switch.h */

#include "ports.h"

void SetupSwitch() {
  SWITCH1_PORT |= SWITCH1;   // Set pullup to up
  SWITCH1_DIR &= ~SWITCH1;  // Define as input
  SWITCH1_REN |=  SWITCH1; // Set pullup 
}

int IsSwitchPressed() {
  if ((SWITCH1_READ & SWITCH1) == 0) return 1;
  
  return 0;
}

int ReadSwitch() {

  if (SWITCH1_READ & SWITCH1) return 1;

  return 0;
}
				
