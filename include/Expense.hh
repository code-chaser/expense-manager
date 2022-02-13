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
    int id;
    Date date;
    Commodity commodity;
    double quantity;
    double amount;
public:
    Expense();
    Expense(int, Date, Commodity, double, double);
    //setter methods
    void setId(int);
    void setDate(Date);
    void setCommodity(Commodity);
    void setQuantity(double);
    void setAmount(double);
    //getter methods
    int getId();
    Date getDate();
    Commodity getCommodity();
    double getQuantity();
    double getAmount();
    //other methods
    void inputDetails();
    void printDetails();
    void printDetails(vector<Expense>);
};

#endif // !EXPENSE