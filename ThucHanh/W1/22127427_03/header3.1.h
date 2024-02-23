#include <iostream>
#include <string>

using namespace std;

struct Fraction
{
    double numerator;
    double denominator;
};

void Input(Fraction &frac);
void Output(const Fraction &frac);
Fraction Add(const Fraction &frac1, const Fraction &frac2);
Fraction Subtract(const Fraction &frac1, const Fraction &frac2);
Fraction Multiply(const Fraction &frac1, const Fraction &frac2);
Fraction Divide(const Fraction &frac1, const Fraction &frac2);
void Reduce(Fraction &frac);
bool Compare(const Fraction &frac1, const Fraction &frac2);
bool IsPositive(const Fraction &frac);
bool IsNegative(const Fraction &frac);
bool IsZero(const Fraction &frac);
