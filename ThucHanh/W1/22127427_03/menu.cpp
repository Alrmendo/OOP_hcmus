#include "header3.1.h"
#include "header3.2.h"
#include "header3.3.h"

int main()
{
    //Assignment 3.1
    Fraction frac1, frac2;
    string compareResult;

    //Assignment 3.2
    Point pointA, pointB, pointC;
    Point center;

    //Assignment 3.3
    LinkedListQueue Queue;

    int choice;

    do
    {
        cout << "\n------------------------" << endl;
        cout << "Week 01 Assignments Menu" << endl;
        cout << "------------------------" << endl;
        cout << "1. Assignmnet 3.1 Fraction" << endl;
        cout << "2. Assignment 3.2 Triangle" << endl;
        cout << "3. Assignment 3.3 Queue / LinkedList" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:

                cout << "Enter details for fraction 1:\n";
                Input(frac1);

                cout << "\nEnter details for fraction 2:\n";
                Input(frac2);

                cout << "\nFraction 1: ";
                Output(frac1);

                cout << "Fraction 2: ";
                Output(frac2);

                cout << "\nSum: ";
                Output(Add(frac1, frac2));

                cout << "\nSubtract: ";
                Output(Subtract(frac1, frac2));

                cout << "\nProduct: ";
                Output(Multiply(frac1, frac2));

                cout << "\nQuotient: ";
                Output(Divide(frac1, frac2));

                cout << "\nReduced Fraction 1: ";
                Reduce(frac1);
                Output(frac1);

                cout << "Reduced Fraction 2: ";
                Reduce(frac2);
                Output(frac2);

                if (Compare(frac1, frac2))
                {
                    compareResult = "Equal";
                }
                else
                {
                    compareResult = "Not Equal";
                }
                cout << "\nComparison: " << compareResult << endl;

                cout << "\nFraction 1 is " << (IsPositive(frac1) ? "positive" : "not positive");
                cout << "\nFraction 2 is " << (IsPositive(frac2) ? "positive" : "not positive");

                cout << endl;
                cout << "\nFraction 1 is " << (IsNegative(frac1) ? "negative." : "not negative.") << endl;
                cout << "Fraction 2 is " << (IsNegative(frac1) ? "negative." : "not negative.") << endl;

                cout << "\nFraction 1 is " << (IsZero(frac1) ? "zero." : "non-zero.") << endl;
                cout << "Fraction 2 is " << (IsZero(frac2) ? "zero." : "non-zero.") << endl;

                break;

            case 2:
                cout << "Enter coordinate for Point A (x y)\n";
                cout << "x: "; cin >> pointA.x;
                cout << "y: "; cin >> pointA.y;

                cout << "Enter coordinate for Point B (x y)\n";
                cout << "x: "; cin >> pointB.x;
                cout << "y: "; cin >> pointB.y;

                cout << "Enter coordinate for Point C (x y)\n";
                cout << "x: "; cin >> pointC.x;
                cout << "y: "; cin >> pointC.y;

                cout << "\nPoints\n";
                cout << "A: "; Output_Point(pointA); cout << endl;
                cout << "B: "; Output_Point(pointB); cout << endl;
                cout << "C: "; Output_Point(pointC); cout << endl;

                cout << "\nDistance\n";
                cout << "Distance from A to B: " << Distance(pointA, pointB) << endl;
                cout << "Distance to Ox for B: " << DistanceToOx(pointB) << endl;
                cout << "Distance to Oy for C: " << DistanceToOy(pointC) << endl; 

                Triangle triangle;
                Input_Triangle(triangle, pointA, pointB, pointC);

                cout << "\nTriangle\n";
                Output_Triangle(triangle);

                cout << "\nIs the triangle valid ? " << (IsValidTriangle(triangle) ? "Yes" : "No") << endl;

                cout << "Type of triangle: " << TypeOfTriangle(triangle) << endl;

                cout << "Perimeter: " << Perimeter(triangle) << endl;
                cout << "Area: " << Area(triangle) << endl;

                center = CenterG(triangle);
                cout << "Center G of the Triangle: ";
                Output_Point(center);
                cout << endl;

                break;

            case 3:
                int capacity;
                cout << "Enter the capacity of the queue: ";
                cin >> capacity;
                init(Queue, capacity);


                int numElements;
                cout << "Enter the number of elements to enqueue: ";
                cin >> numElements;

                for (int i = 0; i < numElements; ++i) 
                {
                    int element;
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> element;
                    enqueue(Queue, element);
                }

                cout << "Peek: " << peek(Queue) << endl;
                cout << "Dequeue: " << dequeue(Queue) << endl;

                cout << "Is empty ? " << (isEmpty(Queue) ? "Yes" : "No") << endl;
                cout << "Is full ? " << (isFull(Queue) ? "Yes" : "No") << endl;

                clear(Queue);

                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
 
    return 0;
}

