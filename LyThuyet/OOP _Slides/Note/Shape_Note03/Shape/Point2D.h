#ifndef _POINT_2D_H_
#define _POINT_2D_H_
#include <iostream>
using namespace std;

class Point2D {
private:
	double x, y;
public:
	Point2D();
	Point2D(const Point2D&);
	Point2D(double, double);
	void set(double, double);
	double getX();
	double getY();
	void move(double, double);
	friend istream& operator>>(istream&, Point2D&);
	friend ostream& operator<<(ostream&, Point2D&);
};

#endif