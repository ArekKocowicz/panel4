#ifndef TOUCH_TYPEDEF_GUARD
#define TOUCH_TYPEDEF_GUARD

enum touch_status_t
{
    TOUCH_STATUS_NOT_PRESSED,
    TOUCH_STATUS_POSSIBLE_PRESSED,
    TOUCH_STATUS_PRESSED
};

#endif


#ifndef MODULE_TOUCH




extern int getTouch0(void);
extern int getFilteredTouch0(void);
extern int getFilteredTouch1(void);
extern int getFilteredTouch2(void);
extern int getTouch1(void);
extern int getTouch2(void);

extern int readTouch(char sensorNumber);
void serveTouch(void);
extern enum touch_status_t touchGetState(unsigned char i);
extern int touchGetLatestRawReadout(unsigned char i);

#endif


#ifdef MODULE_TOUCH

#define TOUCH_HISTORY_LENGTH (4)
int touchHistory[3][TOUCH_HISTORY_LENGTH];
int touchMaximumRawWhilePressed[3];
int touchMinimumRawWhilePressed[3];


enum touch_status_t touchGetState(unsigned char i);
int touchGetLatestRawReadout(unsigned char i);


int getTouch0(void);
int getFilteredTouch0(void);
int getFilteredTouch1(void);
int getFilteredTouch2(void);
int getTouch1(void);
int getTouch2(void);


int readTouch(char sensorNumber);
void serveTouch(void);

#endif