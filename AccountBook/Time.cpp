#include "Time.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>




const short Time::NONE_LEAF_DAY[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


bool Time::setTime(const time_t  lCLibraryTime)
{
	tm timeStructure; 
	localtime_s(&timeStructure,&lCLibraryTime);
	if (!setYear(timeStructure.tm_year + 1900))
	{
		setError();
		return false;
	}
	if (!setMonth(timeStructure.tm_mon + 1))
	{
		setError();
		return false;
	}
	if (!setDay(timeStructure.tm_mday))
	{
		setError();
		return false;
	}
	if (!setHour(timeStructure.tm_hour))
	{
		setError();
		return false;
	}
	if (!setMinute(timeStructure.tm_min))
	{
		setError();
		return false;
	}
	if (!setSecond(timeStructure.tm_sec))
	{
		setError();
		return false;
	}

	return true;
}

bool Time::setTime(const char acString[])
{

	char acYear[5], acMonth[3], acDay[3], acHour[3], acMinute[3], acSecond[3];

	if (strlen(acString) < 14)
		return false;
	
	sscanf_s(acString, "%4s%2s%2s%2s%2s%2s", acYear, 5,
		acMonth, 3, acDay, 3, acHour, 3, acMinute, 3, acSecond, 3);

	if (!setYear(atoi(acYear)))
	{
		setError();
		return false;
	}
	if (!setMonth(atoi(acMonth)))
	{
		setError();
		return false;
	}
	if (!setDay(atoi(acDay)))
	{
		setError();
		return false;
	}
	if (!setHour(atoi(acHour)))
	{
		setError();
		return false;
	}
	if (!setMinute(atoi(acMinute)))
	{
		setError();
		return false;
	}
	if (!setSecond(atoi(acSecond)))
	{
		setError();
		return false;
	}

	return true;


}

bool Time::setYear(const short sYear)
{
	if (sYear < 0)
		return false;

	this->sYear = sYear;
	return true;
}

bool Time::setMonth(const short sMonth)
{
	if (sMonth < 1 || sMonth > 12)
		return false;

	this->sMonth = sMonth;
	return true;
}

bool Time::setDay(const short sDay)
{
	if ( (getMonth() == 2) && isLeafYear())
	{
		if ( (sDay < 1) || (sDay > NONE_LEAF_DAY[1] + 1))
			return false;
	}
	else if ((sDay < 1) || (sDay > NONE_LEAF_DAY[getMonth() - 1]))
	{
		return false;
	}

	this->sDay = sDay;
	return true;
}

bool Time::setHour(const short sHour)
{
	if (sHour < 0 || sHour >23)
		return false;
	
	this->sHour = sHour;
	return true;
}

bool Time::setMinute(const short sMinute)
{
	if (sMinute < 0 || sMinute > 59)
		return false;

	this->sMinute = sMinute;
	return true;
}

bool Time::setSecond(const short sSecond)
{
	if (sSecond < 0 || sSecond >59)
		return false;

	this->sSecond = sSecond;
	return true;
}

time_t Time::getTIme()
{
	tm tempTimeStructure;
	tempTimeStructure.tm_year = getYear()-1900;
	tempTimeStructure.tm_mon = getMonth()-1;
	tempTimeStructure.tm_mday = getDay();
	tempTimeStructure.tm_hour = getHour();
	tempTimeStructure.tm_min = getMinute();
	tempTimeStructure.tm_sec = getSecond();
	return mktime(&tempTimeStructure);
}

bool Time::getTIme(char acString[], const int iStringSize)
{
	if (iStringSize < 15)
		return false;

	sprintf_s(acString,15, "%04d%02d%02d%02d%02d%02d", getYear(), getMonth(), getDay(), getHour(), getMinute(), getSecond());
	return true;
}


short Time::getYear()
{
	return sYear;
}

short Time::getMonth()
{
	return sMonth;
}

short Time::getDay()
{
	return sDay;
}

short Time::getHour()
{
	return sHour;
}

short Time::getMinute()
{
	return sMinute;
}

short Time::getSecond()
{
	return sSecond;
}

bool Time::isLeafYear(const Time & time)
{
	if (((time.sYear % 4 == 0) && (time.sYear % 100 != 0)) || (time.sYear % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::isLeafYear()
{
	return isLeafYear(*this);

}



void Time::setError()
{
	sMonth = 0;
	sDay = 0;
}

bool Time::getError()
{
	if (sMonth == 0 || sDay == 0)
		return true;

	return false;
}

Time::Time()
	:sYear(0), sMonth(0), sDay(0), sHour(0), sMinute(0), sSecond(0)
{
}

Time::Time(const time_t lCLibraryTime)
	: sYear(0), sMonth(0), sDay(0), sHour(0), sMinute(0), sSecond(0)
{
	setTime(lCLibraryTime);
}

Time::Time(const char acTimeString[])
	: sYear(0), sMonth(0), sDay(0), sHour(0), sMinute(0), sSecond(0)
{
	setTime(acTimeString);
}

Time::~Time()
{
}
