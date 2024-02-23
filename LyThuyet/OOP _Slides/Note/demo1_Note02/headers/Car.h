#include <string>
#include <iostream>
#include "PhanSo.h"
using namespace std;

class Car {
private:
    int serial;
    string manufacturer;
    string color;
    bool isEV;

public:
    void setSerial(int serial);
    void setManufacturer(string manufacturer);
    void setColor(string color);
    void setIsEV(bool isEV);
    int getSerial();
    string getManufacturer();
    string getColor();
    bool getIsEV();
    void print();
};
