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

typedef struct
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} version_t;

static const version_t Version = {VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH};

static volatile bool fireEnabled = true;
static Timer         fireTimer;

void ModeButtonAction(void)
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
    Fire_init();
    Button_Init(&ModeButtonAction);
    MAIN_DEBUG_PRINT("Fire steps: %d\r\n", Fire_getNumberOfFireSteps());
    Fire_start();
    fireTimer.start();

    while (1)
    {
        if (fireEnabled && fireTimer.read_ms() >= FIRE_PERIOD_MS)
        {
            Fire_step();
            fireTimer.reset();
        }
    }
}