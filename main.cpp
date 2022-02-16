#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <stdlib.h>
using namespace std;

#include "./include/ExpenseManager.hh"
#include "./include/Expense.hh"
#include "./include/Commodity.hh"
#include "./include/Date.hh"

#ifdef WIN32
#define clrscr() system("cls")
#define pause() system("pause")
#endif
#ifdef __linux__
#define clrscr() system("clear")
#define pause() cout << "Press enter to continue...", cin.get()
#endif

/*

M E N U :-

Options:
[01] - Manage Expenses
    [01] - Add new Expense
    [02] - View existing Expenses
    [03] - Delete an existing Expense
    [04] - Calculate Expenditure
    [05] - View all expenses
    [-1] - Back
[02] - Manage Commodity Types
    [01] - Add new Commodity Type
    [02] - View existing Commodity Types
    [03] - Delete an existing Commodity Type
    [-1] - Back
[-1] - Exit

*/

int main()
{
    ExpenseManager::readFromCSV();
    long long choice = 0;
    while (choice != -1)
    {
        clrscr();
        cout << "\n\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "--- || E X P E N S E   M A N A G E R || ---\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\n";
        cout << "|~~~~~~~~~~~~~~~~~ HOME ~~~~~~~~~~~~~~~~~~|";
        cout << "\n\n";
        cout << "Options:\n"
             << endl;
        cout << "[01] - Manage Expenses" << endl;
        cout << "[02] - Manage Commodity Types\n"
             << endl;
        cout << "[-1] - Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 2 || choice < 1) && choice != -1)
        {
            cout << "\nInvalid choice.\nPlease enter again: ";
            cin >> choice;
        }
        cout << "\n-------------------------------------------\n\n";
        if (choice == 1)
        {
            long long subChoice = 0;
            while (subChoice != -1)
            {
                clrscr();
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "--- || E X P E N S E   M A N A G E R || ---\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\n\n";
                cout << "|~~~~~~~~~~~~ MANAGE EXPENSES ~~~~~~~~~~~~|";
                cout << "\n\n";
                cout << "Options:\n"
                     << endl;
                cout << "[01] - Add new Expense" << endl;
                cout << "[02] - View an existing Expense" << endl;
                cout << "[03] - Delete an existing Expense" << endl;
                cout << "[04] - Calculate Expenditure" << endl;
                cout << "[05] - View all Expenses\n"
                     << endl;
                cout << "[-1] - Back\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                while ((subChoice < 1 || subChoice > 5) && subChoice != -1)
                {
                    cout << "Invalid choice. Please enter again: ";
                    cin >> subChoice;
                }
                cout << "\n-------------------------------------------\n\n";
                if (subChoice == 1)
                {
                    Expense expense;
                    expense.inputDetails(1);
                    ExpenseManager::addExpense(expense);
                    cout << "\n\nAdd another expense with the same date? (Y for Yes || N for No): ";
                    char choice;
                    cin >> choice;
                    while (choice != 'Y' && choice != 'N')
                    {
                        cout << "Invalid choice. Please enter again: ";
                        cin >> choice;
                    }
                    cout << "\n\n";
                    while (choice == 'Y')
                    {
                        Date _date = expense.getDate();
                        expense.inputDetails(0);
                        expense.setDate(_date);
                        ExpenseManager::addExpense(expense);
                        cout << "\n\nAdd another expense with the same date? (Y for Yes || N for No): ";
                        cin >> choice;
                        while (choice != 'Y' && choice != 'N')
                        {
                            cout << "Invalid choice. Please enter again: ";
                            cin >> choice;
                        }
                        cout << "\n\n";
                    }
                }
                else if (subChoice == 2)
                {
                    Expense expense = ExpenseManager::getExpenseDetails();
                    if (expense.getId() != -1)
                        expense.printDetails();
                }
                else if (subChoice == 3)
                {
                    Expense expense = ExpenseManager::getExpenseDetails();
                    if (expense.getId() != -1)
                        ExpenseManager::removeExpense(expense);
                }
                else if (subChoice == 4)
                {
                    ExpenseManager::calculateExpenditure();
                }
                else if (subChoice == 5)
                {
                    ExpenseManager::printExpenses();
                }
                cout << "\n\n-------------------------------------------\n\n";
                if (subChoice != -1)
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    pause();
                }
            }
        }
        else if (choice == 2)
        {
            long long subChoice = 0;
            while (subChoice != -1)
            {
                clrscr();
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "--- || E X P E N S E   M A N A G E R || ---\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                cout << "\n\n";
                cout << "|~~~~~~~~ MANAGE COMMODITY TYPES ~~~~~~~~~|";
                cout << "\n\n";
                cout << "Options:\n"
                     << endl;
                cout << "[01] - Add new Commodity Type" << endl;
                cout << "[02] - View existing Commodity Types" << endl;
                cout << "[03] - Delete an existing Commodity Type\n"
                     << endl;
                cout << "[-1] - Back\n"
                     << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                while ((subChoice < 1 || subChoice > 3) && subChoice != -1)
                {
                    cout << "Invalid choice. Please enter again: ";
                    cin >> subChoice;
                }
                cout << "\n-------------------------------------------\n\n";
                if (subChoice == 1)
                {
                    string commodityType;
                    cout << "Enter Commodity Type: ";
                    getline(cin >> ws, commodityType);
                    ExpenseManager::addCommodityType(commodityType);
                }
                else if (subChoice == 2)
                {
                    ExpenseManager::printCommodityTypes();
                }
                else if (subChoice == 3)
                {
                    ExpenseManager::printCommodityTypes();
                    ExpenseManager::removeCommodityType(ExpenseManager::getCommodityType());
                }
                cout << "\n\n-------------------------------------------\n\n";

                if (subChoice != -1)
                {
                    if (subChoice - 1)
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    pause();
                }
            }
        }
        else if (choice == -1)
        {
            cout << "Exiting...\n"
                 << endl;
            cout << "-------------------------------------------\n\n";
        }
    }
    ExpenseManager::writeToCSV();
    clrscr();
    return 0;
}
