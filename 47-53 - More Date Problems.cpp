#pragma warning(disable : 4996)

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

short DayOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

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

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

sDate GetSystemDate()
{
	sDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

short DayOfWeekOrder(sDate Date)
{
	return DayOrder(Date.Year, Date.Month, Date.Day);
}

string DayShortName(short DayOrder)
{
	string arrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDays[DayOrder];
}

short IsEndOfWeek(sDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(sDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return DayIndex == 5 || DayIndex == 6;
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	sDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date)
{
	sDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate, true);
}


int main()
{
	sDate Date1 = GetSystemDate();

	

	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1)) << " , " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	cout << "\n\nIs it End of Week?\n";
	if (IsEndOfWeek(Date1))
		cout << "Yes it is Saturday, it's of Week.";
	else
		cout << "No it's Not end of week.";
	//---------------------
	cout << "\n\nIs it Weekend?\n";
	if (IsWeekEnd(Date1))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " <<
		DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";
	//---------------------
	cout << "\n\nIs it Business Day?\n";
	if (IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";
	//---------------------
	cout << "\n\nDays until end of week : "
		<< DaysUntilTheEndOfWeek(Date1) << " Day(s).";
	//---------------------
	cout << "\nDays until end of month : "
		<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";
	//---------------------
	cout << "\nDays until end of year : "
		<< DaysUntilTheEndOfYear(Date1) << " Day(s).";




	system("pause>0");
	return 0;
}
