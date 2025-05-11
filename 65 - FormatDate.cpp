// problem 65.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

string FormateDate(stDate Date, string DateFormate = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormate, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

string ReadStringDate(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    string S1 = ReadStringDate("Please Enter Date dd/mm/yyyy? ");

    stDate Date = StringToDate(S1);

    cout << "\n" << FormateDate(Date) << "\n";

    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";

    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";

    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";

    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";

    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";


    system("pause>0");
    return 0;
}

