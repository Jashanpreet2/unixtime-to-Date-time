#include <stdio.h>
#include <math.h>
#define LEAPDAYS 13
#define SECONDSYEAR (365 * 24 * 60 * 60)
#define SECONDSDAY (24*60*60)
#define SECONDSHOUR (60*60)
#define SECONDSMINUTE 60
int main()
{
	int yearDate = 0,
		monthDate = 0,
		dayDate = 0;
	int i;
	const int unixtime = 1679121127;
	const int realTime = unixtime;
	int years = realTime / SECONDSYEAR;
	yearDate = years + 1970;
	int numOfDays = (unixtime - years * SECONDSYEAR) / SECONDSDAY - LEAPDAYS;
	const int JAN = 0,
		FEB = 31,
		MAR = FEB + 28,
		APR = MAR + 31,
		MAY = APR + 30,
		JUN = MAY + 31,
		JUL = JUN + 30,
		AUG = JUL + 31,
		SEP = AUG + 31,
		OCT = SEP + 30,
		NOV = OCT + 31,
		DEC = NOV + 30;
	int months[13] = { JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC,9999999 };
	double hours = 0,
		minutes = 0,
		seconds = 0;
	hours = floor((realTime - (years * SECONDSYEAR) - ((numOfDays + LEAPDAYS) * SECONDSDAY)) / SECONDSHOUR);
	minutes = floor((realTime - (years * SECONDSYEAR) - ((numOfDays + LEAPDAYS) * SECONDSDAY) - hours * SECONDSHOUR) / SECONDSMINUTE);
	seconds = floor(realTime - (years * SECONDSYEAR) - ((numOfDays + LEAPDAYS) * SECONDSDAY) - hours * SECONDSHOUR - minutes * SECONDSMINUTE);
	for (i = 0; i < 11; i++)
	{
		if (numOfDays > months[i] && numOfDays < months[i + 1])
		{
			dayDate = numOfDays - months[i];
			monthDate = i + 1;
		}
	}
	printf("%d-%d-%d\nTime: %02.0lf:%02.0lf:%02.0lf", yearDate, monthDate, dayDate, hours, minutes, seconds);
	return 0;
}
