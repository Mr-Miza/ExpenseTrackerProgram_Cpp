#include <iostream>
#include <fstream>
#include <ctime>

void writeOutput( int currentAmount, std::string expenseName, int expenseAmount) {
    std::ofstream ExpensesFile("Expenses.txt", std::ios::app) ;

    if (ExpensesFile.is_open()){
    std::time_t now = std::time(nullptr);
    char DateStr [50] ; // Declare a character array to hold the formatted date and time string
    std::strftime(DateStr, sizeof(DateStr), "%c", std::localtime(&now));
    //std::strftime --> This function formats the date and time according to a specified format and stores the result in a character array.
    //"%c": This is the format specifier used by strftime. The "%c" specifier represents the preferred date and time representation for the current locale.

        ExpensesFile << "Date : " << DateStr << std::endl;
        ExpensesFile << "Current Amount : " << currentAmount << std::endl;
        ExpensesFile << "Expense Name : " << expenseName << std::endl; 
        ExpensesFile << "Expense Amount : " << expenseAmount << std::endl;
         if ( currentAmount >= expenseAmount) {
        currentAmount = currentAmount - expenseAmount;
        std::cout << "Your current amount is: " << currentAmount << std::endl;
        }
        ExpensesFile << "Total Expenses: " << currentAmount ;
        ExpensesFile << "\n ---------------------------------------------- \n" << std::endl;
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
    int listNumber;

    std::cout << "This is a program to track expenses." << std::endl;
    std::cout << "Enter the amount of expenes u made.\n --If you forgot smth re run the program.\n A number is required: " << std::endl ;
    std::cin >> listNumber ;
    
    if(listNumber == 0 ){
        return 0;
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Enter amount of money u have: " << std::endl;
    std::cin >> currentAmount;
    std::cout << " Your amount is: " << currentAmount << std::endl;

    for(int i=0 ; i < listNumber ;i++ ){

    std::cout << "Enter expense name: " << std::endl;
    std::cin >> expenseName ;

    std::cout << "Enter expense amount: " << std::endl;
    std::cin >> expenseAmount ;

    writeOutput(currentAmount, expenseName, expenseAmount);

    }


    return 0;
} 