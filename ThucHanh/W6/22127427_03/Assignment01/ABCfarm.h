#ifndef ABCFARM_H
#define ABCFARM_H

#include <iostream>
#include <vector>
using namespace std;

class Animal 
{
protected:
    int identifier;
    double weight;
    double age;

public:
    Animal();
    Animal(int, double, double);
    Animal(const Animal& other);
    int getIdentifier() const;
    double getWeight() const;
    double getAge() const;
    void setWeight(double);
    void setAge(double);
    bool isValidWeight() const;
    bool isValidAge() const;
    virtual string getType() const = 0;
    string toString() const;
    virtual ~Animal() {}
};

class DairyCow : public Animal 
{
public:
    DairyCow();
    DairyCow(int, double, double);
    DairyCow(const DairyCow& other);
    string getType() const;
};

class Goat : public Animal 
{
public:
    Goat();
    Goat(int, double, double);
    Goat(const Goat& other);
    string getType() const;
};

class ABCFarm 
{
private:
    vector<Animal*> animals;

public:
    void Input();
    void Output();
    void OutputByAge(int, int);
    ~ABCFarm();
};

#endif
