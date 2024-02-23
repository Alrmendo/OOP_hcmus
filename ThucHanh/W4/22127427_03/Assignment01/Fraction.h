#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
#include <cmath>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int num, int den);
    Fraction(const Fraction& other);
    int GCD(int, int);
    void reduce();
    Fraction operator =(const Fraction &f);

    friend ostream& operator << (ostream& out, const Fraction& f);

    Fraction operator +(Fraction f);
    Fraction operator -(Fraction f);
    Fraction operator *(Fraction f);
    Fraction operator /(Fraction f);

    bool operator ==(Fraction f);
    bool operator !=(Fraction f);
    bool operator >=(Fraction f);
    bool operator >(Fraction f);
    bool operator <=(Fraction f);
    bool operator <(Fraction f);

    Fraction operator +(int n);
    Fraction operator -(int n);
    friend Fraction operator *(int n, Fraction f);
    friend Fraction operator +(int n, Fraction f);

    void operator +=(Fraction f);
    void operator -=(Fraction f);
    void operator *=(Fraction f);
    void operator /=(Fraction f);

    Fraction operator ++();
    Fraction operator ++(int);
    Fraction operator --();
    Fraction operator --(int);

    operator float()
    {
        return (float) numerator/denominator;
    }
};

#endif