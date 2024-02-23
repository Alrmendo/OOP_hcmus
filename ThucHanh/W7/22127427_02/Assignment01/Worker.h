#pragma once
#include "Employee.h"

class Worker : public Employee
{
private:
    int producedItems;

public:
    Worker();
    Worker(int);
    Worker(int, string);
    Worker(int, string, string);
    Worker(int, string, string, string);

    void inputEmployee();
    void printEmployee();
    double computeSalary();
};