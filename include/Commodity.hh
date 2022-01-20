#ifndef COMMODITY
#define COMMODITY

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Commodity
{
private:
    string name;
    string type;
    int rate;
public:
    Commodity();
    Commodity(string, string, int);
    //setter methods
    void setName(string);
    void setType(string);
    void setRate(int);
    //getter methods
    string getName();
    string getType();
    int getRate();
    //other methods
    void inputDetails();
    void printDetails();
};

#endif // !COMMODITY