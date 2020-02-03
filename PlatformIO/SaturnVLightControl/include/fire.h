#ifndef FIRE_H
#define FIRE_H

#include "common.h"

#define FIRE_PERIOD_MS (25)

void     Fire_init(void);
void     Fire_start(void);
void     Fire_stop(void);
bool     IsFireActive(void);
void     Fire_step(void);
uint32_t Fire_getNumberOfFireSteps(void);

#endif // FIRE_H