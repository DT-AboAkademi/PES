#include "ports.h"

void SetupTimer();
void StartTimer();

__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void); 


