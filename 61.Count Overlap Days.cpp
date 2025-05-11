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

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
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


int PeriodLengthInDays(stPeriods Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsDateWithinPeriod(stPeriods Period, sDate Date)
{
	return !(DatesCompare(Date, Period.StartDate) == enDateCompare::Before
		||
		DatesCompare(Date, Period.EndDate) == enDateCompare::After);
}

int CountOverlapDays(stPeriods Period1, stPeriods Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!IsPeriodsOverlap(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateWithinPeriod(Period2, Period1.StartDate))
				OverlapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateWithinPeriod(Period1, Period2.StartDate))
				OverlapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverlapDays;
}

int main()
{
	cout << "\nEnter Period 1:";
	stPeriods Period1 = ReadPeriod();

	cout << "\nEnter Period 2:";
	stPeriods Period2 = ReadPeriod();

	cout << "\nOverlap Days Count is: " << CountOverlapDays(Period1, Period2);



	system("pause>0");
	return 0;
}
