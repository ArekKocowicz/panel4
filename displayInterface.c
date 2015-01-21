#define MODULE_DISPLAY_INTERFAFE
#include "displayInterface.h"

int displayInterfaceGetSchedulerStartHour(void)
{
    return (schedulerItem.start.hour);
}

void displayInterfaceIncrementSchedulerStartHour(void)
{
    MyMathIncrement24(&(schedulerItem.start.hour));
}

void displayInterfaceDecrementSchedulerStartHour(void)
{
    MyMathDecrement24(&(schedulerItem.start.hour));
}

int displayInterfaceGetSchedulerStartMinute(void)
{
    return (schedulerItem.start.min);
}

void displayInterfaceIncrementSchedulerStartMinute(void)
{
    MyMathIncrement60(&(schedulerItem.start.min));
}

void displayInterfaceDecrementSchedulerStartMinute(void)
{
    MyMathDecrement60(&(schedulerItem.start.min));
}

int displayInterfaceGetSchedulerStartSecond(void)
{
    return (schedulerItem.start.sec);
}

void displayInterfaceIncrementSchedulerStartSecond(void)
{
    MyMathIncrement60(&(schedulerItem.start.sec));
}

void displayInterfaceDecrementSchedulerStartSecond(void)
{
    MyMathDecrement60(&(schedulerItem.start.sec));
}

int displayInterfaceGetSchedulerPeriodHour(void)
{
    return (schedulerItem.period.hour);
}

void displayInterfaceIncrementSchedulerPeriodHour(void)
{
    MyMathIncrement24(&(schedulerItem.period.hour));
}

void displayInterfaceDecrementSchedulerPeriodHour(void)
{
    MyMathDecrement24(&(schedulerItem.period.hour));
}

int displayInterfaceGetSchedulerPeriodMinute(void)
{
    return (schedulerItem.period.min);
}

void displayInterfaceIncrementSchedulerPeriodMinute(void)
{
    MyMathIncrement60(&(schedulerItem.period.min));
}

void displayInterfaceDecrementSchedulerPeriodMinute(void)
{
    MyMathDecrement60(&(schedulerItem.period.min));
}

int displayInterfaceGetSchedulerPeriodSecond(void)
{
    return (schedulerItem.period.sec);
}

void displayInterfaceIncrementSchedulerPeriodSecond(void)
{
    MyMathIncrement60(&(schedulerItem.period.sec));
}

void displayInterfaceDecrementSchedulerPeriodSecond(void)
{
    MyMathDecrement60(&(schedulerItem.period.sec));
}