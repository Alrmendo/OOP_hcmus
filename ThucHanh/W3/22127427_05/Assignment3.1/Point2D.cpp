#include "Point2D.h"

point2D::point2D() // or : x(0), y(0);
{
    cout << "Point2D::Default cons" << endl;
    this -> x = 0;
    this -> y = 0;
}

point2D::point2D(int x)
{
    cout << "point2D::(int x) cons" << endl;
    this -> x = x;
    this -> y = 0;
}

point2D::point2D(int x, int y)
{
    cout << "point2D::(int x, int y) cons" << endl;
    this -> x = x;
    this -> y = y;
}

point2D::point2D(const point2D &other)
{
    cout << "point2D::(const point2D &other) cons" << endl;
    this -> x = other.x;
    this -> y = other.y;
}

point2D::point2D(string s)
{
    istringstream is(s);
    char comma;
    is >> x >> comma >> y;
}

string point2D::toString()
{
    ostringstream os;
    os << "Point " << x << "," << y;
    return os.str();
}

point2D point2D::clone()
{
    return point2D(x, y);
}

ostream& operator<<(ostream& out, point2D& p) 
{
	out << "Point2D(" << p.x << "," << p.y << ")";
	return out;
}
