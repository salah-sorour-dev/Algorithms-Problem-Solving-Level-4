

#include <iostream>
#include <string>

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

string MonthName(short Month)
{
	string arrMonth[] = { "Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonth[Month - 1];
}

void PrintMonthCalondar(short Year, short Month)
{
	int NumberOfDays;

	int current = DayOrderOfWeek(Year, Month, 1);

	NumberOfDays = NumberOfDaysInMonth(Year, Month);

	printf("\n  _______________%s_______________\n\n",
		MonthName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	
	cout << "\n  _________________________________\n\n";
}


short ReadYear()
{
	short Year = 0;
	cout << "\nPlease Enter a Year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease Enter a Month? ";
	cin >> Month;
	return Month;
}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalondar(Year, Month);


	system("pause>0");
	return 0;
}

