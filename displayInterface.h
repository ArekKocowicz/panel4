#include "scheduler.h"
#include <stdio.h>
#include <stdlib.h>
#include <Rtcc.h>

#ifndef MODULE_DISPLAY_INTERFAFE

extern int displayInterfaceGetSchedulerStartHour(void);
extern void displayInterfaceIncrementSchedulerStartHour(void);
extern void displayInterfaceDecrementSchedulerStartHour(void);
extern int displayInterfaceGetSchedulerStartMinute(void);
extern void displayInterfaceIncrementSchedulerStartMinute(void);
extern void displayInterfaceDecrementSchedulerStartMinute(void);
extern int displayInterfaceGetSchedulerStartSecond(void);
extern void displayInterfaceIncrementSchedulerStartSecond(void);
extern void displayInterfaceDecrementSchedulerStartSecond(void);
extern int displayInterfaceGetSchedulerPeriodHour(void);
extern void displayInterfaceIncrementSchedulerPeriodHour(void);
extern void displayInterfaceDecrementSchedulerPeriodHour(void);
extern int displayInterfaceGetSchedulerPeriodMinute(void);
extern void displayInterfaceIncrementSchedulerPeriodMinute(void);
extern void displayInterfaceDecrementSchedulerPeriodMinute(void);
extern int displayInterfaceGetSchedulerPeriodSecond(void);
extern void displayInterfaceIncrementSchedulerPeriodSecond(void);
extern void displayInterfaceDecrementSchedulerPeriodSecond(void);

#endif


#ifdef MODULE_DISPLAY_INTERFAFE

int displayInterfaceGetSchedulerStartHour(void);
void displayInterfaceIncrementSchedulerStartHour(void);
void displayInterfaceDecrementSchedulerStartHour(void);
int displayInterfaceGetSchedulerStartMinute(void);
void displayInterfaceIncrementSchedulerStartMinute(void);
void displayInterfaceDecrementSchedulerStartMinute(void);
int displayInterfaceGetSchedulerStartSecond(void);
void displayInterfaceIncrementSchedulerStartSecond(void);
void displayInterfaceDecrementSchedulerStartSecond(void);
int displayInterfaceGetSchedulerPeriodHour(void);
void displayInterfaceIncrementSchedulerPeriodHour(void);
void displayInterfaceDecrementSchedulerPeriodHour(void);
int displayInterfaceGetSchedulerPeriodMinute(void);
void displayInterfaceIncrementSchedulerPeriodMinute(void);
void displayInterfaceDecrementSchedulerPeriodMinute(void);
int displayInterfaceGetSchedulerPeriodSecond(void);
void displayInterfaceIncrementSchedulerPeriodSecond(void);
void displayInterfaceDecrementSchedulerPeriodSecond(void);

#endif