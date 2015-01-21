#define MODULE_DOGM128

#include <p24FJ64GB004.h>
#include "dogm128.h"
#include "font.h"

void spiSendByte(char myByte)
{
    char i;
    LCD_CS1B_SET_LOW(); //select LCD
    for(i=0;i<8;i++)    //send 8 bits
    {
        if(myByte&(1<<8))
            LCD_SI_SET_HIGH();
        else
            LCD_SI_SET_LOW();
        LCD_SCL_SET_LOW(); //send clock tick
        LCD_SCL_SET_HIGH();
        myByte<<=1;        //shift
    }
    LCD_CS1B_SET_HIGH();
}

void lcdSendCommand(char command)
{
    LCD_A0_SET_LOW();
    spiSendByte(command);
}

void lcdSendData(char data)
{
    LCD_A0_SET_HIGH();
    spiSendByte(data);
}

void lcdGoToXY(char x, char y)
{
    char set[] = {0xb0, 0x10, 0x00};
    set[0] = set[0] + y;                //Y - Position auf Steuerbefehl addieren
    set[2] = set[2] + (x & 0x0f);       //Low - Nibble auf Steuerbefehl addieren
    set[1] = set[1] + (x >> 4);         //High - Nibble auf Steuerbefehl addieren
    lcdSendCommand(set[0]);
    lcdSendCommand(set[1]);
    lcdSendCommand(set[2]);
}

void lcdPutChar(char newChar, char mode)
{
    unsigned char a;
    for(a=0;a<6;a++)
        lcdSendData((font[newChar][a])^mode);
}


//lcdPutString zwraca liczbe wyswietlonych znakow
char lcdPutString(char *string, char mode)
{
    char displayedCharactersNumber=0;
    while(*string!='\0')
    {
        lcdPutChar(*string, mode);
        string++;
        displayedCharactersNumber++;
    }
    return displayedCharactersNumber;
}

void lcdClear(char x)
{
    unsigned char a,b;
    for(b=0;b<8;b++)
    {
        lcdGoToXY(4,b);
        for(a=0;a<128;a++)
            lcdSendData(x);
    }
}

void lcdInitSPI(void)
{
    TRISC &= ~((1<<6)|(1<<7)|(1<<8)|(1<<9)); //LCD controll as output
    TRISB &= ~(1<<9);

    LCD_CS1B_SET_HIGH();
    LCD_SCL_SET_HIGH();
    LCD_nRST_SET_LOW(); //reset LCD
}

void lcdInitLCD(void)
{
    LCD_nRST_SET_HIGH();// LCD should be ready
    lcdSendCommand(0x40);
    lcdSendCommand(0xA0);
    lcdSendCommand(0xC8);
    lcdSendCommand(0xA6);
    lcdSendCommand(0xA2);
    lcdSendCommand(0x2F);
    lcdSendCommand(0xF8);
    lcdSendCommand(0x00);
    lcdSendCommand(0x27);
    lcdSendCommand(0x81);
    lcdSendCommand(0x08);
    lcdSendCommand(0xAC);
    lcdSendCommand(0x00);
    lcdSendCommand(0xAF);
}