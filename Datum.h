#pragma once
#include <time.h>
#include <string>

using namespace std;
class Datum
{
public:
	Datum();
	virtual ~Datum();
	struct tm * DatePlusDays(struct tm* date, int days);
	struct tm * getActualDate();
	int getDay(struct tm* time);
	int getMonth(struct tm* time);
	int getYear(struct tm* time);
	bool compareDateWithActualDate(string date);
	bool isNextDayDateOfDelivery(string date);
};

