#include <ctime>  // time and localtime
#include "date.h"
#include <istream>
#include <ostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;

//operator override. Use & to indicate reference. 
//use variable name without & in operator method.
//returns an istream to allow chaining of several dates
//Date value is "returned implicitly"
istream& operator >> (istream& i, Date& date)
{
	int y; 
	i >> y;
	i.ignore(1,'-');
	int m; 
	i >> m;
	i.ignore(1,'-');
	int d; 
	i >> d;
	date = Date(y, m, d);
	return i;
}

ostream& operator << (ostream& o, Date& date)
{
	o << date.getYear() << "-" << date.getMonth() << "-" << date.getDay(); 
	return o;
}

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d)
{
	year = y, month = m, day = d;
}

int Date::getYear() const 
{
	return year;
}

int Date::getMonth() const 
{
	return month;
}

int Date::getDay() const 
{
	return day;
}

void Date::next() 
{
	day++; 
	if(day > daysPerMonth[month])
	{
		day = 1; 
		month++;
		if(month > 12)
		{
			month = 1;
			year++;
		}
	}
}