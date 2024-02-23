#include "header3.1.h"

void Input(Fraction &frac)
{
    cout << "Enter numerator: ";
    cin >> frac.numerator;


    cout << "Enter denominator: ";
    cin >> frac.denominator;
}

void Output(const Fraction &frac)
{
    cout << frac.numerator;
    
    if (frac.denominator != 1)
    {
        cout << "/" << frac.denominator;
    }
    
    cout << endl;
}

Fraction Add(const Fraction &frac1, const Fraction &frac2)
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Subtract(const Fraction &frac1, const Fraction &frac2)
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Multiply(const Fraction &frac1, const Fraction &frac2)
{
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

Fraction Divide(const Fraction &frac1, const Fraction &frac2)
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

void Reduce(Fraction &frac)
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

bool Compare(const Fraction &frac1, const Fraction &frac2)
{
    return (frac1.numerator * frac2.denominator == frac1.denominator * frac2.numerator);
}

bool IsPositive(const Fraction &frac)
{
    return (frac.numerator * frac.denominator > 0);
}

bool IsNegative(const Fraction &frac)
{
    return (frac.numerator * frac.denominator < 0);
}

bool IsZero(const Fraction &frac)
{
    return (frac.numerator == 0);
}