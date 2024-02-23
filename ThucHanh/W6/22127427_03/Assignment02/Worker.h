#ifndef WORKER_H
#define WORKER_H
#include "Employee.h"

class Worker : public Employee
{
protected:
    int producedItems;

public:
    Worker();
    Worker(int);
    Worker(int, string);
    Worker(int, string, string);
    Worker(int, string, string, string);
    Worker(int, string, string, string, int);

    void inputEmployee();
    void printEmployee();
    double computeSalary();
};

#endif