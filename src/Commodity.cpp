#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "./../include/Commodity.hh"

Commodity::Commodity()
{
    name = "";
    type = "";
    rate = 0;
}
Commodity::Commodity(string name, string type, int rate)
{
    this->name = name;
    this->type = type;
    this->rate = rate;
}
//setter methods
void Commodity::setName(string name)
{
    this->name = name;
    return;
}
void Commodity::setType(string type)
{
    this->type = type;
    return;
}
void Commodity::setRate(int rate)
{
    this->rate = rate;
    return;
}
//getter methods
string Commodity::getName()
{
    return name;
}
string Commodity::getType()
{
    return type;
}
int Commodity::getRate()
{
    return rate;
}
//other methods
void Commodity::inputDetails()
{
    cout << "Enter Commodity Name: ";
    cin >> name;
    cout << "Enter Commodity Type: ";
    cin >> type;
    cout << "Enter Commodity Rate: ";
    cin >> rate;
    return;
}
void Commodity::printDetails()
{
    cout << "Commodity Name: " << name << endl;
    cout << "Commodity Type: " << type << endl;
    cout << "Commodity Rate: " << rate << endl;
    return;
}
