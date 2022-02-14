all: ./main.cpp ./src/Commodity.cpp ./src/Date.cpp ./src/Expense.cpp ./src/ExpenseManager.cpp
	g++ -o ./bin/expense-manager ./main.cpp ./src/ExpenseManager.cpp ./src/Commodity.cpp ./src/Date.cpp ./src/Expense.cpp
run:
	./bin/expense-manager
clean:
	rm -f ./bin/*
clean(win):
	del /f bin\*