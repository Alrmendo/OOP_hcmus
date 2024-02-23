#include "Worker.h"

Worker::Worker()
{

}

Worker::Worker(int id)
{
    this -> employeeID = id;
}

Worker::Worker(int id, string name)
{
    this -> employeeID = id;
    this -> fullName = name;
}

Worker::Worker(int id, string name, string date)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
}

Worker::Worker(int id, string name, string date, string addr)
{
    this -> employeeID = id;
    this -> fullName = name;
    this -> hireDate = date;
    this -> address = addr;
}

void Worker::inputEmployee() 
{
    Employee::inputEmployee();
    cout << "Enter number of produced items: ";
    cin >> producedItems;
}

void Worker::printEmployee() 
{
    Employee::printEmployee();
    cout << "Produced Items: " << producedItems << endl;
}

double Worker::computeSalary() 
{
    return Employee::computeSalary() + producedItems * 20000;
}