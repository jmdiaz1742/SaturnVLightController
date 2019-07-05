#include <mbed.h>
#include <leds.h>

Serial pc(SERIAL_TX, SERIAL_RX);

int main()
{
    uint8_t red;
    uint8_t blue;
    uint8_t green;

    leds_init();
    pc.printf("Hello World !\n");

    while (1)
    {
        wait(1);

        red   = 0;
        blue  = 0;
        green = 0;
        for (uint32_t color = 0; color < 8; color++)
        {
            pc.printf("red: %d, blue: %d, green: %d\r\n", red, blue, green);
            leds_setRgb(red, blue, green);
            red += 10;
            blue += 20;
            green += 30;
            wait_ms(50);
            leds_setRgb(0, 0, 0);
            wait_ms(10);
        }
    }
}