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


sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
{

	short WeekEndCounter = 0;

	//in case the data  is weekend keep adding one day util you reach business day
	//we get rid of all weekends before the first business day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//here we increase the vacation dates to add all weekends to it.

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (IsWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//in case the return date is week end keep adding one day util you reach business day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
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

short ReadVacationDays()
{
	short Days;
	cout << "\n\nPlease Enter Vacation Days? ";
	cin >> Days;
	return Days;
}



int main()
{
	sDate Date1 = ReadFullDate();
	short VacationDays = ReadVacationDays();

	sDate DateTo = CalculateVacationReturnDate(Date1, VacationDays);

	cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(DateTo)) << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;



	system("pause>0");
	return 0;
}
