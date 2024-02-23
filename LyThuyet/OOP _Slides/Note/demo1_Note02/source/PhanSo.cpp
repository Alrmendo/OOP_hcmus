#include "PhanSo.h"

float PhanSo::giaTri() {
  return 1.0 * this->tu / this->mau;
}

void PhanSo::xuat() {
  cout << this->tu << "/" << this->mau;
}

void PhanSo::nhap() {
  cin >> this->tu >> this->mau;
}

PhanSo PhanSo::cong(PhanSo ps) {
  PhanSo kq;
  kq.mau = this->mau * ps.mau;
  kq.tu = this->tu * ps.mau + ps.tu * this->mau;
  return kq;
}