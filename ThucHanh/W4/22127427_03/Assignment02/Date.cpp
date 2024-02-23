#include "Date.h"

Date::Date()
{
    this -> day = 2;
    this -> month = 11;
    this -> year = 2012;
}

Date::Date(int d)
{
    this -> day = d;
    this -> month = 1;
    this -> year = 1;
}

Date::Date(int d, int m)
{
    this -> day = d;
    this -> month = m;
    this -> year = 1;
}

Date::Date(int d, int m, int y)
{
    this -> day = d;
    this -> month = m;
    this -> year = y;
}

bool Date::checkLeapYear()
{
    if(year % 400 == 0)
    {
        return true;
    }
    if(year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    return false;
}

void Date::Input() 
{
    cout << "\nInput day/ month/ year: ";
    cin >> day >> month >> year;
    if(day <= 0 || day > 31|| month <= 0 || month > 12|| year <= 0) 
    {
        cout << "\nError";
        Input();
    }
    if (month == 2) 
    {
        if (checkLeapYear() == true && day > 29) 
        {
            cout << "\nError";
            Input();
        }
        if (checkLeapYear() == true && day > 28) 
        {
            cout << "\nError";
            Input();
        }
    }
    if(month == 4 || month == 6 || month == 9 || month == 11) 
    {
        if (day > 30) 
        {
            cout << "\nError";
            Input();
        }
    }
}

istream& operator >>(istream &in, Date& d) 
{
    cout << "\nInput day/ month/ year: ";
    in >> d.day >> d.month >> d.year;
    if(d.day <= 0 || d.day > 31|| d.month <= 0 || d.month > 12|| d.year <= 0) 
    {
        cout << "\nError";
        in >> d;
    }
    if(d.month == 2) 
    {
        if (d.checkLeapYear() == true && d.day > 29) 
        {
            cout << "\nError";
            in >> d;
        }
        if (d.checkLeapYear() == true && d.day > 28) 
        {
            cout << "\nError";
            in >> d;
        }
    }
    if(d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        if (d.day > 30) 
        {
            cout << "\nError";
            in >> d;
        }
    }
    return in;
}

Date& Date::operator =(const Date& d)
{
    if(this != &d)
    {
        day = d.day;
        month = d.month;
        year = d.year;
    }

    return *this;
}

Date Date::Tomorrow()
{
    Date temp;
    temp.day = day + 1;
    temp.month = month + 1;
    temp.year = year;

    if(day == 31 && month == 12)
    {
        temp.day = 1;
        temp.month = 1;
        temp.year = year + 1;
    }
    else if(day == 31)
    {
        temp.day = 1;
        temp.month = month + 1;
    }
    else if(day == 30)
    {
        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            temp.day = 1;
            temp.month = month + 1;
        }
    }
    else if(month == 2)
    {
        if(day == 29 || (day == 28 && checkLeapYear() == false))
        {
            temp.day = 1;
            temp.month = month + 1;
        }
    }
    return temp;
}

Date Date::Yesterday()
{
    Date temp;
    temp.day = day - 1;
    temp.month = month;
    temp.year = year;

    if(day == 1 && month == 1)
    {
        temp.day = 31;
        temp.month = 12;
        temp.year = year - 1;
    }
    else if(day == 1)
    {
        if(month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        {
            temp.day = 31;
        }
        else if(month == 3)
        {
            if(checkLeapYear() == true)
            {
                temp.day = 29;
            }
            else{
                temp.day = 28;
            }
        }
        else {
            temp.day = 30;
        }
        temp.month = month - 1;
    }
    return temp;
}

bool Date::operator ==(const Date &d)
{
    return((day == d.day) && (month == d.month) && (year == d.year));
}

bool Date::operator !=(const Date &d)
{
    return((day != d.day) || (month != d.month) || (year != d.year));
}

bool Date::operator >=(const Date &d)
{
    if(year < d.year)
    {
        return false;
    }
    else{
        if(month < d.month)
        {
            return false;
        }
        else{
            if(day < d.day)
            {
                return false;
            }
        }
    }
    return true;
}

bool Date::operator <=(const Date &d)
{
    if(year > d.year)
    {
        return false;
    }
    else{
        if(month > d.month)
        {
            return false;
        }
        else{
            if(day > d.day)
            {
                return false;
            }
        }
    }
    return true;
}

bool Date::operator >(const Date &d) {
    if (year > d.year) 
    {
        return true;
    }
    else if (year == d.year) 
    {
        if (month > d.month) 
        {
            return true;
        }
        else if (month == d.month) 
        {
            if (day > d.day) 
            {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator <(const Date &d) {
    if (year < d.year) 
    {
        return true;
    }
    else if (year == d.year) 
    {
        if (month < d.month) 
        {
            return true;
        }
        else if (month == d.month) 
        {
            if (day < d.day) 
            {
                return true;
            }
        }
    }
    return false;
}

Date Date::operator +(int n)
{
    Date temp;
    temp.day = day + n;
    temp.month = month;
    temp.year = year;

    if(temp.day > 28)
    {
        switch(month)
        {
            case 2:
                if(checkLeapYear())
                {
                    temp.day = temp.day - 29;
                }
                else{
                    temp.day = temp.day - 28;
                }
                temp.month = 3;
                break;

            case 12:
                if(temp.day > 31)
                {
                    temp.day = temp.day - 31;
                    temp.month = 1;
                    temp.year = year + 1;
                }
                break;

            case 4: case 6: case 9: case 11:
                if(temp.day > 30)
                {
                    temp.day = temp.day - 30;
                    temp.month = month + 1;
                }
                break;

            default:
                if(temp.day > 31)
                {
                    temp.day = temp.day - 31;
                    temp.month = month + 1;
                }
                break;
        }
    }
    return temp;
}

Date Date::operator -(int n) {
    Date temp;
    temp.day = day - n;
    temp.month = month;
    temp.year = year;

    if(temp.day < 1) {
        switch(month) 
        {
            case 1:
                temp.day = temp.day + 31;
                temp.month = 12;
                temp.year = year - 1;
                break;

            case 3:
                if(checkLeapYear()) 
                {
                    temp.day = temp.day + 29;
                }
                else {
                    temp.day = temp.day + 28;
                }
                temp.month = 2;
                break;

            case 2: case 4: case 6: case 9: case 11:
                temp.day = temp.day + 31;
                temp.month = month - 1;
                break;

            default:
                temp.day = temp.day + 30;
                temp.month = month - 1;
                break;
        }
    }
    return temp;
}

Date& Date::operator ++()
{
    *this = this -> Tomorrow();
    return *this;
}

Date Date::operator ++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator --()
{
    *this = this -> Yesterday();
    return *this;
}

Date Date::operator --(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

Date::operator int() 
{
    int m = month;
    int count = day;
    m -= 1;
    while(m > 0) 
    {
        if(m == 1||m == 3||m == 5||m == 7||m == 8||m == 10) 
        {
            count += 31;
        }
        else if(m == 4||m == 6||m == 9||m == 11) 
        {
            count += 30;
        }
        else {
            if(checkLeapYear()) 
            {
                count += 29;
            }
            else {
                count += 28;
            }
        }
        m--;
    }
    return count - 1;
}

Date::operator long() 
{
    Date temp = *this;

    long count = 0;
    count += (int)*this;

    temp.year--;
    while(temp.year > 0) 
    {
        if(temp.checkLeapYear())
        {
            count += 366;
        }
        else{
            count += 365;
        }
        temp.year--;
    }
    return count - 1;
}

Date& Date::operator +=(int n) 
{
    Date temp = *this;
    temp = temp + n;
    *this = temp;
    return *this;
}

Date& Date::operator -=(int n) 
{
    Date temp = *this;
    temp = temp - n;
    *this = temp;
    return *this;
}

ostream& operator << (ostream &out, const Date &d) 
{
    out << d.day << "/" << d.month << "/" << d.year << "\n";
    return out;
}