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
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
//setter methods
void Date::setDay(int day)
{
    this->day = day;
    return;
}
void Date::setMonth(int month)
{
    this->month = month;
    return;
}
void Date::setYear(int year)
{
    this->year = year;
    return;
}
//getter methods
int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
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
    int i = 0;
    while (getline(ss, token, '/'))
    {
        if (i == 0)
        {
            day = stoi(token);
        }
        else if (i == 1)
        {
            month = stoi(token);
        }
        else if (i == 2)
        {
            year = stoi(token);
        }
        i++;
    }
    return;
}
string Date::dateToString()
{
    stringstream ss;
    ss << day << "/" << month << "/" << year;
    return ss.str();
}
int Date::value()
{
    return (day * 1000000) + (month * 10000) + (year * 1);
}