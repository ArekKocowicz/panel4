#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rtc.h"
#include "touch.h"
#include "scheduler.h"
#include "displayInterface.h"
#include "dogm128.h"
#include "valve.h"

#ifndef LCD_ROSTER_TYPEDEF_GUARD
#define LCD_ROSTER_TYPEDEF_GUARD

typedef struct
{
    int (*getter)(void);
    int previousValue;
    char forceUpdate;
    char visible;
    void (*incrementer)(void);
    void (*decrementer)(void);
    char x;
    char y;
    char screenLength;
}screen_item_t;

#endif

#ifndef MODULE_LCD_ROSTER

extern screen_item_t screenItems[SCREEN_ITEMS_AMOUNT];
extern void lcdRosterInit(void);
extern void incrementSelected(void);
extern void actionOnPlusButton(void);
extern void actionOnMinusButton(void);
extern void updateScreen(void);


#endif

#ifdef MODULE_LCD_ROSTER

screen_item_t screenItems[SCREEN_ITEMS_AMOUNT];
unsigned char selectedItem=0;
char strBuf[16];

void nothing(void);
void lcdRosterInit(void);
void incrementSelected(void);
void actionOnPlusButton(void);
void actionOnMinusButton(void);
void updateScreen(void);


#endif