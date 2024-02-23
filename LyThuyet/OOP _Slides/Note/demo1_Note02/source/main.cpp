#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "PhanSo.h"
using namespace std;

int main() {
  // Car car1;
  // car1.setSerial(123456);
  // car1.setManufacturer("Tesla");
  // car1.setColor("Black");
  // car1.setIsEV(true);
  // car1.print();

  // Employee* e1 = new Employee();
  // e1->setId("VNDP1001");
  // e1->setBaseSalary(300000);
  // e1->setOffDays(3);
  // cout << e1->getSalary() << endl;

  // Employee* e2 = new Employee();
  // e2->setId("VNDP1002");
  // e2->setBaseSalary(200000);
  // e2->setOffDays(0);
  // cout << e2->getSalary() << endl;

  // delete e1;
  // delete e2;

  PhanSo ps1;
  cout << "Nhap phan so 1: ";
  ps1.nhap();

  PhanSo ps2;
  cout << "Nhap phan so 2: ";
  ps2.nhap();
  cout << "Tong cua ";
  ps1.xuat();
  cout << " va ";
  ps2.xuat();
  cout << " la ";
  PhanSo kq = ps1.cong(ps2).cong(ps2);
  kq.xuat();

  return 0; 
}
