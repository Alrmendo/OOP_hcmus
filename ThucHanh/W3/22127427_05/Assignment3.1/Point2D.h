#ifndef _POINT2D_H_
#define _POINT2D_H_
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class point2D
{
private:
    double x;
    double y;
public:
    point2D();
    point2D(int);
    point2D(int, int);
    point2D(const point2D &other);
    point2D(string);
    friend ostream& operator << (ostream&, point2D&);
    ~point2D()
    {
        cout << "Point2D::Destructor" << endl;
    }
    string toString();
    point2D clone();
};

#endif