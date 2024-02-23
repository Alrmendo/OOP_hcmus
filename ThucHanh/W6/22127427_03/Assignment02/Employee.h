#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
    int employeeID;
    string fullName;
    string hireDate;
    string address;

public:
    Employee();
    Employee(int);
    Employee(int, string);
    Employee(int, string, string);
    Employee(int, string, string, string);

    void inputEmployee();
    void printEmployee();
    virtual double computeSalary();
};

#endif