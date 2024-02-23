#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    void Input();
    void Output();
    float Distance(Point);
    double DistanceToOx();
    double DistanceToOy();
    void setX(int);
    void setY(int);
};

class Triangle
{
private:
    Point A, B, C;

public:
    void Input();
    void Output();
    bool IsValidTriangle();
    void TypeOfTriangle();
    double Perimeter();
    double Area();
    Point CenterG();
};

#endif
