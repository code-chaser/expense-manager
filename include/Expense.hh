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
    int id;
    Date date;
    Commodity commodity;
    int quantity;
    int amount;
public:
    Expense();
    Expense(int, Date, Commodity, int, int);
    //setter methods
    void setId(int);
    void setDate(Date);
    void setCommodity(Commodity);
    void setQuantity(int);
    void setAmount(int);
    //getter methods
    int getId();
    Date getDate();
    Commodity getCommodity();
    int getQuantity();
    int getAmount();
    //other methods
    void inputDetails();
    void printDetails();
};

#endif // !EXPENSE