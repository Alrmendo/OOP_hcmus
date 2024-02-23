#pragma once
#include "Employee.h"
#include "Worker.h"
#include "OfficeEmployee.h"

class Company
{
private:
    string name;
    vector <Employee*> listEmployee;

public:
    ~Company();
    void inputList();
    void printInfo();
    double totalSalary();
    void highestSalary();
};
