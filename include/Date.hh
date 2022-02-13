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
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    //setter methods
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    //getter methods
    int getDay();
    int getMonth();
    int getYear();
    //other methods
    void inputDetails();
    void printDetails();
    void stringToDate(string);
    string dateToString();
    int value();
};

#endif // !DATE