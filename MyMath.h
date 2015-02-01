#include <stdint.h>

#ifndef MODULE_MY_MATH

extern uint32_t divide(uint32_t dividend, uint32_t divisor);
extern unsigned char MyMathBcdToByte(unsigned char bcd);
extern unsigned char MyMathByteToBcd(unsigned char i);
extern void MyMathIncrement24(char * input);
extern void MyMathDecrement24(char * input);
extern void MyMathIncrement60(char * input);
extern void MyMathDecrement60(char * input);

#endif


#ifdef MODULE_MY_MATH

uint32_t divide(uint32_t dividend, uint32_t divisor);
unsigned char MyMathBcdToByte(unsigned char bcd);
unsigned char MyMathByteToBcd(unsigned char i);
void MyMathIncrement24(char * input);
void MyMathDecrement24(char * input);
void MyMathIncrement60(char * input);
void MyMathDecrement60(char * input);

#endif