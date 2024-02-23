#include "fraction.h"

void Fraction::Input(Fraction& frac)
{

    cout << "Enter numerator: ";
    cin >> frac.numerator;

    cout << "Enter denominator: ";
    cin >> frac.denominator;
}

void Fraction::Output(Fraction &frac) const
{
    cout << frac.numerator;
    
    if (frac.denominator != 1)
    {
        cout << "/" << frac.denominator;
    }
    
    cout << endl;
}

Fraction Fraction::Add(const Fraction &frac1, const Fraction &frac2) const
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Fraction::Subtract(const Fraction &frac1, const Fraction &frac2) const
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Fraction::Multiply(const Fraction &frac1, const Fraction &frac2) const
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Fraction::Divide(const Fraction &frac1, const Fraction &frac2) const
{
    Fraction result;

    if (frac2.denominator == 0 || frac1.denominator == 0)
    {
        cout << "Error: Cannot divide by zero";
    }
    else
    {
        result.numerator = frac1.numerator * frac2.denominator;
        result.denominator = frac1.denominator * frac2.numerator;
    }

    return result;
}

void Fraction::Reduce(Fraction &frac)
{
    int GCD = 1;

    if (frac.numerator != 0)
    {
        int a = abs(frac.numerator);
        int b = abs(frac.denominator);

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        GCD = a;
    }

    frac.numerator /= GCD;
    frac.denominator /= GCD;
}

bool Fraction::Compare(Fraction &frac1, Fraction &frac2) const
{
    return (frac1.numerator * frac2.denominator == frac1.denominator * frac2.numerator);
}

bool Fraction::IsPositive(Fraction &frac) const
{
    return (frac.numerator * frac.denominator > 0);
}

bool Fraction::IsNegative(Fraction &frac) const
{
    return (frac.numerator * frac.denominator < 0);
}

bool Fraction::IsZero(Fraction &frac) const
{
    return (frac.numerator == 0);
}
