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

stPeriods ReadPeriod()
{
	stPeriods Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsDateWithinPeriod(stPeriods Period, sDate Date)
{
	return !(DatesCompare(Date, Period.StartDate) == enDateCompare::Before
		||
		DatesCompare(Date, Period.EndDate) == enDateCompare::After);
}

int main()
{
	cout << "\nEnter Period 1:";
	stPeriods Period1 = ReadPeriod();

	cout << "\nEnter Date to check:";
	sDate Date = ReadFullDate();

	if (IsDateWithinPeriod(Period1, Date))
		cout << "\nYes, Date is within period.";
	else
		cout << "\nNo, Date is NOT within period.";

	system("pause>0");
	return 0;
}
