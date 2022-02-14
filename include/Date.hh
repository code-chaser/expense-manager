#ifndef DATE
#define DATE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Date
{
private:
    long long day;
    long long month;
    long long year;
    bool validateDate();
public:
    Date();
    Date(long long, long long, long long);
    //setter methods
    void setDay(long long);
    void setMonth(long long);
    void setYear(long long);
    //getter methods
    long long getDay();
    long long getMonth();
    long long getYear();
    //other methods
    void inputDetails();
    void printDetails();
    void stringToDate(string);
    string dateToString();
    long long value();
};

#endif // !DATE