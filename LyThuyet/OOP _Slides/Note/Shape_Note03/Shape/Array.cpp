#include "Array.h"

Array::Array() {
	this->n = 0;
	this->a = NULL;
}

Array::Array(int n) {
	this->n = n;
	this->a = new int[n];
	for (int i = 0; i < n; i++) {
		this->a[i] = 0;
	}
}

Array::Array(int a[], int n) {
	this->n = n;
	this->a = new int[n];
	for (int i = 0; i < n; i++) {
		this->a[i] = a[i];
	}
}

Array::Array(const Array& a) {
	this->n = a.n;
	this->a = new int[a.n];
	for (int i = 0; i < a.n; i++) {
		this->a[i] = a.a[i];
	}
}

int Array::at(int i) {
	return this->a[i];
}

void Array::add(int v) {
	int* old = this->a;
	this->a = new int[n + 1];
	for (int i = 0; i < this->n; i++) {
		this->a[i] = old[i];
	}
	if (old != NULL) {
		delete old;
	}
	this->a[n] = v;
	this->n++;
}

int Array::indexOf(int v) {
	for (int i = 0; i < n; i++) {
		if (this->a[i] == v) {
			return i;
		}
	}
	return -1;
}

ostream& operator<<(ostream& out, Array& a) {
	for (int i = 0; i < a.n; i++) {
		cout << a.a[i] << " ";
	}
	return out;
}

void Array::set(int i, int v) {
	this->a[i] = v;
}

Array::~Array() {
	cout << "Array::~Array()" << endl;
	if (this->a != NULL) {
		delete this->a;
	}
}