#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee()
{

}

OfficeEmployee::OfficeEmployee(int id)
{
    this -> employeeID = id;
}

OfficeEmployee::OfficeEmployee(int id, string name)
{
    this -> employeeID = id;
    this -> fullName = name;
}

OfficeEmployee::OfficeEmployee(int id, string name, string date)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
}

OfficeEmployee::OfficeEmployee(int id, string name, string date, string addr)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
    this -> address = addr;
}   

void OfficeEmployee::inputEmployee() 
{
    Employee::inputEmployee();
    cout << "Enter number of working days: ";
    cin >> workingDays;
}

void OfficeEmployee::printEmployee() 
{
    Employee::printEmployee();
    cout << "Working Days: " << workingDays << endl;
}

double OfficeEmployee::computeSalary() 
{
    double payRatePerDay = 300000.0;
    return workingDays * payRatePerDay;
}