#include "Point2D.h"

Point2D::Point2D() : x(0), y(0) {}

Point2D::Point2D(const Point2D& p) : x(p.x), y(p.y) {}

Point2D::Point2D(double a, double b) : x(a), y(b) {}

void Point2D::set(double x, double y) {
	this->x = x;
	this->y = y;
}

double Point2D::getX() {
	return this->x;
}

double Point2D::getY() {
	return this->y;
}

void Point2D::move(double dx, double dy) {
	this->x += dx;
	this->y += dy;
}

istream& operator>>(istream& in, Point2D& p) {
	in >> p.x >> p.y;
	return in;
}

ostream& operator<<(ostream& out, Point2D& p) {
	out << "Point2D(" << p.x << ", " << p.y << ")";
	return out;
}