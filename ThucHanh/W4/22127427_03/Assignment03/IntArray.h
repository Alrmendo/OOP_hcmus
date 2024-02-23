#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using namespace std;

class IntArray 
{
private:
    int *pArr;
    int size;

public:
    IntArray();
    IntArray(int);
    ~IntArray();
    IntArray(int*, int);
    IntArray(IntArray&);

    IntArray& operator =(const IntArray &a);
    friend istream& operator >>(istream& in, IntArray &a);
    friend ostream& operator <<(ostream& out,const IntArray &a);

    int& operator[](int);
    operator int() {return size; }
};

#endif