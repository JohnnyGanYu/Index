#ifndef CLOCKDISPLAY_H
#define CLOCKDISPLAY_H

class ClockDisplay
{
	public:
		ClockDisplay();
		~ClockDisplay();
		void start();
	private:
		NumberDisplay hours;
		NumberDisplay minutes;
	protected:
};

#endif
