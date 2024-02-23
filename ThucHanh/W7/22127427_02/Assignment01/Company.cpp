#include "Company.h"

void Company::inputList() 
{
    int n;
    int type;
    Employee *e;

    cout << "\nInput company name: ";
    cin >> name;

    cout << "\nInput number of employee: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "\nInput information of employee " << i + 1 << endl;
        cout << "\nType of employee (1: Worker; 2: Office Employee): ";
        cin >> type;

        e = NULL;
        if(type == 1) 
        {
            e = new Worker;
        } 
        else if(type == 2) 
        {
            e = new OfficeEmployee;
        }

        e -> inputEmployee();
        listEmployee.push_back(e);
    }
}

void Company::printInfo() 
{
    cout << "\nCompany: " << name << endl;

    for(int i = 0; i< listEmployee.size(); i++) 
    {
        listEmployee[i] -> printEmployee();
    }
}

double Company::totalSalary() 
{
    double sum = 0;
    for (int i = 0; i < listEmployee.size(); i++) 
    {
        sum += listEmployee[i] -> computeSalary();
    }
    return sum;
}

void Company::highestSalary() 
{
    double biggestSalary = 0;
    for (int i = 0; i < listEmployee.size(); i++) 
    {
        if (biggestSalary <= listEmployee[i] -> computeSalary()) 
        {
            biggestSalary = listEmployee[i] -> computeSalary();
        }
    }

    for (int i = 0; i < listEmployee.size(); i++) 
    {
        if (listEmployee[i] -> computeSalary() == biggestSalary) {
            listEmployee[i] -> printEmployee();
        }
    }
}

Company::~Company() 
{
    for (int i = 0; i< listEmployee.size(); i++) 
    {
        delete listEmployee[i];
        listEmployee[i] = NULL;
    }
}