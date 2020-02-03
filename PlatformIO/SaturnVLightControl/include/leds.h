#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

#define LED_OFF_VALUE (0)

/**
 * @brief LED data type
 *
 */
typedef uint8_t led_t;

void Leds_init(void);
void Leds_set(led_t red, led_t green, led_t blue);

#endif // LEDS_H