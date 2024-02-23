#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class MyIntArray
{
private:
    int* a;
    int n;

public:
    MyIntArray();
    MyIntArray(int n);
    MyIntArray(int a[], int n);
    MyIntArray(const MyIntArray& );
    MyIntArray(string s);
    ~MyIntArray()
    {
        cout << "MyIntArray::~MyIntArray()" << endl;
        if(this -> a != NULL)
        {
            delete[] this->a;
        }
    }
    string toString() const;
    MyIntArray clone() const;
};

#endif