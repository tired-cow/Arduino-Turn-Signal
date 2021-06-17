#pragma once

#include "Timer.h"

class Button 
{
private:
	const float DebounceTime = .20f;
	Timer DebounceTimer;
	int PinID;
	bool LastState;

	static void ButtonCallback(int, bool);
public:
	Button(int);
	void Poll();
	int GetPinID() const;
};