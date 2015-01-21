#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Rtcc.h>
#include "MyMath.h"

#ifndef SCHEDULER_TYPEDEF_GUARD
#define	SCHEDULER_TYPEDEF_GUARD

typedef struct
{
    char hour;
    char min;
    char sec;
}scheduler_hour_t;

typedef struct
{
    scheduler_hour_t start;           //this is starting time
    scheduler_hour_t period;          //this is period in which action will be scheduled
}scheduler_item_t;

#endif


#ifndef MODULE_SCHEDULER

extern scheduler_item_t schedulerItem;

extern int schedulerGetItemStatus(scheduler_item_t item, rtccTimeDate now);
extern void schedulerInit(void);




#endif


#ifdef MODULE_SCHEDULER

scheduler_item_t schedulerItem;

uint32_t divide(uint32_t dividend, uint32_t divisor);
int schedulerGetItemStatus(scheduler_item_t item, rtccTimeDate now);
void schedulerInit(void);


#endif
