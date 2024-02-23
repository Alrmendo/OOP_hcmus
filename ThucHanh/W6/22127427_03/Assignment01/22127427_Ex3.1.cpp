#include "ABCfarm.h"

int main() 
{
    ABCFarm myFarm;

    cout << "ABC Farm Management System!" << endl;

    myFarm.Input();

    cout << "\nFarm Details:" << endl;
    myFarm.Output();

    int minAge, maxAge;
    cout << "\nEnter the age range for filtering animals:" << endl;
    cout << "Minimum Age: ";
    cin >> minAge;
    cout << "Maximum Age: ";
    cin >> maxAge;

    cout << "\nAnimals within the age range " << minAge << " to " << maxAge << ":" << endl;
    myFarm.OutputByAge(minAge, maxAge);


    return 0;
}
