#include "Timer.h"
#include <Arduino.h>

Timer::Timer(float Duration)
    : StartTime{0.0f}, Length{Duration}
{

}

void Timer::Start()
{
    StartTime = millis();
}

bool Timer::Done()
{
    unsigned long EndTime{Length * 1000};
    unsigned long CurrentTime{millis()};

    if (CurrentTime - StartTime >= EndTime)
        return true;
    else 
        return false;
}