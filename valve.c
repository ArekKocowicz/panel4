#define MODULE_VALVE
#include "valve.h"


int valveGetOpenTimer(void)
{
    return(valveOpenTimer);
}

int valveGetDemandedOpenTime(void)
{
    return(valveDemandenOpenTime);
}

void valveIncrementDemandedOpenTime(void)
{
    valveDemandenOpenTime++;
}

void valveDecrementDemandedOpenTime(void)
{
    valveDemandenOpenTime--;
}

char valveServeEverySecond(char bStart)
{
    char properValveState;

    if(bStart==1)
        valveOpenTimer=0;

    if(valveOpenTimer<valveDemandenOpenTime)
    {
        properValveState=1;
        valveOpenTimer++;
    }
        
    else
        properValveState=0;
    return(properValveState);
}