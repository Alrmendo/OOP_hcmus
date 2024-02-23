#ifndef OFFICE_EMPLOYEE_H
#define OFFICE_EMPLOYEE_H
#include "Employee.h"

class OfficeEmployee : public Employee
{
protected:
    int workingDays;

public:
    OfficeEmployee();
    OfficeEmployee(int);
    OfficeEmployee(int, string);
    OfficeEmployee(int, string, string);
    OfficeEmployee(int, string, string, string);

    void inputEmployee();
    void printEmployee();
    double computeSalary();
};
#endif