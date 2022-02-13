#ifndef COMMODITY
#define COMMODITY

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Commodity
{
private:
    string name;
    string type;
    double rate;
public:
    Commodity();
    Commodity(string, string, double);
    //setter methods
    void setName(string);
    void setType(string);
    void setRate(double);
    //getter methods
    string getName();
    string getType();
    double getRate();
    //other methods
    void inputDetails();
    void printDetails();
};

#endif // !COMMODITY