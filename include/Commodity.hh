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
    string id;
    string name;
    string type;
    int rate;
public:
    Commodity();
    Commodity(string, string, string, int);
    //setter methods
    void setId(string);
    void setName(string);
    void setType(string);
    void setRate(int);
    //getter methods
    string getId();
    string getName();
    string getType();
    int getRate();
    //other methods
    void inputDetails();
    void printDetails();
};

#endif // !COMMODITY