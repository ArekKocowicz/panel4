#define MODULE_RTC
#include "rtc.h"

void RtcInit(void)
{
   mRtcc_Clear_Intr_Status_Bit;
   RtccInitClock();       								//turn on clock source
   RtccWrOn();
   mRtccSetInt(1);
   
   rtccTimeDate RtccTimeDate;
   RtccTimeDate.f.hour = MyMathByteToBcd(20);								//Set Hour
   RtccTimeDate.f.min =  MyMathByteToBcd(0);								//Set minute
   RtccTimeDate.f.sec =  MyMathByteToBcd(0);								//Set second
   RtccTimeDate.f.mday = MyMathByteToBcd(1);							//Set day
   RtccTimeDate.f.mon =  MyMathByteToBcd(1);							//Se month
   RtccTimeDate.f.year = MyMathByteToBcd(15); 							//set year
   RtccTimeDate.f.wday = MyMathByteToBcd(4);

   RtccWriteTimeDate(&RtccTimeDate,1);				//write into registers
   
   RtccSetAlarmRpt(RTCC_RPT_SEC,1);				//Set the alarm repeat period
   RtccSetAlarmRptCount(10,0);					//set alarm repeat count
   RtccSetChimeEnable(TRUE,0);
   mRtccOn();							//enable the rtcc
   mRtccAlrmEnable();
}

void incrementHours(void)
{
    rtccTimeDate time;
    char hour;

    RtccReadTimeDate(&time);
    hour=MyMathBcdToByte(time.f.hour);
    MyMathIncrement60(&hour);
    time.f.hour=MyMathByteToBcd(hour);
    RtccWriteTimeDate(&time,FALSE);
}


void decrementHours(void)
{
    rtccTimeDate time;
    char hour;

    RtccReadTimeDate(&time);
    hour=MyMathBcdToByte(time.f.hour);
    MyMathDecrement60(&hour);
    time.f.hour=MyMathByteToBcd(hour);
    RtccWriteTimeDate(&time,FALSE);
}

int getHour(void)
{
    rtccTimeDate time;

    RtccReadTimeDate(&time);
    return (MyMathBcdToByte(time.f.hour));
}

void incrementMinutes(void)
{
    rtccTimeDate time;
    char minute;

    RtccReadTimeDate(&time);
    minute=MyMathBcdToByte(time.f.min);
    MyMathIncrement60(&minute);
    time.f.min=MyMathByteToBcd(minute);
    RtccWriteTimeDate(&time,FALSE);
}

void decrementMinutes(void)
{
    rtccTimeDate time;
    char minute;

    RtccReadTimeDate(&time);
    minute=MyMathBcdToByte(time.f.min);
    MyMathDecrement60(&minute);
    time.f.min=MyMathByteToBcd(minute);
    RtccWriteTimeDate(&time,FALSE);
}

int getMinutes(void)
{
    rtccTimeDate time;

    RtccReadTimeDate(&time);
    return(MyMathBcdToByte(time.f.min));
}

void incrementSecond(void)
{
    rtccTimeDate time;
    char second;

    RtccReadTimeDate(&time);
    second=MyMathBcdToByte(time.f.sec);
    MyMathIncrement60(&second);
    time.f.sec=MyMathByteToBcd(second);
    RtccWriteTimeDate(&time,FALSE);
}

void decrementSecond(void)
{
    rtccTimeDate time;
    char second;

    RtccReadTimeDate(&time);
    second=MyMathBcdToByte(time.f.sec);
    MyMathDecrement60(&second);
    time.f.sec=MyMathByteToBcd(second);
    RtccWriteTimeDate(&time,FALSE);
}

int getSecond(void)
{
    rtccTimeDate time;

    RtccReadTimeDate(&time);
    return(MyMathBcdToByte(time.f.sec));
}
