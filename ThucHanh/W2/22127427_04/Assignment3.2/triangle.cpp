#include "triangle.h"

void Point::Input()
{
    cout << "\nInput x value: ";
    cin >> x;
    cout << "Input y value: ";
    cin >> y;
}

void Point::Output()
{
    cout << "(" << x << "," << y << ")";
}

float Point::Distance(Point point)
{
    return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
}

double Point::DistanceToOx()
{
    return fabs(y);
}

double Point::DistanceToOy()
{
    return fabs(x);
}

void Point::setX(int point)
{
    x = point;
}

void Point::setY(int point)
{
    y = point;
}

void Triangle::Input()
{
    cout << "\nInput A: ";
    A.Input();
    cout << "\nInput B: ";
    B.Input();
    cout << "\nInput C: ";
    C.Input();
}

void Triangle::Output()
{
    A.Output();
    B.Output();
    C.Output();
}

bool Triangle::IsValidTriangle()
{
    double AB = A.Distance(B);
    double AC = A.Distance(C);
    double BC = B.Distance(C);
    double BA = B.Distance(A);
    double CA = C.Distance(A);
    double CB = C.Distance(B);
    
    if(AB + AC > BC && BA + BC > AC && CA + CB > AB && AB > 0 && BC > 0 && AC > 0)
    {
        return true;
    }

    return false;
}

void Triangle::TypeOfTriangle()
{
    double AB = A.Distance(B);
    double AC = A.Distance(C);
    double BC = B.Distance(C);
    double BA = B.Distance(A);
    double CA = C.Distance(A);
    double CB = C.Distance(B);

    if(!IsValidTriangle())
    {
        return;
    }

    if (AB == AC || BA == BC || CA == CB)
    {
        if(AB == AC == BC)
        {
            cout << "\nEquilateral triangle";
        }
        else
        {
            cout << "\nIsoseles triangle";
        }
    }
    
    if (pow(AB,2) + pow(AC,2) == pow(BC,2) || pow(BA,2) + pow(BC,2) == pow(AC,2) || pow(CA,2) + pow(CB,2) == pow(AB,2))
    {
        cout << "\nRight-angled triangle";
    }
    else
    {
        cout << "\nNormal triangle";
    }
}

double Triangle::Perimeter()
{
    float per = A.Distance(B) + B.Distance(C) + C.Distance(A);
    return per;
}

double Triangle::Area()
{
    float p = Perimeter()/2;
    float area = abs(p * (p - A.Distance(B)) * (p - A.Distance(C)) * (p - B.Distance(C)));
    return area;
}

Point Triangle::CenterG () 
{
    Point g;
    g.setX((A.DistanceToOy() + B.DistanceToOy() + C.DistanceToOy())/3);
    g.setY((A.DistanceToOx() + B.DistanceToOx() + C.DistanceToOx())/3);
    return g;
}



