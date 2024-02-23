#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
using namespace std;

class Array {
private:
	int n;
	int* a;
public:
	Array();
	Array(int n);
	Array(int a[], int n);
	Array(const Array&);
	int at(int i);
	void add(int v);
	void set(int i, int v);
	int indexOf(int v);
	~Array();
	friend ostream& operator<<(ostream&, Array&);
};

#endif