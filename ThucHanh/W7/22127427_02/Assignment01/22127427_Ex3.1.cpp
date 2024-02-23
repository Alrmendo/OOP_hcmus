#include "Company.h"

int main() 
{
    Company c;
    c.inputList();
    c.printInfo();
    cout << endl;
    cout << "Total Salary: " << c.totalSalary();
    cout << "\nList of employee have the highest salary: " << endl;
    c.highestSalary();

    return 0;
}