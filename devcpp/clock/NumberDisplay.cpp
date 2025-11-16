#include "NumberDisplay.h"

NumberDisplay::NumberDisplay(int lim) : value(0), limit(lim)
{
}

NumberDisplay::~NumberDisplay()
{
}

bool NumberDisplay::increase()
{
	value++;
	if (value < limit)
	{
		return false;
	}
	else
	{
		value = 0;
		return true;
	}
}
