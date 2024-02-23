#include "BankAcc.h"

void BankAccount::input()
{
    cout << "Enter account number: ";
    cin >> accountNumber;
    cin.ignore();
    cout << "Enter owner name: ";
    getline(cin, ownerName);
    cout << "Enter owner social ID: ";
    cin >> ownerSocialID;
    cout << "Enter balance: ";
    cin >> balance;
}

void BankAccount::printToConsole()
{
    cout << "Account number: " << accountNumber << endl;
    cout << "Owner name: " << ownerName << endl;
    cout << "Owner social ID: " << ownerSocialID << endl;
    cout << "Balance: " << balance;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
}

void BankAccount::withdraw(double amount) 
{
    do {
        if (balance - amount >= 50000) 
        {
            balance -= amount;
            break;
        } 
        else 
        {
            cout << "Insufficient balance. Minimum balance should be 50,000 VND." << endl;
            cout << "Enter a valid withdrawal amount: ";
            cin >> amount;
        }
    } while (true);
}

double BankAccount::checkBalance()
{
    return balance;
}
