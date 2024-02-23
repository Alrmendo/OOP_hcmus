#include "fraction.h"

int main()
{
    Fraction frac1, frac2, result;
    string compareResult;

    cout << "Enter details for fraction 1:\n";
    frac1.Input(frac1);

    cout << "\nEnter details for fraction 2:\n";
    frac2.Input(frac2);

    cout << "\nFraction 1: ";
    frac1.Output(frac1);

    cout << "Fraction 2: ";
    frac2.Output(frac2);

    cout << "\nSum: ";
    result = frac1.Add(frac1, frac2);
    result.Output(result);


    cout << "\nSubtract: ";
    result = frac1.Subtract(frac1, frac2);
    result.Output(result);


    cout << "\nProduct: ";
    result = frac1.Multiply(frac1, frac2);
    result.Output(result);

    cout << "\nQuotient: ";
    result = frac1.Divide(frac1, frac2);
    result.Output(result);

    cout << "\nReduced Fraction 1: ";
    frac1.Reduce(frac1);
    frac1.Output(frac1);

    cout << "Reduced Fraction 2: ";
    frac2.Reduce(frac2);
    frac2.Output(frac2);

    if (frac1.Compare(frac1, frac2))
    {
        compareResult = "Equal";
    }
    else
    {
        compareResult = "Not Equal";
    }
    cout << "\nComparison: " << compareResult << endl;

    cout << "\nFraction 1 is " << (frac1.IsPositive(frac1) ? "positive" : "not positive");
    cout << "\nFraction 2 is " << (frac2.IsPositive(frac2) ? "positive" : "not positive");

    cout << endl;
    cout << "\nFraction 1 is " << (frac1.IsNegative(frac1) ? "negative." : "not negative.") << endl;
    cout << "Fraction 2 is " << (frac2.IsNegative(frac2) ? "negative." : "not negative.") << endl;

    cout << "\nFraction 1 is " << (frac1.IsZero(frac1) ? "zero." : "non-zero.") << endl;
    cout << "Fraction 2 is " << (frac2.IsZero(frac2) ? "zero." : "non-zero.") << endl;

    return 0;
}
