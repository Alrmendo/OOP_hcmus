#include "Employee.h"

Employee::Employee()
{
    employeeID = 0;
    fullName = "";
    hireDate = "";
    address = "";
}

Employee::Employee(int id)
{
    this -> employeeID = id;
}

Employee::Employee(int id, string name)
{
    this -> employeeID = id;
    this -> fullName = name;
}

Employee::Employee(int id, string name, string date)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
}

Employee::Employee(int id, string name, string date, string addr)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
    this -> address = addr;
}   

void Employee::inputEmployee()
{
    cout << "Enter employee ID: ";
    cin >> employeeID;
    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter hire date: ";
    getline(cin, hireDate);
    cout << "Enter address: ";
    getline(cin, address);
}

void Employee::printEmployee()
{
    cout << "Employee ID: " << employeeID << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Address: " << address << endl;
}

double Employee::computeSalary()
{
    return 0.0;
}
