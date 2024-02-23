#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction {
private:
    double numerator;
    double denominator;

public:
    void Input(Fraction&);
    void Output(Fraction&) const;
    Fraction Add(const Fraction&, const Fraction&) const;  
    Fraction Subtract(const Fraction&, const Fraction&) const;  
    Fraction Multiply(const Fraction&, const Fraction&) const;  
    Fraction Divide(const Fraction&, const Fraction&) const;  
    void Reduce(Fraction&);
    bool Compare(Fraction&, Fraction&) const;  
    bool IsPositive(Fraction&) const;  
    bool IsNegative(Fraction&) const; 
    bool IsZero(Fraction&) const; 
};

#endif
