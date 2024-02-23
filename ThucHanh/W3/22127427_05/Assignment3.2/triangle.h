#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include "Point2D.h"

class Triangle
{
private:
    point2D A, B, C;

public:
    Triangle();
    Triangle(const point2D&);
    Triangle(const point2D&, const point2D&);
    Triangle(const point2D&, const point2D&, const point2D&);

    ~Triangle()
    {
        cout << "Triangle::Destructor" << endl;
    }

    string toString() const;
    Triangle(const Triangle&);
};

#endif