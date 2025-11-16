#ifndef NUMBERDISPLAY_H
#define NUMBERDISPLAY_H

class NumberDisplay
{
	public:
		NumberDisplay(int limit);
		~NumberDisplay();
		bool increase();
		int limit;
	private:
		int value;
	protected:
};

#endif
