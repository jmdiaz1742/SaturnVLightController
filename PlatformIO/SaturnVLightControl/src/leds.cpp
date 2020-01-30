#include <leds.h>
#include <leds_cfg.h>

// Private fields
static PwmOut redLED(RED_LED_PIN);
static PwmOut greenLED(GREEN_LED_PIN);
static PwmOut blueLED(BLUE_LED_PIN);

// Private methods

// Public methods

/**
 * @brief Initialize LEDs pins PWMs
 *
 */
void Leds_init(void)
{
    redLED.period_ms(PWM_PERIOD);
    greenLED.period_ms(PWM_PERIOD);
    blueLED.period_ms(PWM_PERIOD);

    redLED.write(PWM_DUTY_CYCLE_INITIAL);
    greenLED.write(PWM_DUTY_CYCLE_INITIAL);
    blueLED.write(PWM_DUTY_CYCLE_INITIAL);
}

/**
 * @brief Set LEDs color intensities, from 0 (Off) to 255 (Max)
 *
 * @param red Red LED
 * @param green Green LED
 * @param blue Blue LED
 */
void Leds_set(led_t red, led_t green, led_t blue)
{
    redLED.write(red / 255.0f);
    greenLED.write(green / 255.0f);
    blueLED.write(blue / 255.0f);
}