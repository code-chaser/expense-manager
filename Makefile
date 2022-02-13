all: ./main.cpp ./src/Commodity.cpp ./src/Date.cpp ./src/Expense.cpp ./src/ExpenseManager.cpp
	g++ -o ./bin/expense-manager ./main.cpp ./src/Commodity.cpp ./src/Date.cpp ./src/Expense.cpp ./src/ExpenseManager.cpp
run:
	./bin/expense-manager
clean:
	rm -f ./bin/*
clean(win):
	del /f bin\*