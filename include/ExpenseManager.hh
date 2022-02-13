#ifndef EXPENSEMANAGER
#define EXPENSEMANAGER

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

#include "./Date.hh"
#include "./Commodity.hh"
#include "./Expense.hh"

class ExpenseManager
{
private:
    map<int, Expense> expenses;
    map<int, string> commodityTypes;
public:
    ExpenseManager();
    void addExpense(Expense);
    void removeExpense(Expense);
    Expense getExpenseDetails();
    void addCommodityType(string);
    void removeCommodityType(string);
    void printCommodityTypes();
    string getCommodityType();
    void readFromCSV();
    void writeToCSV();
};

#endif // !EXPENSEMANAGER