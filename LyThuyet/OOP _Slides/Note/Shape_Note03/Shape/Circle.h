#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Point2D.h"

#define PI 3.14

class Circle {
private:
	Point2D center;
	double radius;
public:
	Circle(double);
	Circle(Point2D, double);
	Circle(double, double, double);
	void set(Point2D, double);
	Point2D getCenter();
	double getRadius();
	double getArea();
	double getPerimeter();
	friend istream& operator>>(istream&, Circle&);
	friend ostream& operator<<(ostream&, Circle&);
};

#endif