#ifndef BUTTONS_H
#define BUTTONS_H

#include "common.h"
#include "buttons_cfg.h"

typedef enum
{
    BUTTON_NOT_PRESSED = 0,
    BUTTON_PRESSED
} button_t;

void     Button_Init(Callback<void()> func);
void     Button_Start(void);
void     Button_Stop(void);
button_t Button_ModeRead(void);

#endif // BUTTONS_H