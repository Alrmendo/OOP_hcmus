#include "student.h"

using namespace std;

Student::Student()
{
    this -> id = 0;
    this -> fullname = NULL;
    this -> address = NULL;
    this -> gpa = 0.0;
}

Student::Student(int id, const char* fullname, const char* address, double gpa)
{
    this -> id = id;
    this -> gpa = gpa;
    this -> fullname = new char[strlen(fullname) + 1];
    this -> address = new char[strlen(address) + 1];
    strcpy(this->fullname, fullname);
    strcpy(this->address, address);
}

Student::Student(const Student& other)
{
    this -> id = other.id;
    this -> gpa = other.gpa;
    this -> fullname = new char[strlen(other.fullname) + 1];
    this -> address = new char[strlen(other.address) + 1];
    strcpy(this->fullname, other.fullname);
    strcpy(this->address, other.address);
}

Student::Student(int id)
{
    this -> id = id;
    this -> fullname = NULL;
    this -> address = NULL;
    this -> gpa = 0.0;
}

Student::Student(const char* fullname)
{
    this -> id = 0;
    this -> fullname = new char[strlen(fullname) + 1];
    this -> address = NULL;
    this -> gpa = 0.0;
    strcpy(this->fullname, fullname);
}


string Student::toString() const
{
    string result;
    result = "ID: " + to_string(id);
    if(fullname != NULL)
    {
        result += ", Fullname: " + string(fullname);
    }
    else
    {
        result += ", Fullname: NULL ";
    }
    if(address != NULL)
    {
        result += ", Address: " + string(address);
    }
    else
    {
        result += ", Address: NULL ";
        result += ", GPA: " + to_string(gpa);
    }

    return result;
}

Student Student::clone() const
{
    return Student(*this);
}