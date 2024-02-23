#include "Fraction.h"

Fraction::Fraction()
{
    this -> numerator = 0;
    this -> denominator = 1;
}

Fraction::Fraction(int num, int den)
{
    this -> numerator = num;
    this -> denominator = den;
}

Fraction::Fraction(const Fraction& other)
{
    this -> numerator = other.numerator;
    this -> denominator = other.denominator;
}

int Fraction::GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

void Fraction::reduce()
{
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

ostream& operator << (ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

Fraction Fraction::operator =(const Fraction& f)
{
    if(this != &f)
    {
        numerator = f.numerator;
        denominator = f.denominator;
        reduce();
    }
    return *this;
}

Fraction Fraction::operator +(Fraction f)
{
    Fraction c;
    c.numerator = numerator * f.denominator + f.numerator * denominator;
    c.denominator = denominator * f.denominator;
    c.reduce();

    return c;
}

Fraction Fraction::operator -(Fraction f)
{
    Fraction c;
    c.numerator = numerator * f.denominator - f.numerator * denominator;
    c.denominator = denominator * f.denominator;
    c.reduce();

    return c;
}

Fraction Fraction::operator *(Fraction f)
{
    Fraction c;
    c.numerator = numerator * f.numerator;
    c.denominator = denominator * f.denominator;
    c.reduce();

    return c;
}

Fraction Fraction::operator /(Fraction f)
{
    if(f.denominator == 0)
    {
        cout << "Math error";
    }

    Fraction c;
    c.numerator = numerator * f.denominator;
    c.denominator = denominator * f.numerator;
    c.reduce();

    return c;
}

bool Fraction::operator ==(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 == t2)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator !=(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 != t2)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator >=(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 >= t2)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator >(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 > t2)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator <=(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 <= t2)
    {
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator <(Fraction f)
{
    int t1, t2;
    t1 = numerator * f.denominator;
    t2 = f.numerator * denominator;

    if(t1 < t2)
    {
        return true;
    }
    else{
        return false;
    }
}

Fraction Fraction::operator +(int n)
{
    Fraction c;
    c.numerator = numerator + n * denominator;
    c.denominator = denominator;

    c.reduce();
    return c;
}

Fraction Fraction::operator -(int n)
{
    Fraction c;
    c.numerator = numerator - n * denominator;
    c.denominator = denominator;

    c.reduce();
    return c;
}

Fraction operator +(int n, Fraction f)
{
    Fraction c;
    c.numerator = f.numerator + n * f.denominator;
    c.denominator = f.denominator;

    c.reduce();
    return c;
}

Fraction operator *(int n, Fraction f)
{
    Fraction c;
    c.numerator = n * f.numerator;
    c.denominator = f.denominator;

    c.reduce();
    return c;
}

void Fraction::operator +=(Fraction f)
{
    Fraction c;
    c.numerator = numerator;
    c.denominator = denominator;
    c = c + f;
    numerator = c.numerator;
    denominator = c.denominator;
}

void Fraction::operator -=(Fraction f)
{
    Fraction c;
    c.numerator = numerator;
    c.denominator = denominator;
    c = c - f;
    numerator = c.numerator;
    denominator = c.denominator;
}

void Fraction::operator *=(Fraction f)
{
    Fraction c;
    c.numerator = numerator;
    c.denominator = denominator;
    c = c * f;
    numerator = c.numerator;
    denominator = c.denominator;
}

void Fraction::operator /=(Fraction f)
{
    Fraction c;
    c.numerator = numerator;
    c.denominator = denominator;
    c = c / f;
    numerator = c.numerator;
    denominator = c.denominator;
}

Fraction Fraction::operator ++()
{
    numerator = numerator + denominator;
    return *this;
}

Fraction Fraction::operator ++(int)
{
    Fraction c = *this;
    ++(*this);
    return c;
}

Fraction Fraction::operator --()
{
    numerator = numerator - denominator;
    return *this;
}

Fraction Fraction::operator --(int n)
{
    Fraction c = *this;
    --(*this);
    return c;
}