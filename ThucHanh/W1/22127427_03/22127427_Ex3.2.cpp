#include "header3.2.h"


void Input_Point(Point& point, double x_val, double y_val)
{
    point.x = x_val;
    point.y = y_val;
}

void Output_Point(const Point& point)
{
    cout << "(" << point.x << "," << point.y << ")";
}

double Distance(const Point& point1, const Point&  point2)
{
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

double DistanceToOx(const Point& point)
{
    return fabs(point.y);
}

double DistanceToOy(const Point& point)
{
    return fabs(point.x);
}

void Input_Triangle(Triangle& triangle, const Point& A_val, const Point& B_val, const Point& C_val)
{
    triangle.A = A_val;
    triangle.B = B_val;
    triangle.C = C_val;
}

void Output_Triangle(const Triangle& triangle)
{
    cout << "Triangle vertices:\n";
    cout << "A: "; Output_Point(triangle.A); cout << endl;
    cout << "B: "; Output_Point(triangle.B); cout << endl;
    cout << "C: "; Output_Point(triangle.C); cout << endl;
}

bool IsValidTriangle(const Triangle& triangle)
{
    double AB = Distance(triangle.A, triangle.B);
    double BC = Distance(triangle.B, triangle.C);
    double AC = Distance(triangle.A, triangle.C);
    
    return (AB + BC > AC) || (AB + AC > BC) || (BC + AC > AB);
}

string TypeOfTriangle(const Triangle& triangle)
{
    double AB = Distance(triangle.A, triangle.B);
    double BC = Distance(triangle.B, triangle.C);
    double AC = Distance(triangle.A, triangle.C);

    if (AB == BC && BC == AC)
    {
        return "Equilateral";
    }
    else if (AB == BC || BC == AC || AC == AB)
    {
        return "Isosceles";
    }
    else if (pow(AB,2) + pow(BC,2) == pow(AC,2) || pow(AB,2) + pow(AC,2) == pow(BC,2) || pow(BC,2) + pow(AC,2) == pow(AB,2))
    {
        return "Right-angled";
    }
    else
    {
        return "Scalene";
    }
}

double Perimeter(const Triangle& triangle)
{
    return Distance(triangle.A, triangle.B) + Distance(triangle.B, triangle.C) + Distance(triangle.A, triangle.C);
}

double Area(const Triangle& triangle)
{
    double p = Perimeter(triangle) / 2;
    return sqrt(p * (p - Distance(triangle.A, triangle.B)) * (p - Distance(triangle.B, triangle.C)) * (p - Distance(triangle.A, triangle.C)));
}

Point CenterG(const Triangle& triangle)
{
    Point G;
    G.x = (triangle.A.x + triangle.B.x + triangle.C.x) / 3;
    G.y = (triangle.A.y + triangle.B.y + triangle.C.y) / 3;

    return G;
}