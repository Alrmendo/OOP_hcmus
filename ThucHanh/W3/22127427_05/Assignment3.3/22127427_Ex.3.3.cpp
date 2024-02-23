#include "IntArray.h"

using namespace std;

int main()
{
    MyIntArray a1;
    MyIntArray a2(4);
    int arr[] = {2,2,1,2,7,4,2,7};
    MyIntArray a3(arr,6);
    MyIntArray a4 = a3;
    MyIntArray a5("22127427");

    cout << "Array 1: " << a1.toString() << endl;
    cout << "Array 2: " << a2.toString() << endl;
    cout << "Array 3: " << a3.toString() << endl;
    cout << "Array 4: " << a4.toString() << endl;
    cout << "Array 5: " << a5.toString() << endl;

    MyIntArray a6 = a5.clone();
    cout << "Array 6: " << a6.toString() << endl;
    return 0;
}