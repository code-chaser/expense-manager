#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <thread>
#include <chrono>
using namespace std;

#include "./../include/ExpenseManager.hh"
#include "./../include/Date.hh"
#include "./../include/Commodity.hh"
#include "./../include/Expense.hh"

#define wait(x) this_thread::sleep_for(chrono::milliseconds(x))

map<long long, Expense> ExpenseManager::expenses = map<long long, Expense>();
map<long long, string> ExpenseManager::commodityTypes = map<long long, string>();

ExpenseManager::ExpenseManager()
{
}
void ExpenseManager::addExpense(Expense expense)
{
    long long cnt = 0;
    for (auto E : expenses)
    {
        if (E.second.getDate().value() == expense.getDate().value())
            cnt++;
        else if (E.second.getDate().value() > expense.getDate().value())
            break;
    }
    expense.setId(expense.getDate().value() * 1000 + cnt);
    expenses[expense.getId()] = expense;
    cout << "\nExpense added successfully!" << endl;
    cout << "Expense ID is " << expense.getId() << "\n"
         << endl;
    return;
}
void ExpenseManager::removeExpense(Expense expense)
{
    Date date = expense.getDate();
    long long id = expense.getId();
    expenses.erase(expense.getId());
    cout << "\nExpense with ID " << expense.getId() << " removed successfully!\n\n"
         << endl;
    long long cnt = 0;
    for (auto E : expenses)
    {
        if (E.second.getDate().value() == date.value() && E.second.getId() > id)
            cnt++;
        else if (E.second.getDate().value() > date.value())
            break;
    }
    for (long long i = 0; i < cnt; i++)
        expenses[i + id] = expenses[i + id + 1], expenses[i + id].setId(i + id);
    expenses.erase(cnt + id);
    return;
}
Expense ExpenseManager::getExpenseDetails()
{
    long long choice;
    cout << "\n\n-------------------------------------------\n\n";
    cout << "Search expense by: " << endl;
    cout << "[01] - ID" << endl;
    cout << "[02] - Date" << endl;
    cout << "[03] - Commodity Type" << endl;
    cout << "[04] - Commodity Name" << endl;
    cout << "[05] - Amount Range\n"
         << endl;
    cout << "[-1] - Back\n"
         << endl;
    cout << "-------------------------------------------\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice > 5 || (choice < 1 && choice != -1))
    {
        cout << "\nInvalid choice.\nEnter a valid choice: ";
        cin >> choice;
    }

    cout << "\n-------------------------------------------\n\n";
    if (choice == -1)
        return Expense();
    else if (choice == 1)
    {

        long long idReq;
        cout << "Enter ID: ";
        cin >> idReq;
        if (expenses.find(idReq) != expenses.end())
        {
            return expenses[idReq];
        }
        else
        {
            cout << "\n\nNo expense found with ID: " << idReq << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
    }
    else if (choice == 2)
    {

        Date dateReq;
        cout << "\nEnter Date: ";
        dateReq.inputDetails();
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getDate().value() == dateReq.value())
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with date " << dateReq.dateToString() << ".\n"
                 << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << "\n"
                 << matchingExpenses.size() << " matching records found with date " << dateReq.dateToString() << ".\n"
                 << endl;
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "\nNo expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "\nDo you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "\nEnter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 3)
    {
        string commodityTypeReq;
        cout << "\nEnter Commodity Type: ";
        cin >> commodityTypeReq;
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getCommodity().getType() == commodityTypeReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with commodity type " << commodityTypeReq << ".\n"
                 << endl;
            cout << "\nDo you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << "\n"
                 << matchingExpenses.size() << " matching records found with commodity type " << commodityTypeReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "\nNo expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 4)
    {
        string commodityNameReq;
        cout << "Enter Commodity Name: ";
        cin >> commodityNameReq;
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getCommodity().getName() == commodityNameReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with commodity name " << commodityNameReq << ".\n"
                 << endl;
            cout << "Do you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << matchingExpenses.size() << " matching records found with commodity name " << commodityNameReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "No expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    else if (choice == 5)
    {
        long long lowerLimitReq, upperLimitReq;
        cout << "Enter Amount Range:\n";
        cout << "Lower Limit: ";
        cin >> lowerLimitReq;
        cout << "Upper Limit: ";
        cin >> upperLimitReq;
        if (lowerLimitReq > upperLimitReq)
            swap(lowerLimitReq, upperLimitReq);
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getAmount() >= lowerLimitReq && expense.second.getAmount() <= upperLimitReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with amount range " << lowerLimitReq << " to " << upperLimitReq << ".\n"
                 << endl;
            cout << "Do you want to try again? (Y for Yes || N for No): ";
            char choice;
            cin >> choice;
            while (choice != 'Y' && choice != 'N')
            {
                cout << "Enter valid choice (Y or N): ";
                cin >> choice;
            }
            return (choice == 'Y' || choice == 'y') ? getExpenseDetails() : Expense();
        }
        else
        {
            cout << matchingExpenses.size() << " matching records found with amount range " << lowerLimitReq << " to "
                 << upperLimitReq << ".\n"
                 << endl;
            Expense E = Expense();
            Expense::printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                long long idReq;
                cin >> idReq;
                for (auto expense : matchingExpenses)
                    if (expense.getId() == idReq)
                        return expense;
                cout << "No expense from the list above has ID " << idReq << ".\n"
                     << endl;
                cout << "Do you want to try again? (Y for Yes || N for No): ";
                cin >> choice;
                while (choice != 'Y' && choice != 'N')
                {
                    cout << "Enter valid choice (Y or N): ";
                    cin >> choice;
                }
            }
        }
    }
    return Expense();
}
void ExpenseManager::calculateExpenditure()
{
    long long choice;
    cout << "Options: " << endl;
    cout << "[01] - Between two dates" << endl;
    cout << "[02] - Total Expenditure from the begining of the records" << endl;
    cout << "[-1] - Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while ((choice > 4) || (choice < 1 && choice != -1))
    {
        cout << "Enter valid choice: ";
        cin >> choice;
    }
    if (choice == -1)
        return;
    else if (choice == 1)
    {
        Date startDate, endDate;
        cout << "Enter start date:\n";
        startDate.inputDetails();
        cout << "Enter end date:\n";
        endDate.inputDetails();
        cout << "Calculate expenditure from " << startDate.dateToString() << " to " << endDate.dateToString() << ": " << endl;
        cout << "[01] - By Commodity name" << endl;
        cout << "[02] - By Commodity type" << endl;
        cout << "[03] - For all commodities" << endl;
        cout << "[-1] - Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 3) || (choice < 1 && choice != -1))
        {
            cout << "Enter valid choice: ";
            cin >> choice;
        }
        if (choice == -1)
            return calculateExpenditure();
        else if (choice == 1)
        {
            string commodityNameReq;
            cout << "Enter Commodity Name: ";
            getline(cin >> ws, commodityNameReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value() &&
                    expense.second.getCommodity().getName() == commodityNameReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.value() << " to " << endDate.value() << " for commodity " << commodityNameReq
                 << " is " << totalExpenditure << endl;
        }
        else if (choice == 2)
        {
            string commodityTypeReq;
            cout << "Enter Commodity Type: ";
            getline(cin >> ws, commodityTypeReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value() &&
                    expense.second.getCommodity().getType() == commodityTypeReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.value() << " to " << endDate.value() << " for commodity type " << commodityTypeReq
                 << " is " << totalExpenditure << endl;
        }
        else if (choice == 3)
        {
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getDate().value() >= startDate.value() && expense.second.getDate().value() <= endDate.value())
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure from " << startDate.value() << " to " << endDate.value() << " is " << totalExpenditure << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Calculate expenditure from the begining of the records: " << endl;
        cout << "[01] - By Commodity name" << endl;
        cout << "[02] - By Commodity type" << endl;
        cout << "[03] - For all commodities" << endl;
        cout << "[-1] - Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while ((choice > 3) || (choice < 1 && choice != -1))
        {
            cout << "Enter valid choice: ";
            cin >> choice;
        }
        if (choice == -1)
            return calculateExpenditure();
        else if (choice == 1)
        {
            string commodityNameReq;
            cout << "Enter Commodity Name: ";
            getline(cin >> ws, commodityNameReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getCommodity().getName() == commodityNameReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure for commodity " << commodityNameReq << " is " << totalExpenditure << endl;
        }
        else if (choice == 2)
        {
            string commodityTypeReq;
            cout << "Enter Commodity Type: ";
            getline(cin >> ws, commodityTypeReq);
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                if (expense.second.getCommodity().getType() == commodityTypeReq)
                    totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure for commodity type " << commodityTypeReq << " is " << totalExpenditure << endl;
        }
        else if (choice == 3)
        {
            long long totalExpenditure = 0;
            for (auto expense : expenses)
                totalExpenditure += expense.second.getAmount();
            cout << "Total expenditure is " << totalExpenditure << endl;
        }
    }
}
void ExpenseManager::printExpenses()
{
    vector<Expense> allExpenses;
    for (auto expense : expenses)
        allExpenses.push_back(expense.second);
    Expense::printDetails(allExpenses);
    return;
}
void ExpenseManager::addCommodityType(string type)
{
    for (auto commodityType : commodityTypes)
        if (commodityType.second == type)
            return;
    commodityTypes[commodityTypes.size()] = type;
    return;
}
void ExpenseManager::removeCommodityType(string type)
{
    for (long long i = 0; i < commodityTypes.size(); i++)
        if (commodityTypes[i] == type)
        {
            for (long long j = i; j < commodityTypes.size() - 1; j++)
                commodityTypes[j] = commodityTypes[j + 1];
            commodityTypes.erase(commodityTypes.size() - 1);
            return;
        }
    return;
}
void ExpenseManager::printCommodityTypes()
{
    cout << "\nExisting Commodity Types:\n\n";
    for (auto commodityType : commodityTypes)
        cout << left << setw(log10((int)(commodityTypes.size() > 1) ? commodityTypes.size() - 1 : 1)) << commodityType.first,
            cout << ": " << commodityType.second << endl;
    cout << endl;
    return;
}
string ExpenseManager::getCommodityType()
{
    long long id;
    cout << "\nEnter ID of required Commodity Type: ";
    cin >> id;
    if (id < 0 || id >= commodityTypes.size())
    {
        cout << "Invalid ID.\n";
        return "";
    }
    return commodityTypes[id];
}
void ExpenseManager::readFromCSV()
{
    ifstream file;
    file.open("./data/expenseSheet.csv");
    string line;
    getline(file, line); // skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        long long id;
        Date date;
        Commodity commodity;
        long long quantity;
        long long amount;
        getline(ss, token, ',');
        id = stoll(token);
        getline(ss, token, ',');
        date.stringToDate(token);
        getline(ss, token, ',');
        commodity.setName(token);
        getline(ss, token, ',');
        commodity.setType(token);
        getline(ss, token, ',');
        commodity.setRate(stoll(token));
        getline(ss, token, ',');
        quantity = stoll(token);
        getline(ss, token, ',');
        amount = stoll(token);
        expenses[id] = Expense(id, date, commodity, quantity, amount);
    }
    file.close();
    file.open("./data/commodityTypes.csv");
    getline(file, line); // skip first line
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        getline(ss, token, ',');
        commodityTypes[commodityTypes.size()] = token;
    }
    return;
}
void ExpenseManager::writeToCSV()
{
    ofstream file;
    file.open("./data/temp.csv");
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
    remove("./data/expenseSheet.csv");
    rename("./data/temp.csv", "./data/expenseSheet.csv");

    file.open("./data/temp.csv");
    file << "S.No.,Commodity Type\n";
    for (auto commodityType : commodityTypes)
    {
        file << commodityType.first << ",";
        file << commodityType.second << "\n";
    }
    file.close();
    remove("./data/commodityTypes.csv");
    rename("./data/temp.csv", "./data/commodityTypes.csv");

    return;
}