
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{

    string fullname;
    string month;
    int date;
    int year;

    array<int, 12> monthcodes = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    array<string, 7> dayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    array<string, 12> monthNames = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "Enter your full name: ";
    getline(cin, fullname);
    cout << "Welcome, " << fullname << " This application tells what day is it on a particular date, also you can ofcourse use ai or calander, this application is built using zero ai, thankyou for using this application, follow the instructions :)" << "\n";
    cout << "Enter the date (01-31): " << "\n";
    cin >> date;
    cout << "Enter the month (01-12) or exact name (eg. January): ";
    cin >> month;

    bool isNumeric = true;

    for (char c : month)
    {
        if (!isdigit(static_cast<unsigned char>(c)))
        {
            isNumeric = false;
            break;
        }
    }

    cout << "Enter the year: " << "\n";
    cin >> year;

    if (date > 31 || date < 1)
    {
        cerr << "Please enter a valid date." << "\n";
        return 1;
    }

    int monthNumber = 0;

    if (isNumeric)
    {
        monthNumber = stoi(month);

        if (monthNumber < 1 || monthNumber > 12)
        {
            cerr << "Enter a valid month number or month name, possible mistake: please keep the capslock off and enter the name as 'January' or the monthnumber is >12 or <1";
            return 1;
        }
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            string shortName = monthNames[i].substr(0, 3);

            if (month == monthNames[i] || month == shortName)
            {
                monthNumber = i + 1;
                break;
            }
        }

        if (monthNumber == 0)
        {
            cerr << "Enter a valid month number or month name, possible mistake: please keep the capslock off and enter the name as 'January' or the monthnumber is >12 or <1";
            return 1;
        }
    }

    bool isLeapYear = false;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        isLeapYear = true;
    }
    else
        isLeapYear = false;

    int maxDays = 0;

    if (monthNumber == 1 || monthNumber == 3 ||
        monthNumber == 5 || monthNumber == 7 ||
        monthNumber == 8 || monthNumber == 10 ||
        monthNumber == 12)
    {

        maxDays = 31;
    }
    else if (monthNumber == 4 || monthNumber == 6 ||
             monthNumber == 9 || monthNumber == 11)
    {

        maxDays = 30;
    }
    else if (monthNumber == 2)
    {

        if (isLeapYear)
        {
            maxDays = 29;
        }
        else
        {
            maxDays = 28;
        }
    }
    if (date > maxDays)
    {
        cerr << "Invalid date for the selected month." << "\n";
        return 1;
    }

    int century = year / 100;
    int centuryCode = 0;
    int rem = century % 4;
    if (rem == 0)
        centuryCode = 6; // 1600s, 2000s, 2400s
    else if (rem == 1)
        centuryCode = 4; // 1700s, 2100s
    else if (rem == 2)
        centuryCode = 2; // 1800s, 2200s
    else if (rem == 3)
        centuryCode = 0; // 1900s, 2300s

    int lastTwoDigits = year % 100;
    int yearCode = (lastTwoDigits + (lastTwoDigits / 4)) % 7;

    int monthCode = monthcodes[monthNumber - 1];

    int leapAdjustment = (isLeapYear && (monthNumber == 1 || monthNumber == 2)) ? 1 : 0;

    int total = date + monthCode + centuryCode + yearCode - leapAdjustment;
    int dayIndex = (total % 7 + 7) % 7;

    cout << "\n=========================================\n";
    cout << "Date: " << date << " " << monthNames[monthNumber - 1] << " " << year << "\n";
    cout << "Day : " << dayNames[dayIndex] << "\n";
    cout << "=========================================\n";

    return 0;
}
