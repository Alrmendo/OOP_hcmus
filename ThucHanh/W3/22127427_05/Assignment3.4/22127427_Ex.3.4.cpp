#include "student.h"

using namespace std;

int main()
{
    Student s1;
    Student s2(12345,"Nguyen Minh Triet", "HCM", 9.0);
    Student s3 = s2;
    Student s4(1234567);
    Student s5("Nguyen Hoang Trung Kien");

    cout << "Student 1: " << s1.toString() << endl;
    cout << "Student 2: " << s2.toString() << endl;
    cout << "Student 3: " << s3.toString() << endl;
    cout << "Student 4: " << s4.toString() << endl;
    cout << "Student 5: " << s5.toString() << endl;

    Student s6 = s2.clone();
    cout << "Student 6: " << s6.toString() << endl;

}