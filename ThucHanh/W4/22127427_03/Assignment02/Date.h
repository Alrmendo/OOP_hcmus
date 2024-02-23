#include <iostream>
using namespace std;

class Date 
{
private:
    int day, month, year;

public:
    Date();
    Date(int);
    Date(int, int);
    Date(int, int, int);
    bool checkLeapYear();

    void Input();

    Date& operator =(const Date &d);
    Date Tomorrow();
    Date Yesterday();

    friend istream& operator >>(istream &in, Date&d);
    friend ostream& operator << (ostream &out, const Date &d);

    bool operator ==(const Date &d);
    bool operator !=(const Date &d);
    bool operator >=(const Date &d);
    bool operator <=(const Date &d);
    bool operator >(const Date &d);
    bool operator <(const Date &d);

    Date operator+(int);
    Date operator-(int);

    Date& operator ++();
    Date operator ++(int);
    Date& operator --();
    Date operator --(int);

    operator int();
    operator long();

    Date& operator +=(int n);
    Date& operator -=(int n);
};