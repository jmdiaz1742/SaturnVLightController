#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

void leds_init(void);
void leds_setRgb(uint8_t red, uint8_t blue, uint8_t green);

#endif // LEDS_H