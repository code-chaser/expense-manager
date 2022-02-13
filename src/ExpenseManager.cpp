#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
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
    int cnt = 0;
    for (int i = 0; i < expenses.size(); i++)
    {
        cnt += (expenses[i].getDate().value() == expense.getDate().value());
        if (expenses[i].getDate().value() > expense.getDate().value())
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
    expenses.erase(expense.getId());
    cout << "\nExpense with ID " << expense.getId() << " removed successfully!\n"
         << endl;
    return;
}
Expense ExpenseManager::getExpenseDetails()
{
    int choice;
    cout << "Search expense by: " << endl;
    cout << "[01] - ID" << endl;
    cout << "[02] - Date" << endl;
    cout << "[03] - Commodity Type" << endl;
    cout << "[04] - Commodity Name" << endl;
    cout << "[05] - Amount Range" << endl;
    cout << "[-1] - Back" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice > 5 || (choice < 1 && choice != -1))
    {
        cout << "\nInvalid choice.\nEnter a valid choice: ";
        cin >> choice;
    }
    if (choice == -1)
        return Expense();
    else if (choice == 1)
    {

        int idReq;
        cout << "Enter ID: ";
        cin >> idReq;
        if (expenses.find(idReq) != expenses.end())
        {
            return expenses[idReq];
        }
        else
        {
            cout << "No expense found with ID: " << idReq << endl;
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
    }
    else if (choice == 2)
    {

        Date dateReq;
        cout << "Enter Date: ";
        dateReq.inputDetails();
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getDate().value() == dateReq.value())
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with date " << dateReq.dateToString() << ".\n"
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
            cout << matchingExpenses.size() << " matching records found with date " << dateReq.dateToString() << ".\n"
                 << endl;
            Expense E = Expense();
            E.printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                int idReq;
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
    else if (choice == 3)
    {
        string commodityTypeReq;
        cout << "Enter Commodity Type: ";
        cin >> commodityTypeReq;
        vector<Expense> matchingExpenses;
        for (auto expense : expenses)
            if (expense.second.getCommodity().getType() == commodityTypeReq)
                matchingExpenses.push_back(expense.second);
        if (matchingExpenses.size() == 0)
        {
            cout << "\nNo matching records found with commodity type " << commodityTypeReq << ".\n"
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
            cout << matchingExpenses.size() << " matching records found with commodity type " << commodityTypeReq << ".\n"
                 << endl;
            Expense E = Expense();
            E.printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                int idReq;
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
            E.printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                int idReq;
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
        int lowerLimitReq, upperLimitReq;
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
            E.printDetails(matchingExpenses);
            char choice = 'Y';
            while (choice == 'Y')
            {
                cout << "\nEnter ID of the required expense: ";
                int idReq;
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
void ExpenseManager::addCommodityType(string type)
{
    for (auto commodityType : commodityTypes)
        if (commodityType.second == type)
        {
            return;
        }
    commodityTypes[commodityTypes.size()] = type;
    return;
}
void ExpenseManager::removeCommodityType(string type)
{
    for (auto commodityType : commodityTypes)
        if (commodityType.second == type)
        {
            commodityTypes.erase(commodityType.first);
            return;
        }
    return;
}
void ExpenseManager::printCommodityTypes()
{
    cout << "\nCommodity Types:\n\n";
    for (auto commodityType : commodityTypes)
        cout << commodityType.first << ": " << commodityType.second << endl;
    cout << endl;
    return;
}
string ExpenseManager::getCommodityType()
{
    int id;
    cout << "\nEnter ID of required Commodity Type: ";
    cin >> id;
    return commodityTypes[id];
}
void ExpenseManager::readFromCSV()
{
    ifstream file;
    file.open("./../data/expenseSheet.csv");
    string line;
    getline(file, line); // skip first line
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
        expenses[id] = Expense(id, date, commodity, quantity, amount);
    }
    file.close();
    file.open("./../data/commodityTypes.csv");
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
    file.open("./../data/temp.csv");
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
    remove("./../data/expenseSheet.csv");
    rename("./../data/temp.csv", "./../data/expenseSheet.csv");

    file.open("./../data/temp.csv");
    file << "S.No.,Commodity Type\n";
    for (auto commodityType : commodityTypes)
    {
        file << commodityType.first + 1 << ",";
        file << commodityType.second << "\n";
    }
    file.close();
    remove("./../data/commodityTypes.csv");
    rename("./../data/temp.csv", "./../data/commodityTypes.csv");

    return;
}