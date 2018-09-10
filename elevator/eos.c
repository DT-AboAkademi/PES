#include "eos.h"
#include "blink.h"

#define DCO_FREQ 1*1e6
#define TIMER_INTERVAL 10 // Given in ms

#define DIVIDER 8
#define TMRC (DCO_FREQ / DIVIDER / 1000 * TIMER_INTERVAL)


sTask gTaskList[MAX_TASKS];

tByte gErrorCode = 0;
tWord gTickCount = 0;
tWord gSlaveAckTick = 0;

extern const tByte gMode;
extern tByte gState;


void SetupTimer() {

if (gMode == MASTER) {
        BCSCTL1 = CALBC1_1MHZ;
        DCOCTL = CALDCO_1MHZ;

        // Set up interrupts and timer 0

        // Enable interrupts on timer
        CCTL0 = CCIE;

        // Use clock SMCLK, UP counting, divided of 8
        TACTL = TASSEL_2 + MC_1 + ID_3;

        // Set compare value
        CCR0 = TMRC;
} else {
}
}

void SCH_Start() {
        __enable_interrupt();
}

void SCH_AddTask(void *fPtr, tWord Delay, tWord Repeat) {
    tByte i;
    for (i=0; i<MAX_TASKS; i++) {
        if (!gTaskList[i].pTask) {
            gTaskList[i].pTask = fPtr;
            gTaskList[i].Delay = (Delay / TIMER_INTERVAL)+1;
            gTaskList[i].Repeat = (Repeat / TIMER_INTERVAL)+1;
            gTaskList[i].RunMe = 0;
            return;
        }
    }
    return;
}


void SCH_Update(void) {
    tByte idx;

    for (idx=0; idx<MAX_TASKS; idx++) {
        if (gTaskList[idx].pTask) {
            if (--gTaskList[idx].Delay==0) {
                gTaskList[idx].RunMe++;
                if (gTaskList[idx].Repeat)
                    gTaskList[idx].Delay = gTaskList[idx].Repeat;

            }
        }
    }
}

void SCH_Dispatch(void) {
    tByte idx;
    for (idx=0; idx<MAX_TASKS; idx++) {
        if (gTaskList[idx].RunMe>0) {
            (*gTaskList[idx].pTask)();
            gTaskList[idx].RunMe--;
        }
        if (gTaskList[idx].Repeat == 0) {
            // Should delete task
               // SCH_Delete_Task(idx);
        }
    }
}

void SCH_Init() {
    tByte idx;

    for(idx=0; idx<MAX_TASKS; idx++) {
       gTaskList[idx].pTask = (0);
    }

    // Initialize timer
    SetupTimer();
}

__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void) {
//    BlinkLed();
tByte Message;

gTickCount++; // Update global tickcount

if (gMode == MASTER) {
    if (gTickCount - gSlaveAckTick > 2) {
        gState = ERROR_SLAVE;
    } else {
        gState = STATE_OK;
    }
    SCH_Update();
    Message = gState;
    UART_SendByte(Message);
}

}

