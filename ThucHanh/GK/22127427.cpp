/*
Ho va Ten: Nguyen Minh Triet
MSSV: 22127427
*/

#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class NgayThang
{
private:
    int ngay, thang, nam;

public:
    void KiemTra()
    {
        if (ngay < 1) ngay = 1;
        if (thang < 1) thang = 1;
        if (nam < 1) nam = 1;

        thang += (ngay - 1) / 30;
        ngay = (ngay - 1) % 30 + 1;

        nam += (thang - 1) / 12;
        thang = (thang - 1) % 12 + 1;
    }

    NgayThang();
    NgayThang(int, int, int);
    NgayThang(int, int);
    NgayThang(int);
    NgayThang(const string&);
    NgayThang operator +(int) const;
    NgayThang operator ++();
    NgayThang operator ++(int);

    bool operator>(const NgayThang& other) const
    {
        if (nam != other.nam)
        {
            return nam > other.nam;
        }
        if (thang != other.thang)
        {
            return thang > other.thang;
        }
        return ngay > other.ngay;
    }

    friend ostream& operator<<(ostream& os, const NgayThang& nt);
};

class MangNgayThang
{
private:
    vector<NgayThang*> mangNgayThang;

public:
    ~MangNgayThang()
    {
        for (size_t i = 0; i < mangNgayThang.size(); ++i)
        {
            delete mangNgayThang[i];
        }
    }

    void ThemNgayThang(NgayThang*);
    NgayThang* operator[](int) const;
    NgayThang* NgayThangLonNhat() const;
    friend ostream& operator<<(ostream& os, const MangNgayThang& mnt);
};

void MangNgayThang::ThemNgayThang(NgayThang* nt)
{
    mangNgayThang.push_back(nt);
}

NgayThang* MangNgayThang::operator[](int index) const
{
    return mangNgayThang[index];
}

NgayThang* MangNgayThang::NgayThangLonNhat() const
{
    NgayThang* maxDate = mangNgayThang[0];
    for (size_t i = 0; i < mangNgayThang.size(); ++i)
    {
        if (*mangNgayThang[i] > *maxDate)
        {
            maxDate = mangNgayThang[i];
        }
    }
    return maxDate;
}

ostream& operator<<(ostream& os, const MangNgayThang& mnt)
{
    for (size_t i = 0; i < mnt.mangNgayThang.size(); ++i)
    {
        os << *mnt.mangNgayThang[i];
        if (i < mnt.mangNgayThang.size() - 1)
        {
            os << "; ";
        }
    }
    return os;
}

NgayThang::NgayThang() : ngay(1), thang(1), nam(1)
{
    KiemTra();
}

NgayThang::NgayThang(int ngay, int thang, int nam)
    : ngay(ngay), thang(thang), nam(nam)
{
    KiemTra();
}

NgayThang::NgayThang(int ngay, int thang)
    : ngay(ngay), thang(thang), nam(1)
{
    KiemTra();
}

NgayThang::NgayThang(int ngay)
    : ngay(ngay), thang(1), nam(1)
{
    KiemTra();
}

NgayThang::NgayThang(const string& ngayThangString)
{
    istringstream ss(ngayThangString);
    
    ss >> ngay;
    ss.ignore();
    ss >> thang;
    ss.ignore();
    ss >> nam;

    KiemTra();
}

NgayThang NgayThang::operator+(int days) const 
{
    NgayThang temp(*this);
    temp.ngay += days;
    temp.KiemTra();
    return temp;
}

NgayThang NgayThang::operator++()
{
    ngay++;
    KiemTra();
    return *this;
}

NgayThang NgayThang::operator++(int)
{
    NgayThang temp(*this);
    ++ngay;
    KiemTra();
    return temp;
}

ostream& operator<<(ostream& os, const NgayThang& nt)
{
    os << nt.ngay << "/" << nt.thang << "/" << nt.nam;
    return os;
}


int main()
{
    MangNgayThang mnt;
    /// 1.0 điểm: không lỗi biên dịch
    mnt.ThemNgayThang(new NgayThang(90, 110, -1923));
    mnt.ThemNgayThang(new NgayThang("09/11/2023"));
    mnt.ThemNgayThang(new NgayThang(119000));
    mnt.ThemNgayThang(new NgayThang);
    /// 1.0 điểm: khởi tạo object hợp lý
    /// xuất ra dạng: 'x/x/x' ; vd: '3/2/1900'
    /// phân tách các NgayThang bằng "; "
    /// 1.0 điểm: xuất định dạng: dd/mm/yyyy
    cout << "MangNgayThang: " << mnt << endl;
    /// 1.0 điểm
    delete mnt[3];
    // mnt[3] = new NgayThang(123456);
    /// 1.5 điểm (lưu ý toán tử ++, +int áp dụng lên ngày)
    // mnt.ThemNgayThang(*mnt[0] + *mnt[1]);
    // mnt.ThemNgayThang(*mnt[0] + 119);
    // mnt.ThemNgayThang(911 + *mnt[0]);
    /// 1.5 điểm
    // mnt.ThemNgayThang(191 + (*mnt[1])++ + ++(*mnt[2]));
    cout << "MangNgayThang: " << mnt << endl;
    /// 2.0 điểm: xuất ngày tháng lớn nhất (lưu ý operator)
    cout << "Ngay Thang lon nhat: " << *mnt.NgayThangLonNhat() << endl;
    /// 1.0 điểm: ngày tối đa mỗi tháng hợp lý
    /// (vd: tháng 2 có 28~29 ngày, tháng 7 có 31 ngày).
    system("pause");
    return 0;
}