#ifndef COMMON_H
#define COMMON_H

#include <mbed.h>
#include <stdint.h>

#define __NL "\r\n"

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof((array)[0]))

#define DEBUG (1)
#define DEBUG_SERIAL_TX SERIAL_TX
#define DEBUG_SERIAL_RX SERIAL_RX

#endif // COMMON_H