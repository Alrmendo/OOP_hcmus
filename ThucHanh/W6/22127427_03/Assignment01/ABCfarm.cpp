#include "ABCfarm.h"

// Animal class implementation
Animal::Animal() : identifier(0), weight(0.0), age(0.0) {}

Animal::Animal(int id, double w, double a) : identifier(id), weight(w), age(a) {}

Animal::Animal(const Animal& other) : identifier(other.identifier), weight(other.weight), age(other.age) {}

int Animal::getIdentifier() const {
    return identifier;
}

double Animal::getWeight() const {
    return weight;
}

double Animal::getAge() const {
    return age;
}

void Animal::setWeight(double w) {
    weight = w;
}

void Animal::setAge(double a) {
    age = a;
}

bool Animal::isValidWeight() const {
    return weight > 0;
}

bool Animal::isValidAge() const {
    return age > 0;
}

std::string Animal::toString() const {
    return getType() + " - Identifier: " + std::to_string(identifier) + ", Weight: " + std::to_string(weight) + ", Age: " + std::to_string(age);
}

// DairyCow class implementation
DairyCow::DairyCow() : Animal() {}

DairyCow::DairyCow(int id, double w, double a) : Animal(id, w, a) {}

DairyCow::DairyCow(const DairyCow& other) : Animal(other) {}

std::string DairyCow::getType() const {
    return "DairyCow";
}

// Goat class implementation
Goat::Goat() : Animal() {}

Goat::Goat(int id, double w, double a) : Animal(id, w, a) {}

Goat::Goat(const Goat& other) : Animal(other) {}

std::string Goat::getType() const {
    return "Goat";
}

// ABCFarm class implementation
void ABCFarm::Input() 
{
int numCows, numGoats;

    cout << "Enter the number of cows: ";
    cin >> numCows;

    for (int i = 0; i < numCows; i++) 
    {
        int id;
        double weight, age;

        cout << "Enter the identifier for cow " << i + 1 << ": ";
        cin >> id;

        cout << "Enter the weight for cow " << i + 1 << ": ";
        cin >> weight;

        cout << "Enter the age for cow " << i + 1 << ": ";
        cin >> age;

        Animal* cow = new DairyCow(id, weight, age);
        animals.push_back(cow);
    }

    cout << "Enter the number of goats: ";
    cin >> numGoats;

    for (int i = 0; i < numGoats; i++) 
    {
        int id;
        double weight, age;

        cout << "Enter the identifier for goat " << i + 1 << ": ";
        cin >> id;

        cout << "Enter the weight for goat " << i + 1 << ": ";
        cin >> weight;

        cout << "Enter the age for goat " << i + 1 << ": ";
        cin >> age;

        Animal* goat = new Goat(id, weight, age);
        animals.push_back(goat);
    }
}

void ABCFarm::Output() 
{
    cout << "Animals:" << endl;
    for (int i = 0; i < animals.size(); ++i) 
    {
        const Animal* animal = animals[i];
        cout << animal->toString() << endl;
    }
}

void ABCFarm::OutputByAge(int min, int max) 
{
    for (int i = 0; i < animals.size(); ++i)
    {
        const Animal* animal = animals[i];
        if (animal->getAge() >= min && animal->getAge() <= max) 
        {
            cout << animal->toString() << endl;
        }
    }
}

ABCFarm::~ABCFarm() 
{
    for (int i = 0; i < animals.size(); ++i) 
    {
        delete animals[i];
    }
}
