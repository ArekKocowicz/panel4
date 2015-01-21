#ifndef MODULE_FLOW

//extern void _ISR _CNInterrupt(void);
extern void flowInit(void);

#endif
#ifdef MODULE_FLOW

int flowCounter=0;

void _ISR _CNInterrupt(void);
void flowInit(void);

#endif