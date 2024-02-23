#include <string>
#include <iostream>
#define MONTHLY_LEAVE 2
#define MONTHLY_WORKING_DAYS 22
using namespace std;

class Employee {
private:
  string id;
  int offDays;
  int baseSalary;
public:
  void setId(string id) {
    this->id = id;
  }

  string getId() {
    return this->id;
  }

  void setBaseSalary(int base) {
    this->baseSalary = base;
  }

  int getBaseSalary() {
    return this->baseSalary;
  }

  void setOffDays(int days) {
    this->offDays = days;
  }

  int getWorkingDays() {
    if (offDays < MONTHLY_LEAVE) {
        return MONTHLY_WORKING_DAYS;
    }
    return MONTHLY_WORKING_DAYS - (this->offDays - MONTHLY_LEAVE);
  }

  int getSalary() {
    return this->baseSalary * this->getWorkingDays() * 8;
  }
};