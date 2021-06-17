#pragma once

class Timer
{
private:
	unsigned long StartTime;
	float Length;

public:
	Timer(float);
	void Start();
	bool Done();
};