#pragma once

#include <cstdio>
#include <ctime>

using namespace std;

class Time
{
public:

	bool setTime(const time_t lCLibaryTime);
	bool setTime(const char acTimeString[]);
	

	bool setYear(const short sYear);
	bool setMonth(const short sMonth);
	bool setDay(const short sDay);
	bool setHour(const short sHour);
	bool setMinute(const short sMinute);
	bool setSecond(const short sSecond);


	time_t getTIme();
	bool getTIme(char acString[], const int iStringSize);

	short getYear();
	short getMonth();
	short getDay();
	short getHour();
	short getMinute();
	short getSecond();

	bool isLeafYear();
	bool isLeafYear(const Time & time);

	Time();
	Time(const time_t  lCLibaryTime);
	Time(const char  acTimeString[]);
	~Time();
	

private:
	short sYear;
	short sMonth;
	short sDay;
	short sHour;
	short sMinute;
	short sSecond;

	const static short NONE_LEAF_DAY[12];
};

