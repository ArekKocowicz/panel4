#ifndef MODULE_UART

extern void uartSetup(void);
extern void uartSendStr(char * string);

#endif
#ifdef MODULE_UART



void _ISR _U1TXInterrupt(void);

void uartSetup(void);
void uartSendStr(char * string);



#endif


