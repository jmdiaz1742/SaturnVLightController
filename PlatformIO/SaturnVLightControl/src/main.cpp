#include "fire.h"
#include "buttons.h"
#include "version.h"
#include "common.h"

#define MAIN_DEBUG
#if defined(DEBUG) && defined(MAIN_DEBUG)
Serial pc(DEBUG_SERIAL_TX, DEBUG_SERIAL_RX);
#define MAIN_DEBUG_PRINT(message, ...) \
    pc.printf("MAIN: " message __NL, ##__VA_ARGS__)
#else
#define MAIN_DEBUG_PRINT(message, ...)
#endif // DEBUG_PRINT

static volatile bool fireEnabled = true;
static Timer         fireTimer;

/**
 * @brief When mode button is pressed, enable/disable the fire animation
 *
 */
static void modeButtonAction(void)
{
    fireEnabled = !fireEnabled;
    if (fireEnabled)
    {
        Fire_start();
        fireTimer.start();
    }
    else
    {
        Fire_stop();
        fireTimer.stop();
    }
    MAIN_DEBUG_PRINT("Fire status: %d\r\n", fireEnabled);
}

int main()
{
    MAIN_DEBUG_PRINT("Saturn V lights controller\r\n"
                     "Version: %d.%d.%d\r\n",
                     Version.major,
                     Version.minor,
                     Version.patch);
    MAIN_DEBUG_PRINT("Fire steps: %d\r\n", Fire_getNumberOfFireSteps());

    Fire_init();
    Button_Init(&modeButtonAction);

    Fire_start();
    Button_Start();
    fireTimer.start();

    while (1)
    {
        if (fireEnabled && (fireTimer.read_ms() >= FIRE_PERIOD_MS))
        {
            Fire_step();
            fireTimer.reset();
        }
    }
}