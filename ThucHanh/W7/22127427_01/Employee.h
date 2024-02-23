#pragma once
#include <iostream>
#include <string>
#include <vector>

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

    virtual void inputEmployee();
    virtual void printEmployee();
    virtual double computeSalary();
};