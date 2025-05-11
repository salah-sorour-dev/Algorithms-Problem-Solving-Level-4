

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

sDate IncreaseDateByXDays(int Days, sDate Date)
{
	for (int i = 0; i < Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate IncreaseDateByXMonths(int Months, sDate Date)
{
	for (int i = 0; i < Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}

sDate IncreaseDateByXYears(int Years, sDate Date)
{
	for (int i = 0; i < Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearsFaster(int Years, sDate Date)
{
	Date.Year += Years;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecade(int Decades, sDate Date)
{
	for (int i = 0; i < Decades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadeFaster(int Decades, sDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
	Date.Year += 1000;
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

	Date1 = IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(10, Date1);
	cout << "\n02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonths(5, Date1);
	cout << "\n06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Adding 10 years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecade(10, Date1);
	cout << "\n11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadeFaster(10, Date1);
	cout << "\n12-Adding 10 Decades (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding one Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding one Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}
