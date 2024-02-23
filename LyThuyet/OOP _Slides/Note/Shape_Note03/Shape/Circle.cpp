#include "Circle.h"

Circle::Circle(double radius) {
	this->radius = radius;
}

Circle::Circle(Point2D p, double r) : center(p), radius(r) {}

Circle::Circle(double x, double y, double r) : center(x, y), radius(r) {}

void Circle::set(Point2D center, double radius) {
	this->center = center;
	this->radius = radius;
}

Point2D Circle::getCenter() {
	return this->center;
}

double Circle::getRadius() {
	return this->radius;
}

double Circle::getArea() {
	return this->radius * this->radius * PI;
}

double Circle::getPerimeter() {
	return this->radius * PI * 2;
}

istream& operator>>(istream& in, Circle& c) {
	in >> c.center >> c.radius;
	return in;
}

ostream& operator<<(ostream& out, Circle& c) {
	out << "Circle(" << c.center << ", " << c.radius << ")";
	return out;
}