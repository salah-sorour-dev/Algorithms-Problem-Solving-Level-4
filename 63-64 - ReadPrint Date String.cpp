// problem 63 - 64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate StringToDate(string S1)
{
    vector<string> vDate;
    vDate = SplitString(S1, "/");

    stDate Date;
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReadStringDate(string Message)
{
    string DateString;

    cout << Message;
    getline(cin>>ws, DateString);
    return DateString;
}

int main()
{
    string S1 = ReadStringDate("Please Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(S1);

    cout << "\nDay:" << Date.Day;
    cout << "\nMonth:" << Date.Month;
    cout << "\nYear:" << Date.Year;

    cout << "\n\nYou Entered: " << DateToString(Date);

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
