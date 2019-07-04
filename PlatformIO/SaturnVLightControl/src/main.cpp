#include <mbed.h>

int main()
{
    Serial     pc(SERIAL_TX, SERIAL_RX);
    DigitalOut myled(LED1);

    pc.printf("Hello World !\n");

    while (1)
    {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(1.0); // 1 sec
    }
}