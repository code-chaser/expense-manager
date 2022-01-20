#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "./../include/ExpenseManager.hh"

ExpenseManager::ExpenseManager()
{
    expenses = map<int, Expense>();
    commodityTypes = map<int, string>();
}
void ExpenseManager::addExpense(Expense expense)
{
    expenses[(expenses.rbegin()->first)+1] = expense;
    return;
}
void ExpenseManager::addCommodityType(string type)
{
    commodityTypes[commodityTypes.size()] = type;
    return;
}
void ExpenseManager::readFromCSV()
{
    ifstream file;
    file.open("./../data/expenseSheet.csv");
    string line;
    getline(file, line); //skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        int id;
        Date date;
        Commodity commodity;
        int quantity;
        int amount;
        getline(ss, token, ',');
        id = stoi(token);
        getline(ss, token, ',');
        date.stringToDate(token);
        getline(ss, token, ',');
        commodity.setName(token);
        getline(ss, token, ',');
        commodity.setType(token);
        getline(ss, token, ',');
        commodity.setRate(stoi(token));
        getline(ss, token, ',');
        quantity = stoi(token);
        getline(ss, token, ',');
        amount = stoi(token);
        addExpense(Expense(id, date, commodity, quantity, amount));
    }
    file.close();
    file.open("./../data/commodityTypes.csv");
    getline(file, line); //skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        addCommodityType(token);
    }
    return;
}
void ExpenseManager::writeToCSV()
{
    ofstream file;
    file.open("./../data/expenseSheet.csv");
    file << "ID,Date,Commodity Name,Commodity Type,Rate,Quantity,Amount\n";
    for (auto expense : expenses)
    {
        file << expense.first << ",";
        file << expense.second.getDate().dateToString() << ",";
        file << expense.second.getCommodity().getName() << ",";
        file << expense.second.getCommodity().getType() << ",";
        file << expense.second.getCommodity().getRate() << ",";
        file << expense.second.getQuantity() << ",";
        file << expense.second.getAmount() << "\n";
    }
    file.close();
    file.open("./../data/commodityTypes.csv");
    file << "S.No.,Commodity Type\n";
    for (auto commodityType : commodityTypes)
    {
        file << commodityType.first+1 << ",";
        file << commodityType.second << "\n";
    }
    file.close();
    return;
}