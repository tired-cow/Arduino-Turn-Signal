#include "Definitions.h"

const float BlinkTime{1.0f};

// Variables
int CurrentSignal{0};

void setup() 
{
    Serial1.begin(9600);
}

void loop() 
{

	if (Serial1.available() > 0)
	{
		int byte = Serial1.read();

		if (byte = SIGNAL_CANCEL)
		{
			CurrentSignal = 0;
			return;
		}

		switch (byte)
		{
			case SIGNAL_LEFT:
				CurrentSignal = SIGNAL_LEFT;
				break;
        }
    }
}
