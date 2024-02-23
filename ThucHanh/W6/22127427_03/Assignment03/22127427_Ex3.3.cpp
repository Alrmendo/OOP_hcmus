#include "SavingBank.h"

int main() 
{
    SavingBankAccount acount1;

    acount1.input();

    double depositAmount;
    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    acount1.deposit(depositAmount);

    double withdrawAmount;
    cout << "Enter withdraw amount: ";
    cin >> withdrawAmount;
    acount1.withdraw(withdrawAmount);


    cout << endl;
    acount1.printToConsole();


    cout << "Current balance: " << acount1.checkBalance() << endl;
    cout << "Accrued interest: " << acount1.checkInterest() << endl;


    double immediateWithdrawAmount;
    cout << "\nEnter immediate withdraw amount: ";
    cin >> immediateWithdrawAmount;
    acount1.withdrawImmediately(immediateWithdrawAmount);


    cout << endl;
    acount1.printToConsole();


    cout << "Updated balance: " << acount1.checkBalance() << endl;
    cout << "Updated interest: " << acount1.checkInterest() << endl;

    return 0;
}
