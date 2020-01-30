#include "fire.h"
#include "version.h"
#include "common.h"

#define MAIN_DEBUG
#if defined(DEBUG) && defined(MAIN_DEBUG)
Serial pc(DEBUG_SERIAL_TX, DEBUG_SERIAL_RX);
#define MAIN_DEBUG_PRINT(message, ...) pc.printf("MAIN: " message __NL, ##__VA_ARGS__)
#else
#define MAIN_DEBUG_PRINT(message, ...)
#endif // DEBUG_PRINT

typedef struct
{
    uint8_t major;
    uint8_t minor;
    uint8_t patch;
} version_t;

typedef enum
{
    STATE_INIT = 0,
    STATE_READ_BUTTON,
    STATE_READ_POT,
    STATE_SHOW_FIRE,

    STATE_NUM_MAX
} state_t;

static const version_t  Version       = {VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH};
static volatile state_t CurrentState  = STATE_INIT;
static volatile state_t PreviousState = STATE_INIT;

static void setNewState(state_t state)
{
    PreviousState = CurrentState;
    CurrentState  = state;
}

int main()
{
    Fire_init();

    while (1)
    {
        switch (CurrentState)
        {
            case STATE_INIT:
                MAIN_DEBUG_PRINT("Saturn V lights controller\r\n"
                                 "Version: %2d.%2d.%2d\r\n",
                                 Version.major,
                                 Version.minor,
                                 Version.patch);
                Fire_start();
                setNewState(STATE_SHOW_FIRE);
                break;

            case STATE_SHOW_FIRE:
                Fire_step();
                thread_sleep_for(FIRE_PERIOD_MS);
                break;

            default:
                setNewState(STATE_INIT);
                break;
        }
    }
}