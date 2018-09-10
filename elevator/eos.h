#ifndef EOS_H
#define EOS_H

#include <msp430.h>

#define MASTER 0
#define SLAVE 1

#define ACK_SLAVE_OK 0x11

#define STATE_OK 0x01

#define ERROR_NOERROR 0x01
#define ERROR_SLAVE 0x10
#define ERROR_NOSLAVE 0x20


typedef unsigned int tWord;
typedef unsigned char tByte;


typedef struct {
    void (*pTask)(void);
    tWord Delay;
    tWord Repeat;
    tByte RunMe;
} sTask;

#define MAX_TASKS 5

void SCH_AddTask(void *fPtr, tWord Delay, tWord Repeat);
void SCH_Init();
void SCH_Dispatch(void);
void SCH_Update(void);
void SCH_Start(void);


#endif // EOS_H

