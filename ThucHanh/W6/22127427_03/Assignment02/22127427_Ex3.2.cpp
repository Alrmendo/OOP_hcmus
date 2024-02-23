#include "Worker.h"
#include "OfficeEmployee.h"

int main()
{
    //====== OFFICE EMPLOYEE ======//
    OfficeEmployee o1(22127469, "Do Hai Yen", "29 01 2004", "HCM");
    o1.printEmployee();
    cout << endl;

    cout << "Office Employee" << endl;
    OfficeEmployee o2;
    o2.inputEmployee();
    cout << endl;
    cout << "Salary: " << o2.computeSalary() << endl;
    o2.printEmployee();
    cout << endl;
    
    //====== WORKER ======//
    Worker w1(22127427, "Nguyen Minh Triet", "16 06 2004", "HCM", 2);
    w1.printEmployee();
    cout << endl;

    cout << "Worker" << endl;
    Worker w2;
    w2.inputEmployee();
    cout << endl;
    cout << "Salary: " << w2.computeSalary() << endl;
    w2.printEmployee();
    
    return 0;
}