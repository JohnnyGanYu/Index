#include "ClockDisplay.h"
#include "NumberDisplay.h"

ClockDisplay::ClockDisplay() : hours(24), minutes(60)
{
}

ClockDisplay::~ClockDisplay()
{
}

void ClockDisplay::start()
{
	for (1)
	{
		if ( minutes.increase() )
		{
			hours.increase();
		}
		
	}
}
