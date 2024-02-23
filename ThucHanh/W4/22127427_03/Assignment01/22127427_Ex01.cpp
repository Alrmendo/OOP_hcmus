#include "Fraction.h"

int main()
{
	Fraction f1, f2;
	Fraction f3(1, -7);
	Fraction f4(f3);
	Fraction f5 = f2;
	Fraction f6, f7, f8;
	
	f6=f3;

	f7=f1+f5;
	f8=f2-f4;
	f2=f3*f4;
	f5=f6/f3;

	cout << endl;
	cout<<(f2==f3);
	cout << endl;
	cout<<(f3!=f1);
	cout << endl;
	cout<<(f2>=f5);
	cout << endl;
	cout<<(f2>f5);
	cout << endl;
	cout<<(f5<=f3);
	cout << endl;
	cout<<(f5<f3);


	f1=f2+3;
	f3=-7+f1;
	f5=7*f3;
	f6=f4-6;

    cout << endl;
	cout<<f3;
    cout << endl;
	cout<<f6;

	f1+=f5;
	f6-=f7;
	f8*=f1;
	f8/=f2;

	cout << endl;
	cout<<f8++;
	cout << endl;
	cout<<++f7;
	
	cout << endl;
	cout<<f8--;
	cout << endl;
	cout<<--f7;
	
    cout << endl;
    float f=(float)f3;
    cout << f << endl;

	return 0;
}