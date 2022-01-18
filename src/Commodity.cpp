using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "./../include/commodity.hh"

Commodity::Commodity()
{
    id = "";
    name = "";
    type = "";
    rate = 0;
}
Commodity::Commodity(string id, string name, string type, int rate)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->rate = rate;
}
//setter methods
void Commodity::setId(string id)
{
    this->id = id;
    return;
}
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
string Commodity::getId()
{
    return id;
}
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
    cout << "Enter Commodity ID: ";
    cin >> id;
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
    cout << "Commodity ID: " << id << endl;
    cout << "Commodity Name: " << name << endl;
    cout << "Commodity Type: " << type << endl;
    cout << "Commodity Rate: " << rate << endl;
    return;
}
