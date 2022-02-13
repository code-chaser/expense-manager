#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
using namespace std;

#define int long long

#include "./include/ExpenseManager.hh"
#include "./include/Expense.hh"
#include "./include/Commodity.hh"
#include "./include/Date.hh"

/*

Options:
[01] - Manage Expenses
    [01] - Add new Expense
    [02] - View existing Expenses
    [03] - Delete an existing Expense
    [-1] - Back
[02] - Manage Commodity Types
    [01] - Add new Commodity Type
    [02] - View existing Commodity Types
    [03] - Delete an existing Commodity Type
    [-1] - Back
[-1] - Exit

*/

signed main()
{
    ExpenseManager expenseManager;
    expenseManager.readFromCSV();
    int choice = 0;
    while (choice != -1)
    {
        cout << "Options: " << endl;
        cout << "[01] - Manage Expenses" << endl;
        cout << "[02] - Manage Commodity Types" << endl;
        cout << "[-1] - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int subChoice = 0;
            while (subChoice != -1)
            {
                cout << "Options: " << endl;
                cout << "[01] - Add new Expense" << endl;
                cout << "[02] - View an existing Expense" << endl;
                cout << "[03] - Delete an existing Expense" << endl;
                cout << "[-1] - Back" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1)
                {
                    Expense expense;
                    expense.inputDetails();
                    expenseManager.addExpense(expense);
                }
                else if (subChoice == 2)
                {
                    expenseManager.getExpenseDetails().printDetails();
                }
                else if (subChoice == 3)
                {
                    expenseManager.removeExpense(expenseManager.getExpenseDetails());
                }
            }
        }
        else if (choice == 2)
        {
            int subChoice = 0;
            while (subChoice != -1)
            {
                cout << "Options: " << endl;
                cout << "[01] - Add new Commodity Type" << endl;
                cout << "[02] - View existing Commodity Types" << endl;
                cout << "[03] - Delete an existing Commodity Type" << endl;
                cout << "[-1] - Back" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1)
                {
                    string commodityType;
                    cout << "Enter Commodity Type: ";
                    cin >> commodityType;
                    expenseManager.addCommodityType(commodityType);
                }
                else if (subChoice == 2)
                {
                    expenseManager.printCommodityTypes();
                }
                else if (subChoice == 3)
                {
                    expenseManager.printCommodityTypes();
                    expenseManager.removeCommodityType(expenseManager.getCommodityType());
                }
            }
        }
        else
        {
            cout << "Exiting..." << endl;
        }
    }
}
