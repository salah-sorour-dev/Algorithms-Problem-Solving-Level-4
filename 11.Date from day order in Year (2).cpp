// problem 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short DayOrderOfWeek(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


int NumberOfDaysFromBeginYear(short Day, short Month, short Year)
{

	int TotalDays = 0;
	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(Year, i);

	}
	return TotalDays + Day;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate GetDateFromDayOrderInYear(int DateOrderInYear, short Year)
{
	sDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

short ReadDay()
{
	short Day;
	cout << "Please Enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please Enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please Enter a Year? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysOrderInYear = NumberOfDaysFromBeginYear(Day, Month, Year);

	cout << "\nNumber of Days From the Begenning of the year is "
	     << NumberOfDaysFromBeginYear(Day, Month, Year);

	sDate Date;
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);

	cout << "\nDate for [" << DaysOrderInYear << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
