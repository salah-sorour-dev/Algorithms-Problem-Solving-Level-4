

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

sDate DecreaseDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
			Date.Day = 31;

		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

sDate DecreaseDateByXDays(int Days, sDate Date)
{
	for (int i = 0; i < Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate DecreaseDateByXMonths(int Months, sDate Date)
{
	for (int i = 0; i < Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYears(int Years, sDate Date)
{
	for (int i = 0; i < Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearsFaster(int Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecade(int Decades, sDate Date)
{
	for (int i = 0; i < Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadeFaster(int Decades, sDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
	Date.Year -= 1000;
	return Date;
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

int main()
{
	sDate Date1 = ReadFullDate();

	cout << "\nDate After:\n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(10, Date1);
	cout << "\n02-Subtracting 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Subtracting 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Subtracting 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYears(10, Date1);
	cout << "\n08-Subtracting 10 years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Subtracting 10 years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecade(10, Date1);
	cout << "\n11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadeFaster(10, Date1);
	cout << "\n12-Subtracting 10 Decades (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting one Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting one Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}
