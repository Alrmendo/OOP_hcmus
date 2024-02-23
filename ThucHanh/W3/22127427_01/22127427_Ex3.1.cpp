#include "Point2D.h"

int main()
{
    point2D p1;
    point2D p2(10);
    point2D p3(5,3);
    point2D p4(p3);
    point2D p5("15, -2");

    cout << p1.toString() << endl;
    cout << p2.toString() << endl;
    cout << p3.toString() << endl;
    cout << p4.toString() << endl;
    cout << p5.toString() << endl;

    point2D p6 = p3.clone();
    cout << p6.toString() << endl;
    
    return 0;
}