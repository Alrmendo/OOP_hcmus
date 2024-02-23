#include "triangle.h"

int main ()
{
    Triangle triangle;
    triangle.Input();
    
    triangle.TypeOfTriangle();

    if (triangle.IsValidTriangle()) 
    {
        cout << "\n--> This triangle is valid !\n";

        cout << "\nPerimeter: ";
        cout << triangle.Perimeter() << endl;

        cout << "\nArea: ";
        cout << triangle.Area() << endl;

        cout << "\nCenter: ";
        triangle.CenterG().Output();
    }
    else
    {
        cout << "Not a Triangle!";
    }

    return 0;
}