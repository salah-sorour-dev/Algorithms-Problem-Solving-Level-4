// problem 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);

}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arr31[7] = { 1,3,5,7,8,10,12 };
	//return that month have 31 days
	for (short i = 1; i <= 7; i++)
	{
		if (arr31[i - 1] == Month)
			return 31;
	}

	return 30;

}

short NumberOfHoursInMonth(short Month, short Year)
{
	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year)
{
	return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondInMonth(short Month, short Year)
{
	return NumberOfMinutesInMonth(Month, Year) * 60;
}

short ReadYear()
{
	short Year = 0;
	cout << "Enter Year to Chek? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Enter Month to Chek? ";
	cin >> Month;
	return Month;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days in Month [" << Month << "] is ";
	cout << NumberOfDaysInMonth(Month, Year);

	cout << "\nNumber of Hours in Month [" << Month << "] is ";
	cout << NumberOfHoursInMonth(Month, Year);

	cout << "\nNumber of Minutes in Month [" << Month << "] is ";
	cout << NumberOfMinutesInMonth(Month, Year);

	cout << "\nNumber of Seconds in Month [" << Month << "] is ";
	cout << NumberOfSecondInMonth(Month, Year);

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
