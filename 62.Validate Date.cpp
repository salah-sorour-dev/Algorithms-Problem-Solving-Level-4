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

bool IsValidateDate(sDate Date)
{
	if (Date.Day < 1 || Date.Day > 31)
		return false;
	
	if (Date.Month < 1 || Date.Month > 12)
		return false;

	if (Date.Day == 2)
	{
		if (IsLeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}

	short DayInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

	if (Date.Day > DayInMonth)
		return false;

	return true;

}

int main()
{
	sDate Date = ReadFullDate();

	if (IsValidateDate(Date))
		cout << "\nYes, Date is a valide date.";
	else
		cout << "\nNo, Date is a NOT valide date.";


	system("pause>0");
	return 0;
}
