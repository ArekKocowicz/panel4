#define MODULE_ADC

#include <p24FJ64GB004.h>
#include "common.h"
#include "adc.h"


void enableADC(void)
{
    AD1CON1bits.ADON=1;
    AD1CON1bits.SSRC=0;
    AD1CON2=0;
    AD1CON3bits.ADRC=0;
    AD1CON3bits.ADCS=8;
    AD1CON3bits.SAMC=8;
}

void disableADC(void)
{
    AD1CON1bits.ADON=0;
}

int readADC(char channel)
{
    AD1CHSbits.CH0SA=channel;
    AD1CON1bits.SAMP=1;
    __delay_us(1);
    AD1CON1bits.SAMP=0;
    AD1CON1bits.DONE=1;
    while (!AD1CON1bits.DONE);   // wait to complete the conversion
    return ADC1BUF0;
}

void sampleADC(char channel)
{
    AD1CHSbits.CH0SA=channel;
    AD1CON1bits.SAMP=1;
    __delay_us(1);
}