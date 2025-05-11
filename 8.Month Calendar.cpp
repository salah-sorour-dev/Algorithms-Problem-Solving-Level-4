// problem 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

short DayOrder(short Year, short Month, short Day)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string PrintDayName(short DayOrder)
{
	string arrDays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDays[DayOrder];
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

short ReadDay()
{
	short Day = 0;
	cout << "\nPlease Enter a Day? ";
	cin >> Day;
	return Day;
}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOrder(Year, Month, Day);
	cout<<"\nDay Name : "<<PrintDayName(DayOrder(Year, Month, Day));

	system("pause>0");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
