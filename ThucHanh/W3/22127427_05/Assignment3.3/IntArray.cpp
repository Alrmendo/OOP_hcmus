#include "IntArray.h"

using namespace std;

MyIntArray::MyIntArray()
{
    this -> n = 0;
    this -> a = NULL;
    cout << "Default constructor called\n";
}

MyIntArray::MyIntArray(int n)
{
    this -> n = n;
    this -> a = new int[n];
    for(int i = 0; i < n; i++)
    {
        this -> a[i] = 0;
    }
}

MyIntArray::MyIntArray(int a[], int n)
{
    this -> n = n;
    this -> a = new int[n];
    for(int i = 0; i < n; i++)
    {
        this -> a[i] = a[i];
    }
}

MyIntArray::MyIntArray(const MyIntArray& a)
{
    this -> n = a.n;
    this -> a = new int[a.n];
    for(int i = 0; i < n; i++)
    {
        this -> a[i] = a.a[i];
    }
}

MyIntArray::MyIntArray(string s)
{
    this -> n = s.length();
    this -> a = new int[n];
    for( int i = 0; i < n; i++)
    {
        this -> a[i] = s[i] - '0'; 
    }
    cout << "String constructor called\n";
}

string MyIntArray::toString() const
{
    string result = "[";
    for(int i = 0; i < n; i++)
    {
        result = result + to_string(a[i]);
        if(i < n - 1)
        {
            result = result + ", ";
        }
    }
    result = result + "]";
    return result;
}

MyIntArray MyIntArray::clone() const
{
    MyIntArray object(n);
    for (int i = 0; i < n; i++)
    {
        object.a[i] = a[i];
    }
    return object;
}
