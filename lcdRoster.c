#define MODULE_LCD_ROSTER
#include "lcdRoster.h"


void nothing(void)
{
    //do nothing
}


void lcdRosterInit(void)
{
    screenItems[0].decrementer=decrementHours;
    screenItems[0].incrementer=incrementHours;
    screenItems[0].getter=getHour;
    screenItems[0].x=4;
    screenItems[0].y=0;
    screenItems[0].screenLength=2;
    screenItems[0].previousValue=-1;
    screenItems[0].visible=1;

    screenItems[1].decrementer=decrementMinutes;
    screenItems[1].incrementer=incrementMinutes;
    screenItems[1].getter=getMinutes;
    screenItems[1].x=20;
    screenItems[1].y=0;
    screenItems[1].screenLength=2;
    screenItems[1].previousValue=-1;
    screenItems[1].visible=1;

    screenItems[2].decrementer=decrementSecond;
    screenItems[2].incrementer=incrementSecond;
    screenItems[2].getter=getSecond;
    screenItems[2].x=36;
    screenItems[2].y=0;
    screenItems[2].screenLength=2;
    screenItems[2].previousValue=-1;
    screenItems[2].visible=1;

    screenItems[3].decrementer=nothing; //touch 0 raw
    screenItems[3].incrementer=nothing;
    screenItems[3].getter=getTouch0;
    screenItems[3].x=4;
    screenItems[3].y=4;
    screenItems[3].screenLength=4;
    screenItems[3].previousValue=-1;
    screenItems[3].visible=0;

    screenItems[4].decrementer=nothing; //touch 1 raw
    screenItems[4].incrementer=nothing;
    screenItems[4].getter=getTouch1;
    screenItems[4].x=4;
    screenItems[4].y=5;
    screenItems[4].screenLength=4;
    screenItems[4].previousValue=-1;
    screenItems[4].visible=0;

    screenItems[5].decrementer=nothing; //touch 2 raw
    screenItems[5].incrementer=nothing;
    screenItems[5].getter=getTouch2;
    screenItems[5].x=4;
    screenItems[5].y=6;
    screenItems[5].screenLength=4;
    screenItems[5].previousValue=-1;
    screenItems[5].visible=0;

    screenItems[6].decrementer=nothing;
    screenItems[6].incrementer=nothing;
    //screenItems[6].getter=getBacklightTimeout;
    screenItems[6].x=4;
    screenItems[6].y=7;
    screenItems[6].screenLength=2;
    screenItems[6].previousValue=-1;
    screenItems[6].visible=1;

    screenItems[7].decrementer=nothing; //touch 0 filtered
    screenItems[7].incrementer=nothing;
    screenItems[7].getter=getFilteredTouch0;
    screenItems[7].x=40;
    screenItems[7].y=4;
    screenItems[7].screenLength=1;
    screenItems[7].previousValue=-1;
    screenItems[7].visible=1;

    screenItems[8].decrementer=nothing; //touch 1 filtered
    screenItems[8].incrementer=nothing;
    screenItems[8].getter=getFilteredTouch1;
    screenItems[8].x=40;
    screenItems[8].y=5;
    screenItems[8].screenLength=1;
    screenItems[8].previousValue=-1;
    screenItems[8].visible=1;

    screenItems[9].decrementer=nothing; //touch 2 filtered
    screenItems[9].incrementer=nothing;
    screenItems[9].getter=getFilteredTouch2;
    screenItems[9].x=40;
    screenItems[9].y=6;
    screenItems[9].screenLength=1;
    screenItems[9].previousValue=-1;
    screenItems[9].visible=1;


    screenItems[10].decrementer=displayInterfaceDecrementSchedulerStartHour;
    screenItems[10].incrementer=displayInterfaceIncrementSchedulerStartHour;
    screenItems[10].getter=displayInterfaceGetSchedulerStartHour;
    screenItems[10].x=4;
    screenItems[10].y=1;
    screenItems[10].screenLength=2;
    screenItems[10].previousValue=-1;
    screenItems[10].visible=1;

    screenItems[11].decrementer=displayInterfaceDecrementSchedulerStartMinute;
    screenItems[11].incrementer=displayInterfaceIncrementSchedulerStartMinute;
    screenItems[11].getter=displayInterfaceGetSchedulerStartMinute;
    screenItems[11].x=20;
    screenItems[11].y=1;
    screenItems[11].screenLength=2;
    screenItems[11].previousValue=-1;
    screenItems[11].visible=1;

    screenItems[12].decrementer=displayInterfaceDecrementSchedulerStartSecond;
    screenItems[12].incrementer=displayInterfaceIncrementSchedulerStartSecond;
    screenItems[12].getter=displayInterfaceGetSchedulerStartSecond;
    screenItems[12].x=36;
    screenItems[12].y=1;
    screenItems[12].screenLength=2;
    screenItems[12].previousValue=-1;
    screenItems[12].visible=1;

    screenItems[13].decrementer=displayInterfaceDecrementSchedulerPeriodHour;
    screenItems[13].incrementer=displayInterfaceIncrementSchedulerPeriodHour;
    screenItems[13].getter=displayInterfaceGetSchedulerPeriodHour;
    screenItems[13].x=4;
    screenItems[13].y=2;
    screenItems[13].screenLength=2;
    screenItems[13].previousValue=-1;
    screenItems[13].visible=1;

    screenItems[14].decrementer=displayInterfaceDecrementSchedulerPeriodMinute;
    screenItems[14].incrementer=displayInterfaceIncrementSchedulerPeriodMinute;
    screenItems[14].getter=displayInterfaceGetSchedulerPeriodMinute;
    screenItems[14].x=20;
    screenItems[14].y=2;
    screenItems[14].screenLength=2;
    screenItems[14].previousValue=-1;
    screenItems[14].visible=1;

    screenItems[15].decrementer=displayInterfaceDecrementSchedulerPeriodSecond;
    screenItems[15].incrementer=displayInterfaceIncrementSchedulerPeriodSecond;
    screenItems[15].getter=displayInterfaceGetSchedulerPeriodSecond;
    screenItems[15].x=36;
    screenItems[15].y=2;
    screenItems[15].screenLength=2;
    screenItems[15].previousValue=-1;
    screenItems[15].visible=1;

    screenItems[16].decrementer=valveDecrementDemandedOpenTime;
    screenItems[16].incrementer=valveIncrementDemandedOpenTime;
    screenItems[16].getter=valveGetDemandedOpenTime;
    screenItems[16].x=52;
    screenItems[16].y=2;
    screenItems[16].screenLength=3;
    screenItems[16].previousValue=-1;
    screenItems[16].visible=1;

    screenItems[17].decrementer=nothing;
    screenItems[17].incrementer=nothing;
    screenItems[17].getter=valveGetOpenTimer;
    screenItems[17].x=78;
    screenItems[17].y=2;
    screenItems[17].screenLength=3;
    screenItems[17].previousValue=-1;
    screenItems[17].visible=1;

}

void incrementSelected(void)
{
    screenItems[selectedItem].forceUpdate=1;

    do
    {
        selectedItem++;
        if(selectedItem>=SCREEN_ITEMS_AMOUNT)
            selectedItem=0;
    }
    while(screenItems[selectedItem].visible==0); //pomin niewidoczne elementy

    screenItems[selectedItem].forceUpdate=1;
}

void actionOnPlusButton(void)
{
    screenItems[selectedItem].incrementer();
}

void actionOnMinusButton(void)
{
    screenItems[selectedItem].decrementer();
}

void updateScreen(void)
{
    unsigned char i, x, y;
    int value;
    for(i=0;i<SCREEN_ITEMS_AMOUNT;i++)
    {
        if(screenItems[i].visible)
        {
            value=screenItems[i].getter();
            if((value!=screenItems[i].previousValue) || screenItems[i].forceUpdate)
            {
                x=screenItems[i].x;
                y=screenItems[i].y;
                lcdGoToXY(x,y);
                switch(screenItems[i].screenLength)
                {
                    case 1:
                    sprintf(strBuf,"%1d", value);
                    break;
                    case 2:
                    sprintf(strBuf,"%02d", value);
                    break;
                    case 3:
                    sprintf(strBuf,"%03d", value);
                    break;
                    case 4:
                    sprintf(strBuf,"%04d", value);
                    break;
                }
                if(selectedItem==i)  //jezeli to "podswietlony" item
                    lcdPutString(strBuf, 0xff);
                else
                    lcdPutString(strBuf, 0);
                screenItems[i].forceUpdate=0; //odswiezyles na LCD wiec wyzeruj zadanie
                screenItems[i].previousValue=value; //zapisz jaka wartosc zostala wpisana na LCD
            }
        }
    }
}
