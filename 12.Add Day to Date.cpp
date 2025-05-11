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

sDate DateAddDays(short DaysToAdd, sDate Date)
{
	short RemainingDays = DaysToAdd + NumberOfDaysFromBeginYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
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

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short ReadDaysToAdd()
{
	short Days;
	cout << "\nHow many Days to add? ";
	cin >> Days;
	return Days;
}


int main()
{
	sDate Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);

	cout << "\nDate After Adding [" << Days << "] Days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
