#include "triangle.h"

using namespace std;

int main()
{
    Triangle p1;

    point2D a(2,3);
    Triangle p2(a);

    point2D a1(5,6);
    point2D a2(1,4);
    point2D a3(-5,12);
    Triangle p3(a1,a2,a3);

    point2D a4("12,3");
    point2D a5("1,6");
    point2D a6("5,1");
    Triangle p4(a4,a5,a6);

    Triangle p5(p4);

    cout << p1.toString() << endl;
    cout << p2.toString() << endl;
    cout << p3.toString() << endl;
    cout << p4.toString() << endl;
    cout << p5.toString() << endl;
}