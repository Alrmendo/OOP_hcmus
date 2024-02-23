#include "IntArray.h"

IntArray::IntArray()
{

}

IntArray::~IntArray()
{
    if(size > 0)
    {
        size = 0;
        delete []pArr;
        pArr = NULL;
    }
}

IntArray::IntArray(int n)
{
    if(n <= 0)
    {
        n = 0;
        pArr = NULL;
        return;
    }
    size = n;
    pArr = new int[size];
    for(int i = 0; i < size; ++i)
    {
        pArr[i] = 0;
    }
}

IntArray::IntArray(int a[], int n)
{
    size = n;
    pArr = new int[size];
    for(int i = 0; i < size; ++i)
    {
        pArr[i] = a[i];
    }
}

IntArray::IntArray(IntArray& a)
{
    if(this != &a)
    {
        size = a.size;
        pArr = new int[size];
        for(int i = 0; i < size; ++i)
        {
            pArr[i] = a.pArr[i];
        }
    }
}

IntArray& IntArray::operator =(const IntArray &a)
{
    if(this != &a)
    {
        delete []pArr;
        size = a.size;
        pArr = new int[size];
        for(int i = 0; i < size; ++i)
        {
            pArr[i] = a.pArr[i];
        }
    }
    return *this;
}

int& IntArray::operator[](int i)
{
    if(i > size)
    {
        cout << "\nError";
        return pArr[0];
    }
    return pArr[i];
}

istream& operator >>(istream& in, IntArray &a)
{
    cout << "\nInput size: ";
    in >> a.size;
    cout << "\nInput value: ";

    a.pArr = new int[a.size];
    for(int i = 0; i < a.size; ++i)
    {
        in >> a.pArr[i];
    }
    return in;
}

ostream& operator <<(ostream& out, const IntArray& a)
{
    for (int i = 0; i < a.size; ++i) 
    {
        out << a.pArr[i] << " ";
    }
    out << "\n";
    return out;
}

