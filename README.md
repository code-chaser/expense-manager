# expense-manager &nbsp; [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/code-chaser/expense-manager/blob/main/LICENSE) [![Download Code](https://img.shields.io/badge/Download-Code-red.svg)](https://github.com/code-chaser/expense-manager/archive/refs/heads/main.zip)
a simple tool that can be used to keep track of daily household expenses, made using basic OOPs features in C++ and a little bit of file handling
___

<!--
<table align="center" style="width:100%">
   <thead></thead>
   <tbody>
      <tr>
         <td rowspan=4><h3>CHECK OUT</h3></td>
         <td><a href="#build--execute">BUILD & EXECUTE</a></td>
      </tr>
      <tr>
         <td><a href="#screenshots">SCREENSHOTS</a></td>
      </tr>
      <tr>
         <td><a href="#class-design">CLASS DESIGN</a></td>
      </tr>
      <tr>
         <td><a href="#tech-stack">TECH STACK</a></td>
      </tr>
   </tbody>
</table>

___
-->


### CHECK OUT
- [BUILD & EXECUTE](#build--execute)
- [SCREENSHOTS](#screenshots)
- [CLASS DESIGN](#class-design)
- [TECH STACK](#tech-stack)

___

<br>


## BUILD & EXECUTE
- For Windows users: firstly install ` make ` for executing ` makefile `, from this [link](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows);
- For Linux users: ` make ` generally comes pre-installed;
   - if not, then run the following command: ` sudo apt-get install make `
   <br>
- Now, run the following commands:
   - for building executable file: 
  ```bash
     make all        # universal;
  ```
   - for executing it:
  ```bash
     make run        # universal;
  ```
   - for deleting executable file:
  ```bash
     make clean      # for linux/macOS;
     make clean(win) # for windows;
  ```
___

<br>

## SCREENSHOTS

<br>

<div style="text-align:center"><img src="https://user-images.githubusercontent.com/63065397/153944917-7bf7b1a8-0a6a-406e-9a19-3d47a68394ed.png" /></div>

<br>

<div style="text-align:center"><img src="https://user-images.githubusercontent.com/63065397/153945403-dcc8e1ba-360b-4b32-ad78-fd911214e2ab.png" /></div>

<br>

<div style="text-align:center"><img src="https://user-images.githubusercontent.com/63065397/153945727-4546630a-ffbb-4380-8c34-102b90f66e66.png" /></div>

<br>





___

<br>


## CLASS DESIGN

![ClassDiagram](https://user-images.githubusercontent.com/63065397/153952270-def56c4f-2c9b-4fa1-ac93-064e7347fcbd.png)

___

<br>

## CLASS DESIGN
   ***- rendered by [mermaid](https://mermaid-js.github.io/mermaid/#/classDiagram)***


```mermaid
classDiagram
   direction LR
   class ExpenseManager{
      -$map~long long, Expense~ expenses
      -$map~long long, string~ commodityTypes
      +$addExpense(Expense) void
      +$removeExpense(Expense) void
      +$getExpenseDetails() Expense
      +$calculateExpenditure() void
      +$printExpenses() void
      +$addCommodityType(string) void
      +$removeCommodityType(string) void
      +$getCommodityType() string
      +$printCommodityTypes() void
      +$readFromCSV() void
      +$writeToCSV() void
   }
   class Expense{
      -long long id
      -Date date
      -Commodity commodity
      -double quantity
      -double amount
      +Expense() void
      +Expense(long long, Date, Commodity, double, double) void
      +setId(long long) void
      +setDate(Date) void
      +setCommodity(Commodity) void
      +setQuantity(double) void
      +setAmount(double) void
      +getId() long long
      +getDate() Date
      +getCommodity() Commodity
      +getQuantity() double
      +getAmount() double
      +inputDetails() void
      +printDetails() void
      +$printDetails(vector~Expense~) void
   }
   class Commodity{
      -string name
      -string type
      -double rate
      +Commodity() void
      +Commodity(string, string, double) void
      +setName(string) void
      +setType(string) void
      +setRate(double) void
      +getName() string
      +getType() string
      +getRate() double
      +inputDetails() void
      +printDetails() void
      
   }
   class Date{
      -int day
      -int month
      -int year
      +Date() void
      +Date(int, int, int) void
      +setDay(int) void
      +setMonth(int) void
      +setYear(int) void
      +getDay() int
      +getMonth() int
      +getYear() int
      +inputDetails() void
      +printDetails() void
      +stringToDate(string) void
      +dateToString() string
      +value() int
      +validateDate() bool
   }
   ExpenseManager *-- Expense
   Expense *-- Commodity
   Expense *-- Date
   link ExpenseManager "https://github.com/code-chaser/expense-manager/blob/main/include/ExpenseManager.hh" "click to see declaration"
   link Expense "https://github.com/code-chaser/expense-manager/blob/main/include/Expense.hh" "click to see declaration"
   link Commodity "https://github.com/code-chaser/expense-manager/blob/main/include/Commodity.hh" "click to see declaration"
   link Date "https://github.com/code-chaser/expense-manager/blob/main/include/Date.hh" "click to see declaration"
```

___
### TECH STACK
- C++

___
> #### _Happy Expenditures!! 🤪_
___
