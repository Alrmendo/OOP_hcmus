#ifndef PHAN_SO_H_
#define PHAN_SO_H_
#include <iostream>
using namespace std;

class PhanSo {
private:
  int tu, mau;
public:
  float giaTri();
  void xuat();
  void nhap();
  PhanSo cong(PhanSo ps);
};
#endif 