#ifndef EXPENSE
#define EXPENSE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "./Date.hh"
#include "./Commodity.hh"

class Expense
{
private:
    long long id;
    Date date;
    Commodity commodity;
    double quantity;
    double amount;
public:
    Expense();
    Expense(long long, Date, Commodity, double, double);
    //setter methods
    void setId(long long);
    void setDate(Date);
    void setCommodity(Commodity);
    void setQuantity(double);
    void setAmount(double);
    //getter methods
    long long getId();
    Date getDate();
    Commodity getCommodity();
    double getQuantity();
    double getAmount();
    //other methods
    void inputDetails();
    void printDetails();
    static void printDetails(vector<Expense>);
};

#endif // !EXPENSE