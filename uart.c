#define MODULE_UART
#include <p24FJ64GB004.h>

char uartTXBuf[8];   //characters to send
char uartTXLen=0;    //number of character to send
char uartTXInd=0;    //number of already send characters

void uartSetup(void)
{
    AD1PCFGLbits.PCFG12=1;      //digital
    TRISCbits.TRISC3=0;         //output

    RPOR9bits.RP19R=3;          //RP19 as UART1 TX
    U1MODEbits.UARTEN=1;        //enable=1
    U1MODEbits.BRGH=1;          //faster bauds enabled
    U1BRG=34;                   //56kbaud
    U1STAbits.UTXEN=1;          //transmitter nabled
    IFS0bits.U1TXIF=0;          //clear interrupt flag
    IEC0bits.U1TXIE=1;          //enable interrupts
}

void _ISR _U1TXInterrupt(void)
{
    IFS0bits.U1TXIF=0;
    if(uartTXInd<uartTXLen)
    {
        U1TXREG=uartTXBuf[uartTXInd];
        uartTXInd++;
    }
    else
    {
        uartTXInd=0;
        uartTXLen=0;
    }
}

void uartSendStr(char * string)
{
    char a=0;

    uartTXLen=0;
    while(*string!='\0')            //count and copy to buffer
    {
        uartTXBuf[a]=*string;
        string++;
        a++;
        uartTXLen++;
    }
    uartTXInd=0;
    U1TXREG=uartTXBuf[0];
    uartTXInd++;
}