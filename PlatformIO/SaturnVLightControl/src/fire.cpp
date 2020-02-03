#include "fire.h"
#include "fire_cfg.h"
#include "leds.h"

static bool     FireEnabled = false;
static uint32_t FireStep    = 0;

/**
 * @brief Initialize Fire module
 *
 */
void Fire_init(void)
{
    FireEnabled = false;
    FireStep    = 0;
    Leds_init();
}

/**
 * @brief Enable fire animations
 *
 */
void Fire_start(void)
{
    FireEnabled = true;
}

/**
 * @brief Disable fire animations
 *
 */
void Fire_stop(void)
{
    FireEnabled = false;
    Leds_set(LED_OFF_VALUE, LED_OFF_VALUE, LED_OFF_VALUE);
}

/**
 * @brief Get the fire animations status
 *
 * @return true Fire animations enabled
 * @return false Fire animations disabled
 */
bool IsFireActive(void)
{
    return FireEnabled;
}

/**
 * @brief Step through the various fire animation colors, use FIRE_PERIOD_MS as
 * separation between steps
 *
 */
void Fire_step(void)
{
    if (FireEnabled)
    {
        if (NUMBER_OF_FIRE_ELEMENTS <= FireStep)
        {
            FireStep = 0;
        }

        Leds_set(FirePattern[FireStep].red,
                 FirePattern[FireStep].green,
                 FirePattern[FireStep].blue);
        ++FireStep;
    }
}

uint32_t Fire_getNumberOfFireSteps(void)
{
    return NUMBER_OF_FIRE_ELEMENTS;
}