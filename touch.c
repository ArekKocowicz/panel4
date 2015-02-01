#define MODULE_TOUCH

#include <p24FJ64GB004.h>
#include "touch.h"
#include "adc.h"
#include "config.h"

int getTouch0(void)
{
    return(touchGetLatestRawReadout(0));
}

int getFilteredTouch0(void)
{
    return(touchGetState(0));
}

int getFilteredTouch1(void)
{
    return(touchGetState(1));
}

int getFilteredTouch2(void)
{
    return(touchGetState(2));
}

int getTouch1(void)
{
    return(touchGetLatestRawReadout(1));
}

int getTouch2(void)
{
    return(touchGetLatestRawReadout(2));
}

int readTouch(char sensorNumber)
{
    char channel;
    if(sensorNumber==0)
        channel=4;
    if(sensorNumber==1)
        channel=6;
    if(sensorNumber==2)
        channel=8;

    TRISCbits.TRISC1=0;         //T4 analog but pulled to High
    PORTCbits.RC1=1;
    AD1PCFGbits.PCFG7=0;
    TRISBbits.TRISB3=0;         //T2 analog but pulled to Low
    PORTBbits.RB3=1;
    AD1PCFGbits.PCFG5=0;
    if(sensorNumber==0)
    {
        TRISBbits.TRISB2=0;     //T1 as output
    }
    if(sensorNumber==1)
    {
        TRISCbits.TRISC0=0;     //T3 as output
    }
    if(sensorNumber==2)
    {
        TRISCbits.TRISC2=0;     //T3 as output
    }

    __delay_us(10);
    enableADC();
    sampleADC(7);        //sample VDD

    if(sensorNumber==0)
    {
        TRISBbits.TRISB2=1;  //T1 as input
        return(readADC(4));
    }
    if(sensorNumber==1)
    {
        TRISCbits.TRISC0=1;  //T3 as output
        return(readADC(6));
    }
    if(sensorNumber==2)
    {
        TRISCbits.TRISC2=1;  //T3 as output
        return(readADC(8));
    }
    //to be formaly correct there should be return here
}


void serveTouch(void)
{
    unsigned char i;
    static char bFirstCall=1;

    if(bFirstCall) //inicjalizuj bufor przesuwny przy pierwszym wywolaniu
    {
        bFirstCall=0;
        touchMaximumRawWhilePressed[0]=246;
        touchMaximumRawWhilePressed[1]=290;
        touchMaximumRawWhilePressed[2]=253;

        touchMinimumRawWhilePressed[0]=241;
        touchMinimumRawWhilePressed[1]=285;
        touchMinimumRawWhilePressed[2]=245;

        for(i=0;i<3;i++)
        {
            touchHistory[i][0]=1023;
            touchHistory[i][1]=1023;
            touchHistory[i][2]=1023;
            touchHistory[i][3]=1023;
        }
    }

    for(i=0;i<3;i++) //dla wszystkich taczsensorow
    {
        //przesun hostorie touchow
        touchHistory[i][1]=touchHistory[i][0];
        touchHistory[i][2]=touchHistory[i][1];
        touchHistory[i][3]=touchHistory[i][2];
        //dodaj najnowsza wartosc
        touchHistory[i][0]=readTouch(i);
        disableADC();
    }
}


enum touch_status_t touchGetState(unsigned char i)
{
 if(touchHistory[i][0]<touchMaximumRawWhilePressed[i] &&
    touchHistory[i][1]<touchMaximumRawWhilePressed[i] &&
    touchHistory[i][2]<touchMaximumRawWhilePressed[i] &&
    touchHistory[i][3]<touchMaximumRawWhilePressed[i] /*&&
    touchHistory[i][0]>touchMinimumRawWhilePressed[i] &&
    touchHistory[i][1]>touchMinimumRawWhilePressed[i] &&
    touchHistory[i][2]>touchMinimumRawWhilePressed[i] &&
    touchHistory[i][3]>touchMinimumRawWhilePressed[i]*/
            )
             return(TOUCH_STATUS_PRESSED);
       else
             return(TOUCH_STATUS_NOT_PRESSED);
}

int touchGetLatestRawReadout(unsigned char i)
{
    return touchHistory[i][0];
}

