#include "Employee.h"

Employee::Employee()
{

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
    do {
        cout << "\nEnter employee ID: ";
        cin >> employeeID;
    } while (employeeID <= 0);

    cout << "Enter full name: ";
    cin.ignore(1);
    getline(cin, fullName);
    cout << "Enter hire date: ";
    getline(cin, hireDate);
    cout << "Enter address: ";
    getline(cin, address);
}

void Employee::printEmployee()
{
    cout << "\nEmployee ID: " << employeeID << endl;
    cout << "Full Name: " << fullName << endl;
    cout << "Hire Date: " << hireDate << endl;
    cout << "Address: " << address << endl;
    cout << "Salary: " << computeSalary() << endl;
}

double Employee::computeSalary()
{
    return 0;
}
