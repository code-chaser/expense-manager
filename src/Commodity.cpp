#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

#include "./../include/Commodity.hh"

Commodity::Commodity()
{
    name = "";
    type = "";
    rate = -1.00;
}
Commodity::Commodity(string name, string type, double rate)
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
void Commodity::setRate(double rate)
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
double Commodity::getRate()
{
    return rate;
}
//other methods
void Commodity::inputDetails()
{
    cout << "Commodity Name: ";
    cin >> name;
    cout << "Commodity Type: ";
    cin >> type;
    return;
}
void Commodity::printDetails()
{
    cout << "Commodity Name: " << name << endl;
    cout << "Commodity Type: " << type << endl;
    cout << "Commodity Rate: " << rate << endl;
    return;
}