#include <iostream>
#include "Point2D.h"
#include "Circle.h"
#include "Array.h"

using namespace std;

int main() {
	Array a1;
	a1.add(5);
	a1.add(10);
	a1.add(15);
	a1.add(20);
	Array a2(a1);
	a2.set(0, 100);
	cout << a1 << endl;
	cout << a2 << endl;
	Array* a3 = new Array(a2);
	cout << *a3 << endl;
	delete a3;
	return 0;
}