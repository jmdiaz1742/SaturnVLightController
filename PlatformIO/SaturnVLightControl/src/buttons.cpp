#include "buttons.h"
#include "buttons_cfg.h"

static InterruptIn      ModeButton(MODE_BUTTON_PIN);
static Callback<void()> ModeFunction;
static Timeout          DebounceTimeout;

/**
 * @brief Interrupt Service Routine
 *
 */
static void modeButton_Irq(void)
{
    // Disable IRQ for debounce time
    Button_Stop();
    DebounceTimeout.attach(&Button_Start, BUTTON_DEBOUNCE_TIME_S);

    ModeFunction();
}

/**
 * @brief Initialize button
 *
 * @param func Funtion to be executed when button is pressed
 */
void Button_Init(Callback<void()> func)
{
    ModeButton.fall(&modeButton_Irq);
    ModeFunction = func;
}

/**
 * @brief Enable button
 *
 */
void Button_Start(void)
{
    ModeButton.enable_irq();
}

/**
 * @brief Disable button
 *
 */
void Button_Stop(void)
{
    ModeButton.disable_irq();
}

/**
 * @brief Read the button current state
 *
 * @return button_t button state
 */
button_t Button_ModeRead(void)
{
    button_t buttonState = BUTTON_NOT_PRESSED;

    // Button pressed is LOW level on pin
    if (ModeButton.read() == 0)
    {
        buttonState = BUTTON_PRESSED;
    }
    return buttonState;
}