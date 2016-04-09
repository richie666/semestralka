#include "Datum.h"


/*
Datum::Datum()
{
}

Datum::~Datum()
{
}

struct tm * Datum::DatePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY = 24 * 60 * 60;

	// Seconds since start of epoch
	time_t date_seconds = mktime(date) + (days * ONE_DAY);

	// Update caller's date
	// Use localtime because mktime converts to UTC so may change date
	//return (*localtime)(&date_seconds);
}

tm * Datum::getActualDate()
{
	time_t rawtime_;
	struct tm *timeInfo_;
	time(&rawtime_);
	//return timeInfo_ = localtime(&rawtime_);
}

int Datum::getDay(struct tm* time)
{
	return time->tm_mday;
}

int Datum::getMonth(struct tm* time)
{
	return time->tm_mon + 1;
}

int Datum::getYear(struct tm* time)
{
	return time->tm_year + 1900;
}

bool Datum::compareDateWithActualDate(string date)
{
	struct tm* time = DatePlusDays(getActualDate(), 2);
	string date1 = to_string(getDay(time)) + "." + to_string(getMonth(time)) + "." + to_string(getYear(time));
	const char * d1 = date1.c_str();
	const char * d = date.c_str();
	if (strcmp(d, d1) < 0)
	{
		return true;
	}
	istringstream date_s(date);
	struct tm date_c;
	date_s >> get_time(&date_c, "%d.%m.%Y");
	time_t seconds = mktime(&date_c);
	int day;
	int month;
	int year;
	//day = atoi(date.substr(0, 2).c_str);
	//month = atoi(date.substr(3, 2).c_str);
	//year = atoi(date.substr(6, 4).c_str);
	if (getDay() + 2 < 31)
	{
		return true;
	}
	return false;
}

bool Datum::isNextDayDateOfDelivery(string date)
{
	struct tm* time = DatePlusDays(getActualDate(), 1);
	string date1 = to_string(getDay(time)) + "." + to_string(getMonth(time)) + "." + to_string(getYear(time));
	const char * d1 = date1.c_str();
	const char * d = date.c_str();
	if (strcmp(d, d1) == 0)
	{
		return true;
	}
	return false;
}
*/