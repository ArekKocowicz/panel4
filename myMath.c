#define MODULE_MY_MATH
#include "myMath.h"

uint32_t divide(uint32_t dividend, uint32_t divisor)
{
    uint8_t i;
    uint32_t remainder;

    if (divisor == 0)
        return (0);

    remainder = 0;
    for (i = 0; i < (sizeof(uint32_t)*8); i++)
    {
        remainder <<= 1;
        remainder += (dividend >> ((sizeof(uint32_t)*8) - 1)) & 1;
        dividend <<= 1;
        if (remainder >= divisor)
            remainder -= divisor;
    }
    return remainder;
}

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