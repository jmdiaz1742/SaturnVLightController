#include "buttons.h"

static InterruptIn      ModeButton(MODE_BUTTON_PIN);
static Callback<void()> ModeFunction;
static volatile bool    ModeButtonEnabled = false;
static Timeout          DebounceTimeout;

void enableModeButtonIrq(void)
{
    ModeButtonEnabled = true;
}

void modeButton_Irq(void)
{
    if (ModeButtonEnabled)
    {
        ModeButtonEnabled = false;
        ModeFunction();
        DebounceTimeout.attach(&enableModeButtonIrq, BUTTON_DEBOUNCE_TIME_S);
    }
}

void Button_Init(Callback<void()> func)
{
    ModeButton.fall(&modeButton_Irq);
    ModeFunction      = func;
    ModeButtonEnabled = true;
}

void Button_Start(void)
{
    ModeButton.enable_irq();
}

void Button_Stop(void)
{
    ModeButton.disable_irq();
}

button_t Button_ModeRead(void)
{
    button_t buttonState = BUTTON_NOT_PRESSED;

    if (ModeButton.read())
    {
        buttonState = BUTTON_PRESSED;
    }
    return buttonState;
}