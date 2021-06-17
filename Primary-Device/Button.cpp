#include "Button.h"
#include <Arduino.h>
#include "Definitions.h"

Button::Button(int ID)
	: PinID{ID}, LastState{false}, DebounceTimer{DebounceTime}
{
	pinMode(ID, INPUT);
	DebounceTimer.Start();
}

void Button::Poll()
{
	bool CurrentState{false};

	if (digitalRead(PinID) == HIGH)
		CurrentState = true;

	if (DebounceTimer.Done() == true)
	{
		if (LastState == false && CurrentState == true)
			Button::ButtonCallback(PinID, BUTTON_PRESSED);
		else if (LastState == true && CurrentState == false)	
			Button::ButtonCallback(PinID, BUTTON_RELEASED);

		DebounceTimer.Start();
	}
}

int Button::GetPinID() const
{
	return PinID;
}

static void Button::ButtonCallback(int PinID, bool ButtonState);