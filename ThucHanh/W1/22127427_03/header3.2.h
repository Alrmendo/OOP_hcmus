#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Triangle
{
    Point A, B, C;
};

void Input_Point(Point& point, double x_val, double y_val);
void Output_Point(const Point& point);
double Distance(const Point& point1, const Point&  point2);
double DistanceToOx(const Point& point);
double DistanceToOy(const Point& point);
void Input_Triangle(Triangle& triangle, const Point& A_val, const Point& B_val, const Point& C_val);
void Output_Triangle(const Triangle& triangle);
bool IsValidTriangle(const Triangle& triangle);
string TypeOfTriangle(const Triangle& triangle);
double Perimeter(const Triangle& triangle);
double Area(const Triangle& triangle);
Point CenterG(const Triangle& triangle);
