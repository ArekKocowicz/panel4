#define MODULE_FLOW

#include <p24FJ64GB004.h>
#include "flow.h"

void _ISR _CNInterrupt(void)
{
    IFS1bits.CNIF=0;
    flowCounter++;
}

void flowInit(void)
{
    TRISBbits.TRISB14=0; //flow sensor input
    PORTBbits.RB14=1;
    AD1PCFGLbits.PCFG10=1;
}