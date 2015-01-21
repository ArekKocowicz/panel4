#ifndef MODULE_DOGM128

extern void spiSendByte(char myByte);
extern void lcdSendCommand(char command);
extern void lcdSendData(char data);
extern void lcdGoToXY(char x, char y);
extern void lcdPutChar(char newChar, char mode);
extern char lcdPutString(char *string, char mode);
extern void lcdClear(char x);
extern void lcdInitSPI(void);
extern void lcdInitLCD(void);

#endif

#ifdef MODULE_DOGM128

#define LCD_A0_SET_HIGH() LATC|=(1<<7)
#define LCD_A0_SET_LOW() LATC&=~(1<<7)
#define LCD_nRST_SET_HIGH() LATC|=(1<<6)
#define LCD_nRST_SET_LOW() LATC&=~(1<<6)
#define LCD_CS1B_SET_HIGH() LATB|=(1<<9)
#define LCD_CS1B_SET_LOW() LATB&=~(1<<9)
#define LCD_SCL_SET_HIGH() LATC|=(1<<8)
#define LCD_SCL_SET_LOW() LATC&=~(1<<8)
#define LCD_SI_SET_HIGH() LATC|=(1<<9)
#define LCD_SI_SET_LOW() LATC&=~(1<<9)

void spiSendByte(char myByte);
void lcdSendCommand(char command);
void lcdSendData(char data);
void lcdGoToXY(char x, char y);

void lcdPutChar(char newChar, char mode);
char lcdPutString(char *string, char mode);
void lcdClear(char x);
void lcdInitSPI(void);
void lcdInitLCD(void);

#endif




