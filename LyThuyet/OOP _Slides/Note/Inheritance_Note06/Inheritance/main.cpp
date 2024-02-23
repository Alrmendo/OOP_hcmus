#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

class Animal {
protected:
	string name;
	string color;

public:
	Animal(string name, string color) {
		this->name = name;
		this->color = color;
		cout << "Animal::Animal" << endl;
	}

	virtual void print() {
		cout << "Animal::print" << endl;
		cout << "Name: " << this->name << endl;
		cout << "Color: " << this->color << endl;
	}

	virtual void say() = 0;

	virtual ~Animal() {
		cout << "Animal::~Animal" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(string name, string color) : Animal(name, color) {
		cout << "Cat::Cat" << endl;
	}

	void print() {
		cout << "This is a cat" << endl;
		Animal::print();
	}

	void say() {
		cout << "Meo meo o~o" << endl;
	}
};

class Dog : public Animal {
public:
	Dog(string name, string color) : Animal(name, color) {
		cout << "Dog::Dog" << endl;
	}

	virtual void print() {
		cout << "This is a dog" << endl;
		Animal::print();
	}

	virtual void say() {
		cout << "Gau gau >.<" << endl;
	}

	virtual ~Dog() {
		cout << "Dog::~Dog" << endl;
	}
};

class Poodle : public Dog {
protected:
	int size; // 1, 2, 3
public:
	Poodle(string name, string color, int size) : Dog(name, color) {
		cout << "Poodle::Poodle" << endl;
		this->size = size;
	}

	void print() {
		cout << "This is a poodle" << endl;
		Animal::print();
		cout << "Size: " << this->size << endl;
	}

	virtual ~Poodle() {
		cout << "Poodle::~Poodle" << endl;
	}
};

class Mouse : public Animal {
public:
	Mouse(string name, string color) : Animal(name, color) {
		// cout << "Mouse::Mouse" << endl;
	}

	virtual void print() {
		cout << "This is a mouse" << endl;
		Animal::print();
	}

	virtual void say() {
		cout << "Chit chit +.+" << endl;
	}
};

int main() {
	Array<string> a1;
	Array<string> a2;
	a1.push("Hello world");
	a1.push("This");
	a1.push("is");
	a2.push("my Array");
	a2.push("implemented in C++");
	Array<Array<string>> aa;
	return 0;
}