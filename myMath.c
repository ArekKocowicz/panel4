#define MODULE_MY_MATH
#include "myMath.h"


unsigned char MyMathBcdToByte(unsigned char bcd)
{
    return ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F);
}

unsigned char MyMathByteToBcd(unsigned char i)
{
    return ((i / 10) << 4) + (i % 10);
}

void MyMathIncrement24(char * input)
{
    (*input)++;
    (*input)%=24;
}

void MyMathDecrement24(char * input)
{
    (*input)--;
    if((*input)<0)
        (*input)=23;
}

void MyMathIncrement60(char * input)
{
    (*input)++;
    (*input)%=60;
}

void MyMathDecrement60(char * input)
{
    (*input)--;
    if((*input)<0)
        (*input)=59;
}