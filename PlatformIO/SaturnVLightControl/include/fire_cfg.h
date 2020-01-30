#ifndef FIRE_CFG_H
#define FIRE_CFG_H

#include "leds.h"

typedef struct
{
    led_t red;
    led_t green;
    led_t blue;
} color_t;

const color_t FirePattern[] = {{226, 88, 34},
                               {226, 40, 34},
                               {226, 56, 34},
                               {226, 88, 34},
                               {226, 120, 34},
                               {226, 120, 34},
                               {226, 136, 34},
                               {226, 88, 34},
                               {226, 90, 54},
                               {226, 88, 34}};

#define NUMBER_OF_FIRE_ELEMENTS SIZE_OF_ARRAY(FirePattern)

#endif // FIRE_CFG_H