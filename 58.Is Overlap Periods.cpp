#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

struct stPeriods
{
	sDate StartDate;
	sDate EndDate;
};

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day ? true : false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare DatesCompare(sDate Date1, sDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

short ReadYear()
{
	short Year;
	cout << "Please Enter Year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Please Enter Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "\nPlease Enter Day? ";
	cin >> Day;
	return Day;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsPeriodsOverlap(stPeriods Period1, stPeriods Period2)
{
	if (
		DatesCompare(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
		||
		DatesCompare(Period2.StartDate, Period1.EndDate) == enDateCompare::After
		)
		return false;
	else
		return true;
}

stPeriods ReadPeriod()
{
	stPeriods Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

int main()
{
	cout << "\nEnter Period 1:";
	stPeriods Period1 = ReadPeriod();

	cout << "\nEnter Period 2:";
	stPeriods Period2 = ReadPeriod();
	

	if (IsPeriodsOverlap(Period1, Period2))
		cout << "\n\nYes, Periods Overlap";
	else
		cout << "\n\nNo, Periods NOT Overlap";

	system("pause>0");
	return 0;
}
