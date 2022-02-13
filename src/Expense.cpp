#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

#include "./../include/Expense.hh"

Expense::Expense()
{
    id = -1;
    date = Date();
    commodity = Commodity();
    quantity = -1.00;
    amount = -1.00;
}
Expense::Expense(long long id, Date date, Commodity commodity, double quantity, double amount)
{
    this->id = id;
    this->date = date;
    this->commodity = commodity;
    this->quantity = quantity;
    this->amount = amount;
}
// setter methods
void Expense::setId(long long id)
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
void Expense::setQuantity(double quantity)
{
    this->quantity = quantity;
    return;
}
void Expense::setAmount(double amount)
{
    this->amount = amount;
    return;
}
// getter methods
long long Expense::getId()
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
double Expense::getQuantity()
{
    return quantity;
}
double Expense::getAmount()
{
    return amount;
}
// other methods
void Expense::inputDetails()
{
    cout << "Enter Expense Details:\n";
    cout << "------------------------------------------------------\n";
    date.inputDetails();
    commodity.inputDetails();
    cout << "Quantity (kg/ltr/piece): ";
    cin >> quantity;
    while (quantity <= 0)
    {
        cout << "Enter valid quantity: ";
        cin >> quantity;
    }
    cout << "Amount: ";
    cin >> amount;
    commodity.setRate(amount / quantity);
    cout << "------------------------------------------------------\n";
    return;
}
void Expense::printDetails()
{
    cout << "Expense Details: " << endl;
    cout << "ID: ";
    if (date.getDay() < 10)
        cout << "0";
    cout << id << endl;
    date.printDetails();
    commodity.printDetails();
    cout << "Quantity: " << quantity << endl;
    cout << "Amount: " << amount << endl;
    return;
}
void Expense::printDetails(vector<Expense> expenses)
{
    cout << "\n\n";
    cout << "------------------------------------------------------\n\n";
    long long sNoSpace = max(5LL, (long long)log10(expenses.size())), idSpace = 2, dateSpace = 4, commodityNameSpace = 14, commodityTypeSpace = 4, commodityRateSpace = 4, quantitySpace = 8, amountSpace = 6;
    for (auto expense : expenses)
    {
        if (idSpace < to_string(expense.getId()).length())
            idSpace = to_string(expense.getId()).length();
        if (dateSpace < expense.getDate().dateToString().length())
            dateSpace = expense.getDate().dateToString().length();
        if (commodityNameSpace < expense.getCommodity().getName().length())
            commodityNameSpace = expense.getCommodity().getName().length();
        if (commodityTypeSpace < expense.getCommodity().getType().length())
            commodityTypeSpace = expense.getCommodity().getType().length();
        if (commodityRateSpace < to_string(expense.getCommodity().getRate()).length())
            commodityRateSpace = to_string(expense.getCommodity().getRate()).length();
        if (quantitySpace < to_string(expense.getQuantity()).length())
            quantitySpace = to_string(expense.getQuantity()).length();
        if (amountSpace < to_string(expense.getAmount()).length())
            amountSpace = to_string(expense.getAmount()).length();
    }
    cout << "\n"
         << " | "
         << left << setw(idSpace) << "ID";
    cout << " | ";
    cout << left << setw(dateSpace) << "Date";
    cout << " | ";
    cout << left << setw(commodityNameSpace) << "Commodity Name";
    cout << " | ";
    cout << left << setw(commodityTypeSpace) << "Type";
    cout << " | ";
    cout << left << setw(commodityRateSpace) << "Rate";
    cout << " | ";
    cout << left << setw(quantitySpace) << "Quantity";
    cout << " | ";
    cout << left << setw(amountSpace) << "Amount";
    cout << " |\n ";
    long long totalDash = 6 * 3 + 4 + idSpace + dateSpace + commodityNameSpace + commodityTypeSpace + commodityRateSpace + quantitySpace + amountSpace;
    for (long long i = 0; i < totalDash; i++)
        cout << "-";
    cout << "\n";
    for (auto expense : expenses)
    {
        cout << " | ";
        if (expense.getDate().getDay() < 10)
            cout << left << setw(idSpace) << (to_string(expense.getId()) + "0");
        else
            cout << left << setw(idSpace) << expense.getId();
        cout << " | ";
        cout << left << setw(dateSpace) << expense.getDate().dateToString();
        cout << " | ";
        cout << left << setw(commodityNameSpace) << expense.getCommodity().getName();
        cout << " | ";
        cout << left << setw(commodityTypeSpace) << expense.getCommodity().getType();
        cout << " | ";
        cout << left << setw(commodityRateSpace) << expense.getCommodity().getRate();
        cout << " | ";
        cout << left << setw(quantitySpace) << expense.getQuantity();
        cout << " | ";
        cout << left << setw(amountSpace) << expense.getAmount();
        cout << " |\n";
    }
    return;
}
