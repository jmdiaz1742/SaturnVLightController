#include "fire.h"
#include "fire_cfg.h"
#include "leds.h"
#include "common.h"

static bool     FireEnabled = false;
static uint32_t FireStep    = 0;

void Fire_init(void)
{
    FireEnabled = false;
    FireStep    = 0;
    Leds_init();
}

void Fire_start(void)
{
    FireEnabled = true;
}

void Fire_stop(void)
{
    FireEnabled = false;
    Leds_set(0, 0, 0);
}

void Fire_step(void)
{
    if (FireStep > NUMBER_OF_FIRE_ELEMENTS)
    {
        FireStep = 0;
    }

    Leds_set(FirePattern[FireStep].red, FirePattern[FireStep].green, FirePattern[FireStep].blue);
    ++FireStep;
}