#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "./../include/Date.hh"

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
//setter methods
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
//getter methods
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
//other methods
void Date::inputDetails()
{
    cout << "Enter Date (DD,MM,YYYY): ";
    cout << "Day   - (DD)  : ", cin >> day;
    cout << "Month - (MM)  : ", cin >> month;
    cout << "Year  - (YYYY): ", cin >> year;
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
    long long i = 0;
    while (getline(ss, token, '/'))
    {
        if (i == 0)
        {
            day = stoll(token);
        }
        else if (i == 1)
        {
            month = stoll(token);
        }
        else if (i == 2)
        {
            year = stoll(token);
        }
        i++;
    }
    return;
}
string Date::dateToString()
{
    stringstream ss;
    if(day < 10) ss << "0";
    ss << day << "/";
    if(month < 10) ss << "0";
    ss << month << "/";
    if(year < 10) ss << "000";
    else if(year < 100) ss << "00";
    else if(year < 1000) ss << "0";
    ss << year;
    return ss.str();
}
long long Date::value()
{
    return (day * 1000000) + (month * 10000) + (year * 1);
}