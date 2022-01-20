#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "./../include/Expense.hh"

Expense::Expense()
{
    id = 0;
    date = Date();
    commodity = Commodity();
    quantity = 0;
    amount = 0;
}
Expense::Expense(int id, Date date, Commodity commodity, int quantity, int amount)
{
    this->id = id;
    this->date = date;
    this->commodity = commodity;
    this->quantity = quantity;
    this->amount = amount;
}
//setter methods
void Expense::setId(int id)
{
    this->id = id;
    return;
}
void Expense::setDate(Date date)
{
    this->date = date;
    return;
}
void Expense::setCommodity(Commodity commodity)
{
    this->commodity = commodity;
    return;
}
void Expense::setQuantity(int quantity)
{
    this->quantity = quantity;
    return;
}
void Expense::setAmount(int amount)
{
    this->amount = amount;
    return;
}
//getter methods
int Expense::getId()
{
    return id;
}
Date Expense::getDate()
{
    return date;
}
Commodity Expense::getCommodity()
{
    return commodity;
}
int Expense::getQuantity()
{
    return quantity;
}
int Expense::getAmount()
{
    return amount;
}
//other methods
void Expense::inputDetails()
{
    cout << "Enter Expense Details: " << endl;
    cout << "ID: ";
    cin >> id;
    date.inputDetails();
    commodity.inputDetails();
    cout << "Quantity: ";
    cin >> quantity;
    cout << "Amount: ";
    cin >> amount;
    return;
}
void Expense::printDetails()
{
    cout << "Expense Details: " << endl;
    cout << "ID: " << id << endl;
    date.printDetails();
    commodity.printDetails();
    cout << "Quantity: " << quantity << endl;
    cout << "Amount: " << amount << endl;
    return;
}