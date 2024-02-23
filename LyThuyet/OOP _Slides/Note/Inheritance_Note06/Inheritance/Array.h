#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
using namespace std;

template<class T>
class Array {
protected:
	int n;
	T* elements;
public:
	Array();
	void push(T e);
	void print();
	int getLength() const;
	~Array();
};

template<class T>
Array<T>::Array() {
	this->n = 0;
	this->elements = nullptr;
}

template<class T>
void Array<T>::push(T e) {
	T* old = this->elements;
	this->elements = new T[this->n + 1];
	for (int i = 0; i < this->n; i++) {
		this->elements[i] = old[i];
	}
	this->elements[n] = e;
	this->n++;
	delete[] old;
}

template<class T>
void Array<T>::print() {
	cout << "Length: " << this->n << endl;
	for (int i = 0; i < this->n; i++) {
		cout << this->elements[i] << " ";
	}
	cout << endl;
}

template<class T>
int Array<T>::getLength() const {
	return this->n;
}

template<class T>
Array<T>::~Array() {
	if (this->elements != nullptr) {
		delete[] this->elements;
	}
}

#endif // !_ARRAY_H_
