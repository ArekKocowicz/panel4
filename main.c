#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <p24FJ64GB004.h>
#include <Rtcc.h>
#include "config.h"
#include "clockSwitch.h"
#include "touch.h"
#include "config.h"
#include "adc.h"
#include "scheduler.h"
#include "displayInterface.h"
#include "MyMath.h"
#include "rtc.h"
#include "lcdRoster.h"

_CONFIG1(FWDTEN_OFF & GCP_OFF);
_CONFIG2(FNOSC_LPRC & PLL96MHZ_OFF & PLLDIV_DIV2 & IESO_OFF & FCKSM_CSECMD & OSCIOFNC_OFF & POSCMOD_NONE);
_CONFIG3(SOSCSEL_SOSC);
_CONFIG4(RTCOSC_SOSC);

char bTimingFlagRTC=0;
char bTimingFlagTouch=0;
enum touch_status_t previousTouchState[3];
enum touch_status_t currentTouchState;
char touchTimeSpentInThisState[3];
rtccTimeDate RtccTimeDate;
char bUpdateScreen=0;
int touchRefreshingPeriod;


char bValveBeginOpenPeriod=0;
char bBacklightOn=1;
char bValveOpen=0;

typedef enum
{
    LOCKED,
    UNLOCKING1,
    UNLOCKING2,
    UNLOCKED,
}lock_state_t;

#define T1_INTERRUPT_PERIOD_MS (50)

#define BACKLIGHT_OUTPUT_ENABLE()   (AD1PCFGbits.PCFG10=0,TRISBbits.TRISB14=0)
#define BACKLIGHT_TURN_ON()         (PORTBbits.RB14=1)
#define BACKLIGHT_TURN_OFF()        (PORTBbits.RB14=0)

#define BOOST_OUTPUT_ENABLE()       (TRISBbits.TRISB8=0)
#define BOOST_TURN_ON()             (PORTBbits.RB8=1)
#define BOOST_TURN_OFF()            (PORTBbits.RB8=0)

#define VALVE_OUTPUT_ENABLE()       (TRISAbits.TRISA10=0)
#define VALVE_TURN_ON()             (PORTAbits.RA10=1)
#define VALVE_TURN_OFF()            (PORTAbits.RA10=0)

typedef struct
{
    lock_state_t currentState;
    int milisecondsInCurrentState;
    int milisecondsSincePreviousTouchReadout;
    int milisecondsTransition;

}lock_machine_t;

lock_machine_t lockMachine={UNLOCKED, 0, 0, 0};

enum touch_status_t previousTouch[2]={TOUCH_STATUS_NOT_PRESSED, TOUCH_STATUS_NOT_PRESSED, TOUCH_STATUS_NOT_PRESSED};

void _ISR _RTCCInterrupt(void)
{
    clockSwitch(NOSC_FRCDIV);
    IFS3bits.RTCIF=0;
    bTimingFlagRTC=1;
}

void _ISR _T1Interrupt(void)
{
    clockSwitch(NOSC_FRCDIV);
    IFS0bits.T1IF=0;    //clear flag
    TMR1=0;
    bTimingFlagTouch=1;
}

int getBacklightTimeout(void)
{
    
    return lockMachine.currentState;
}

void main(void)
{
    clockSwitch(NOSC_FRCDIV);
    __builtin_write_OSCCONL(OSCCON | 0x02); // turn on SOSC
    CLKDIVbits.RCDIV=0;  //this selects by 1 prescaller for running the microcontroller from INTRC

    BOOST_OUTPUT_ENABLE();
    BOOST_TURN_ON();
    BACKLIGHT_OUTPUT_ENABLE();
    BACKLIGHT_TURN_ON();
    VALVE_OUTPUT_ENABLE();
    VALVE_TURN_OFF();

    lcdInitSPI();
    __delay_us(25000);
    lcdInitLCD();
    lcdClear(0x00);
    schedulerInit();
    RtcInit();
    lcdRosterInit();
    screenItems[6].getter=getBacklightTimeout;

    T1CONbits.TCS=1;  //timer clocked from T1CK pin (SOSC oscillator)
    T1CONbits.TCKPS=0;//no prescaler
    PR1=1600;         //SOSC is 32KHz so 1600 means that the interrupt happens every 50ms
    TMR1=0;
    IFS0bits.T1IF=0;
    IEC0bits.T1IE=1;
    T1CONbits.TON=1;
   
    //PORTBbits.RB14=1;    //backlight
    
    clockSwitch(NOSC_LPRC);
    while(1)
    {
        if(bTimingFlagTouch)
        {
            bTimingFlagTouch=0;

            lockMachine.milisecondsInCurrentState+=T1_INTERRUPT_PERIOD_MS;
            lockMachine.milisecondsSincePreviousTouchReadout+=T1_INTERRUPT_PERIOD_MS;

            if(lockMachine.currentState==UNLOCKED)
                touchRefreshingPeriod=50;
            else
                touchRefreshingPeriod=200;
            if(lockMachine.milisecondsSincePreviousTouchReadout>=touchRefreshingPeriod)   //serve touch every defined period
            {
               lockMachine.milisecondsSincePreviousTouchReadout=0;
               __delay_us(200);     //without this delay touchsensors measure wrong values, probably RC oscillator is not stable right after turning it on
               serveTouch();
               bUpdateScreen=1;
            }

            switch(lockMachine.currentState)
            {
                case LOCKED:                    
                    //BACKLIGHT_TURN_OFF();
                    bBacklightOn=0;
                    if(TOUCH_STATUS_PRESSED==touchGetState(0))
                    {
                        lockMachine.milisecondsTransition+=T1_INTERRUPT_PERIOD_MS;
                    }
                    else
                    {
                        lockMachine.milisecondsTransition=0;
                    }
                    if(lockMachine.milisecondsTransition>=2000)
                    {
                        lockMachine.milisecondsTransition=0;
                        lockMachine.currentState=UNLOCKING1;
                        lockMachine.milisecondsInCurrentState=0;
                        bUpdateScreen=1;
                    }
                break;
                case UNLOCKING1:
                    //BACKLIGHT_TURN_ON();
                    bBacklightOn=1;
                    if(lockMachine.milisecondsInCurrentState>=4000 ||
                            TOUCH_STATUS_PRESSED==touchGetState(2))
                    {
                        lockMachine.currentState=LOCKED;
                        lockMachine.milisecondsInCurrentState=0;
                    }
                    if(TOUCH_STATUS_PRESSED==touchGetState(1))
                    {
                        lockMachine.milisecondsTransition+=T1_INTERRUPT_PERIOD_MS;
                    }
                    else
                    {
                        lockMachine.milisecondsTransition=0;
                    }
                    if(lockMachine.milisecondsTransition>=2000)
                    {
                        lockMachine.currentState=UNLOCKING2;
                        lockMachine.milisecondsInCurrentState=0;
                        lockMachine.milisecondsTransition=0;
                        bUpdateScreen=1;
                    }
                break;
                case UNLOCKING2:
                    //BACKLIGHT_TURN_ON();
                    bBacklightOn=1;
                    if(lockMachine.milisecondsInCurrentState>=4000 ||
                            TOUCH_STATUS_PRESSED==touchGetState(0))
                    {
                        lockMachine.currentState=LOCKED;
                        lockMachine.milisecondsInCurrentState=0;
                    }
                    if(TOUCH_STATUS_PRESSED==touchGetState(2))
                    {
                        lockMachine.milisecondsTransition+=T1_INTERRUPT_PERIOD_MS;
                    }
                    else
                    {
                        lockMachine.milisecondsTransition=0;
                    }
                    if(lockMachine.milisecondsTransition>=2000)
                    {
                        lockMachine.currentState=UNLOCKED;
                        lockMachine.milisecondsInCurrentState=0;
                        lockMachine.milisecondsTransition=0;
                        bUpdateScreen=1;
                    }
                break;
                case UNLOCKED:
                    //BACKLIGHT_TURN_ON();
                    bBacklightOn=1;
                    if(lockMachine.milisecondsInCurrentState>=30000)
                    {
                        lockMachine.currentState=LOCKED;
                        lockMachine.milisecondsInCurrentState=0;
                    }
                    if(touchGetState(0)==TOUCH_STATUS_PRESSED && previousTouch[0]==TOUCH_STATUS_NOT_PRESSED)
                    {
                        incrementSelected();
                        lockMachine.milisecondsInCurrentState=0;
                        bUpdateScreen=1;
                    }
                    if(touchGetState(1)==TOUCH_STATUS_PRESSED && previousTouch[1]==TOUCH_STATUS_NOT_PRESSED)
                    {
                        actionOnPlusButton();
                        lockMachine.milisecondsInCurrentState=0;
                        bUpdateScreen=1;
                    }
                    if(touchGetState(2)==TOUCH_STATUS_PRESSED && previousTouch[2]==TOUCH_STATUS_NOT_PRESSED)
                    {
                        actionOnMinusButton();
                        lockMachine.milisecondsInCurrentState=0;
                        bUpdateScreen=1;
                    }
                break;
            }
            previousTouch[0]=touchGetState(0);
            previousTouch[1]=touchGetState(1);
            previousTouch[2]=touchGetState(2);

            if(bUpdateScreen)
            {
                bUpdateScreen=0;
                updateScreen();
            }
            clockSwitch(NOSC_LPRC);
        }

        if(bTimingFlagRTC)
        {
            bTimingFlagRTC=0;
            RtccReadTimeDate(&RtccTimeDate);
            if(schedulerGetItemStatus(schedulerItem,RtccTimeDate))
                bValveBeginOpenPeriod=1;
            else
                bValveBeginOpenPeriod=0;

            if(valveServeEverySecond(bValveBeginOpenPeriod)==1)
            {
                bValveOpen=1;
                //BOOST_TURN_ON();
                //VALVE_TURN_ON();
            }
            else
            {
                bValveOpen=0;
                //BOOST_TURN_OFF();
                //VALVE_TURN_OFF();
            }
            updateScreen();
            clockSwitch(NOSC_LPRC);
        }


//valve and LCB backlight are supplied from the same boost power domain so
//if valve should be open or backlight should be on boost must be enabled.

        if(bBacklightOn||bValveOpen)
            BOOST_TURN_ON();
        else
            BOOST_TURN_OFF();
        if(bBacklightOn)
            BACKLIGHT_TURN_ON();
        else
            BACKLIGHT_TURN_OFF();
        if(bValveOpen)
            VALVE_TURN_ON();
        else
            VALVE_TURN_OFF();
    }
}

