#include "Definitions.h"
#include "Button.h"

// Button Pins
const int LBUTTON{10};
const int FBUTTON{11};
const int RBUTTON{12};

// Variables
Button LButton{LBUTTON};
Button FButton{FBUTTON};
Button RButton{RBUTTON};

int LastButtonID{0};

void setup() 
{
	Serial.begin()
}

void loop() 
{
	LButton.Poll();
	FButton.Poll();
	RButton.Poll();
}

static void Button::ButtonCallback(int PinID, bool ButtonState)
{
	if (PinID == LastButtonID)
	{
		Serial.write(SIGNAL_CANCEL);
		LastButtonID = 0;
		return;
	}

	switch (PinID)
	{
	case LBUTTON:
		Serial.write(SIGNAL_LEFT);
		LastButtonID = PinID;
		break;
	default:
		break;
	}
}