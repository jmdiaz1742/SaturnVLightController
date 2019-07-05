#include <leds.h>
#include <leds_cfg.h>

// Private fields
PwmOut redLED(RED_LED_PIN);
PwmOut blueLED(BLUE_LED_PIN);
PwmOut greenLED(GREEN_LED_PIN);

// Private methods

// Public methods
void leds_init(void)
{
    redLED.period_ms(PWM_PERIOD);
    blueLED.period_ms(PWM_PERIOD);
    greenLED.period_ms(PWM_PERIOD);

    redLED.write(PWM_DUTY_CYCLE_INITIAL);
    blueLED.write(PWM_DUTY_CYCLE_INITIAL);
    greenLED.write(PWM_DUTY_CYCLE_INITIAL);
}

void leds_setRgb(uint8_t red, uint8_t blue, uint8_t green)
{
    redLED.write(red / 255.0f);
    blueLED.write(blue / 255.0f);
    greenLED.write(green / 255.0f);
}