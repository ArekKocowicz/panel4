#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <p24FJ64GB004.h>
#include "MyMath.h"

#ifndef MODULE_VALVE

extern int valveGetOpenTimer(void);
extern int valveGetDemandedOpenTime(void);
extern void valveIncrementDemandedOpenTime(void);
extern void valveDecrementDemandedOpenTime(void);
extern char valveServeEverySecond(char bStart);

#endif

#ifdef MODULE_VALVE

uint8_t valveDemandenOpenTime=3;
uint8_t valveOpenTimer=0;

int valveGetOpenTimer(void);
int valveGetDemandedOpenTime(void);
void valveIncrementDemandedOpenTime(void);
void valveDecrementDemandedOpenTime(void);
char valveServeEverySecond(char bStart);


#endif