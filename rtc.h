#include <stdio.h>
#include <stdlib.h>
#include <p24FJ64GB004.h>
#include <Rtcc.h>
#include "MyMath.h"


#ifndef MODULE_RTC

extern void RtcInit(void);
extern void incrementHours(void);
extern void decrementHours(void);
extern int getHour(void);
extern void incrementMinutes(void);
extern void decrementMinutes(void);
extern int getMinutes(void);
extern void incrementSecond(void);
extern void decrementSecond(void);
extern int getSecond(void);



#endif

#ifdef MODULE_RTC

void RtcInit(void);
void incrementHours(void);
void decrementHours(void);
int getHour(void);
void incrementMinutes(void);
void decrementMinutes(void);
int getMinutes(void);
void incrementSecond(void);
void decrementSecond(void);
int getSecond(void);


#endif