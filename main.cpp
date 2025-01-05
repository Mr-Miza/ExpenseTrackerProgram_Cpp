#include <iostream>
#include <fstream>
#include <ctime>

void writeOutput( int currentAmount, std::string expenseName, int expenseAmount) {
    std::ofstream ExpensesFile("Expenses.txt") ;

    if (ExpensesFile.is_open()){
    std::time_t now = std::time(nullptr);
    char DateStr [50] ;
    std::strftime(DateStr, sizeof(DateStr), "%c", std::localtime(&now));

        ExpensesFile << "Date : " << DateStr << std::endl;
        ExpensesFile << "Current Amount : " << currentAmount << std::endl;
        ExpensesFile << "Expense Name : " << expenseName << std::endl; 
        ExpensesFile << "Expense Amount : " << expenseAmount << std::endl;
        ExpensesFile.close();
    }   
    else {
        std::cout << "Unable to open file" << std::endl;    

    }
}

int main() {

    int currentAmount =0 ;
    std::string expenseName;
    int expenseAmount = 0;

    std::cout << "This is a program to track expenses." << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Enter amount of money u have: " << std::endl;
    std::cin >> currentAmount;
    std::cout << " Your amount is: " << currentAmount << std::endl;
    std::cout << "Enter expense name: " << std::endl;
    std::cin >> expenseName ;
    std::cout << " Your expense name is: " << expenseName << std::endl;

    std::cout << "Enter expense amount: " << std::endl;
    std::cin >> expenseAmount ;
    std::cout << " Your expense amount is: " << expenseAmount << std::endl;

    writeOutput(currentAmount, expenseName, expenseAmount);

    if ( currentAmount >= expenseAmount) {
        currentAmount = currentAmount - expenseAmount;
        std::cout << "Your current amount is: " << currentAmount << std::endl;
    }



  
    return 0;
} 