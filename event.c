//*****************************************************************************
// event.h
// Author: Chad Simmerman
// Date: 2/13/202
// Lab 6: TIRTOS
// Class: EE 4930
// Description: Get basic RTOS up and running to update the LCD with a setpoint
//****************************************************************************
#include "setup.h"

int main()
{
    initLCD();
    initTASK();
    initClk();
    initHWI();
    initSWI();
    Board_init();
    __enable_interrupts();
    BIOS_start();

    while(1);
}

/**
 * clk0Fxn - Runs every time the timer has a timeout
 * Really just starts
 */
void clk0Fxn (UArg arg)
{
   //printf("Starting ADC\r\n");
   ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC| ADC14_CTL0_ON;  // enable and start conversion
}

/**
 * swiFxn - Runs when triggered by the HWI
 * Pulls the value from the adc conversion in mem[0] and passes it to the task
 */
void swiFxn(UArg arg)
{
    ADCvalue = ADC14->MEM[0];
    reading = ((double)ADCvalue/102.375) + 50.0;
    Event_post(myEvent1, Event_Id_00);
}

/**
 * hwiFxn - Runs when the adc isr handler would run
 * initiates the swi interrupt
 */
void hwiFxn(UArg arg)
{
    //printf("Inside hwiFxn\r\n");
    if(ADC14->IV == 12)
    {
        ADC14->MEM[0];
        Swi_post(swi);
    }
}

/**
 * lcdUpdate Task -> Runs constantly and forever checking for pending events
 */
void lcdUpdate(UArg arg0, UArg arg1)
{
    UInt events;
    while(1)
    {

        events = Event_pend(myEvent2, Event_Id_NONE, Event_Id_00, BIOS_WAIT_FOREVER);
        if(events && 2)
        {
            if(reading != samesamebutnotdifferent)
            {
                samesamebutnotdifferent = reading;
                updateLCD(reading);
                //printf("Update LCD\r\n");
            }

        }
    }
}

void handleStuff(UArg arg0, UArg arg1)
{
    UInt events;
    while(1)
    {
        //printf("TASK0\r\n");
        events = Event_pend(myEvent1, Event_Id_NONE, Event_Id_00, BIOS_WAIT_FOREVER);
        if(events && 1)
        {
            Event_post(myEvent2, Event_Id_00);
            //printf("Inside handleStuff\r\n");
        }
    }
}

void updateLCD(int value)
{
    LCD_clear();
    LCD_home();
    LCD_print_str("Setpt:    F");
    LCD_goto_xy(6,0);
    LCD_print_udec3(value);

}

/**
 * Configures LCD Settings with a blank screen
 */
void initLCD(void)
{
    LCD_Config();
    LCD_contrast(DARK);
    LCD_clear();
    return;
}


/**
 * Initialize HWI
 */
void initHWI(void)
{
    Error_init(&eb);
    Hwi_Params_init(&hwiParams);

    hwiParams.arg = 5;
    /* ID Is the interrupt number ie if adc normally nvic 24, so id will be 24 + 16 = 40 */
    hwi0 = Hwi_create(HWI_SOURCE, hwiFxn, &hwiParams, &eb);
    if (hwi0 == NULL) {
        System_abort("Hwi create failed");
    }

    P4->SEL0 |= 0x07;
    P4->SEL1 &= ~0x07;
    ADC14->CTL0 |= ADC14_CTL0_SHT0_5 | ADC14_CTL0_SHP | ADC14_CTL0_SSEL_4 | ADC14_CTL0_ON;
    ADC14->CTL1 = 0;
    ADC14->CTL1 |= ADC14_CTL1_RES__12BIT;  // 12-bit conversion
    ADC14->MCTL[0] |= ADC14_MCTLN_INCH_6;  // input on A6
    ADC14->IER0 |= ADC14_IER0_IE0;  // enable interrupt

    NVIC->ISER[0] |=(1<<24);    // enable interrupt for ADC
    Hwi_enable();
}

/**
 * Initializes SWI
 */
void initSWI(void)
{
    Swi_Params_init(&swiParams);
    swi = Swi_create((Swi_FuncPtr)swiFxn, &swiParams, &eb);
    if(swi == NULL) {
        System_abort("Swi create failed");
    }

     myEvent1 = Event_create(NULL, NULL);
     myEvent2 = Event_create(NULL, NULL);

}

/**
 * Initializes the Task
 */
void initTASK(void)
{
    Task_Params_init(&tp2);
    tp2.stackSize = 1024;
    tp2.priority = 1;
    task1 = Task_create((Task_FuncPtr)handleStuff, &tp2, NULL);
    if(task1 == NULL)
    {
        System_abort("Task0 Create Failed");
    }

    Task_Params_init(&tp1);
    tp1.stackSize = 1024;
    tp1.priority = 5;
    task0 = Task_create((Task_FuncPtr)lcdUpdate, &tp1, NULL);
    if(task0 == NULL)
    {
        System_abort("Task0 Create Failed");
    }
}

/**
 * Initialize Clock
 */
void initClk(void)
{
    Clock_Params_init(&clkParams);
    clkParams.period = CLKPERIOD;
    clkParams.startFlag = TRUE;
    myClock = Clock_create(clk0Fxn, CLKPERIOD, &clkParams, &eb);
    if (myClock == NULL)
    {
        printf("Clock Create Failed");
    }
}
