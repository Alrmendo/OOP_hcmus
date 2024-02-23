#include "Car.h"

void Car::setSerial(int serial) {
  this->serial = serial;
}

void Car::setManufacturer(string manufacturer) {
  this->manufacturer = manufacturer;
}

void Car::setColor(string color) {
  this->color = color;
}

void Car::setIsEV(bool isEV) {
  this->isEV = isEV;
}

int Car::getSerial() {
  return this->serial;
}

string Car::getManufacturer() {
  return this->manufacturer;
}

string Car::getColor() {
  return this->color;
}

bool Car::getIsEV() {
  return this->isEV;
}

void Car::print() {
  cout << "This is a " << this->manufacturer;
  if (this->isEV) {
    cout << " EV";
  }
  else {
    cout << " car";
  }
  cout << " (" << this->color << ")";
  cout << " serial " << this->serial << endl;
}