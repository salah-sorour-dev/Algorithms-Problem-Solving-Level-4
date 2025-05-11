

#include <iostream>

using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
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

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
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
	cout << "Please Enter Day? ";
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

int main()
{
	sDate Date = ReadFullDate();

	if (IsLastDayInMonth(Date))
		cout << "\nYes. Day Is Last Day In Month.";
	else
		cout << "\nNo. Day Is Not Last Day In Month.";

	
	if (IsLastMonthInYear(Date.Month))
		cout << "\nYes. Month Is Last Month In Year.";
	else
		cout << "\nNo. Month Is Not Last Month In Year.";


	system("pause>0");
	return 0;
}

