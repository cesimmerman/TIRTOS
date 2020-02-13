//*****************************************************************************
// setup.h
// Author: Chad Simmerman
// Date: 2/13/202
// Lab 6: TIRTOS
// Class: EE 4930
// Description: Setup TIRTOS
//****************************************************************************

/* XDC module Headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Mailbox.h>

#include <ti/drivers/Board.h>
#define __MSP432P401R__
#include "msp.h"
#include "msoe_lib_all.h"
#include <stdio.h>

#define NUMMSGS         3       /* Number of messages */
#define TIMEOUT         12      /* Timeout value */
#define CLKPERIOD       1000    /* Timeout and Clk Period Value */
#define VOLTAGE         4.5
#define LIGHT 43
#define MED 45
#define DARK 48

#define TASKSTACKSIZE   512
#define HWI_SOURCE 40

typedef struct MsgObj {
    Int         id;             /* Writer task id */
    Char        val;            /* Message value */
} MsgObj, *Msg;

void hwiFxn(UArg arg);
void swiFxn(UArg arg);
void lcdUpdate(UArg arg0, UArg arg1);
void handleStuff(UArg arg0, UArg arg1);
void hwiFunc(void);
void clk0Fxn (UArg arg);
void updateLCD(int value);
void initLCD(void);

void initHWI(void);
void initClk(void);
void initSWI(void);
void initTASK(void);

Task_Struct task0Struct;
Task_Struct task1Struct;

Char task0Stack[TASKSTACKSIZE];
Char task1Stack[TASKSTACKSIZE];

Task_Params tp1;
Task_Params tp2;

Task_Handle task0;
Task_Handle task1;

Event_Struct evtStruct;
Event_Handle myEvent1;
Event_Handle myEvent2;

Swi_Handle swi;
Swi_Params swiParams;

Hwi_Handle hwi0;
Hwi_Params hwiParams;
Error_Block eb;

Clock_Struct clk0Struct, clk1Struct;
Clock_Handle myClock;

Clock_Params clkParams;

float ADCvalue;
int reading;
int samesamebutnotdifferent = 0;
