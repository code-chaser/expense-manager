#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>
using namespace std;

#include "./../include/Commodity.hh"
#include "./../include/ExpenseManager.hh"

#define wait(x) this_thread::sleep_for(chrono::milliseconds(x))

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
// setter methods
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
// getter methods
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
// other methods
void Commodity::inputDetails()
{
    cout << "Commodity Name: ";
    getline(cin >> ws, name);
    cout << "\n";
    cout << "Commodity Type:\n";
    ExpenseManager::printCommodityTypes();
    cout << "\nOptions:\n";
    cout << "[01] - Select commodity type from the list above\n";
    cout << "[02] - Add a new commodity type\n\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "\nInvalid choice.\nPlease enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 1)
        type = ExpenseManager::getCommodityType();
    else if (choice == 2)
    {
        cout << "Enter new commodity type: ";
        getline(cin >> ws, type);
        ExpenseManager::addCommodityType(type);
    }
    return;
}
void Commodity::printDetails()
{
    cout << "Commodity Name: " << name << endl;
    cout << "Commodity Type: " << type << endl;
    cout << "Commodity Rate: " << rate << endl;
    return;
}