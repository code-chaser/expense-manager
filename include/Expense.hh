#ifndef EXPENSE
#define EXPENSE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "./Date.hh"
#include "./Commodity.hh"

class Expense
{
private:
    string id;
    Date date; 
    Commodity commodity;
    int quantity;
    int amount;
public:
    Expense();
    Expense(string, Date, Commodity, int, int);
    //setter methods
    void setId(string);
    void setDate(Date);
    void setCommodity(Commodity);
    void setQuantity(int);
    void setAmount(int);
    //getter methods
    string getId();
    Date getDate();
    Commodity getCommodity();
    int getQuantity();
    int getAmount();
    //other methods
    void inputDetails();
    void printDetails();
};

#endif // !EXPENSE