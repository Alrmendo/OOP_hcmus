#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Student
{
private:
    int id;
    char* fullname, *address;
    double gpa;

public:
    Student();
    Student(int id, const char* fullname, const char* address, double gpa);
    Student(const Student & other);
    Student(int id);
    Student(const char* fullname);

    ~Student()
    {
        delete[] fullname;
        delete[] address;
        cout << "Destructor called\n";
    }

    string toString() const;
    Student clone() const;

};
#endif
