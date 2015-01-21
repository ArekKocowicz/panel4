#ifndef MODULE_ADC

extern void enableADC(void);
extern void disableADC(void);
extern int readADC(char channel);
extern void sampleADC(char channel);

#endif
#ifdef MODULE_ADC

void enableADC(void);
void disableADC(void);
int readADC(char channel);
void sampleADC(char channel);

#endif