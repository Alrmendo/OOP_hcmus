#include "triangle.h"

Triangle::Triangle()
{
    cout << "Triangle::Default cons" << endl;
    this -> A = point2D(0,0);
    this -> B = point2D(0,0);
    this -> C = point2D(0,0);
}

Triangle::Triangle(const point2D& a)
{
    cout << "Triangle::(const point2D& a) cons" << endl;
    this -> A = a;
    this -> B = point2D(0,0);
    this -> C = point2D(0,0);
}

Triangle::Triangle(const point2D& a1, const point2D& a2)
{
    cout << "Triangle::(const point2D& a1, const point2D& a2) cons" << endl;
    this -> A = a1;
    this -> B = a2;
    this -> C = point2D(0,0);
}


Triangle::Triangle(const point2D& a3, const point2D& a4, const point2D& a5)
{
    cout << "Triangle::(const point2D& a3, const point2D& a4, const point2D& a5) cons" << endl;
    this -> A = a3;
    this -> B = a4;
    this -> C = a5;
}

Triangle::Triangle(const Triangle& p)
{
    cout << "Point2D::(const Triangle& p) cons" << endl;
    this -> A = p.A;
    this -> B = p.B;
    this -> C = p.C;
}

string Triangle::toString() const
{
    stringstream is;
    is << "Triangle with vertices: " << A.toString() << ", " << B.toString() << ", " << C.toString();
    return is.str(); 
}