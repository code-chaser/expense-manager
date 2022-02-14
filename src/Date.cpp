#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

#include "./../include/Date.hh"

#define wait(x) this_thread::sleep_for(chrono::milliseconds(x))

Date::Date()
{
    day = -1;
    month = -1;
    year = -1;
}
Date::Date(long long day, long long month, long long year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
// setter methods
void Date::setDay(long long day)
{
    this->day = day;
    return;
}
void Date::setMonth(long long month)
{
    this->month = month;
    return;
}
void Date::setYear(long long year)
{
    this->year = year;
    return;
}
// getter methods
long long Date::getDay()
{
    return day;
}
long long Date::getMonth()
{
    return month;
}
long long Date::getYear()
{
    return year;
}
// other methods
bool Date::validateDate()
{
    //check if the date is a valid calendar date
    if(day < 1 || day > 31)
        return false;
    if(month < 1 || month > 12)
        return false;
    if(year < 0)
        return false;
    if(month == 2)
    {
        if(day > 29)
            return false;
        if(day == 29)
            if(year % 4 != 0)
                return false; // loophole: non-leap years like 2100, 2200, etc.
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
        if(day > 30)
            return false;
    return true;
}
void Date::inputDetails()
{
    cout << "\n";
    cout << "Enter Date (DD,MM,YYYY):\n";
    cout << "\tDay   - (DD)  : ", cin >> day;
    cout << "\tMonth - (MM)  : ", cin >> month;
    cout << "\tYear  - (YYYY): ", cin >> year;
    cout << "\n";
    while(!validateDate())
    {
        cout << "\nInvalid Date!\nPlease enter a valid date:\n";
        this->inputDetails();
    }
    return;
}
void Date::printDetails()
{
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    return;
}
void Date::stringToDate(string date)
{
    stringstream ss(date);
    string token;
    getline(ss, token, '/');
    day = stoll(token);
    getline(ss, token, '/');
    month = stoll(token);
    getline(ss, token, '/');
    year = stoll(token);
    return;
}
string Date::dateToString()
{
    stringstream ss;
    if (day < 10)
        ss << "0";
    ss << day << "/";
    if (month < 10)
        ss << "0";
    ss << month << "/";
    if (year < 10)
        ss << "000";
    else if (year < 100)
        ss << "00";
    else if (year < 1000)
        ss << "0";
    ss << year;
    return ss.str();
}
long long Date::value()
{
    return year * 10000 + month * 100 + day;
}