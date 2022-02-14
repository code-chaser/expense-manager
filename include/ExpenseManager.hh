#ifndef EXPENSEMANAGER
#define EXPENSEMANAGER

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

#include "./Commodity.hh"
#include "./Expense.hh"

class ExpenseManager
{
private:
    static map<long long, Expense> expenses;
    static map<long long, string> commodityTypes;
public:
    ExpenseManager();
    
    static void addExpense(Expense);
    static void removeExpense(Expense);
    static Expense getExpenseDetails();
    static void calculateExpenditure();
    static void printExpenses();

    static void addCommodityType(string);
    static void removeCommodityType(string);
    static void printCommodityTypes();
    static string getCommodityType();

    static void readFromCSV();
    static void writeToCSV();
};

#endif // !EXPENSEMANAGER