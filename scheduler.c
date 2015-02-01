#define MODULE_SCHEDULER
#include "scheduler.h"



int schedulerGetItemStatus(scheduler_item_t item, rtccTimeDate now)
{
   uint32_t nowInSeconds;         //current time expressed in seconds
   uint32_t itemStartInSeconds;   //items starting time expressed in seconds
   uint32_t itemPeriodInSeconds;  //items period expressed in seconds
   uint32_t remainder;

   nowInSeconds=MyMathBcdToByte(now.f.sec)+60L*MyMathBcdToByte(now.f.min)+60L*60L*MyMathBcdToByte(now.f.hour);
   itemStartInSeconds=item.start.sec+60L*item.start.min+60L*60L*item.start.hour;
   itemPeriodInSeconds=item.period.sec+60L*item.period.min+60L*60L*item.period.hour;
   if(nowInSeconds>=itemStartInSeconds)
   {
       remainder=divide(nowInSeconds-itemStartInSeconds,itemPeriodInSeconds);
       if(remainder==0)
            return(1);
   }
   return 0;
}


void schedulerInit(void)
{
    schedulerItem.period.hour=0;
    schedulerItem.period.min=0;
    schedulerItem.period.sec=20;

    schedulerItem.start.hour=0;
    schedulerItem.start.min=0;
    schedulerItem.start.sec=0;
}


