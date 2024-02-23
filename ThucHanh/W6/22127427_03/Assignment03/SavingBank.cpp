#include "SavingBank.h"

void SavingBankAccount::input() 
{
    BankAccount::input();
    cout << "Enter annual interest rate: ";
    cin >> annualInterestRate;
    cout << "Enter period (in months): ";
    cin >> period;
    cout << "Enter number of saving months until now: ";
    cin >> savingMonths;
}

void SavingBankAccount::printToConsole()
{
    BankAccount::printToConsole();
    cout << endl;
    cout << "Annual interest rate: " << annualInterestRate << "%" << endl;
    cout << "Period: " << period << " months" << endl;
    cout << "Number of saving months until now: " << savingMonths << " months" << endl;
}

void SavingBankAccount::deposit(double amount) 
{
    do {
        if (savingMonths < period) 
        {
            cout << "Cannot deposit. Number of saving months is less than the period." << endl;
            break;
        } 
        else 
        {
            BankAccount::deposit(amount);
            break;
        }
    } while (true);
}

void SavingBankAccount::withdraw(double amount) 
{
    do {
        if (savingMonths < period) 
        {
            cout << "Cannot withdraw. Number of saving months is less than the period." << endl;
            break;
        } 
        else 
        {
            BankAccount::withdraw(amount);
            break;
        }
    } while (true);
}

void SavingBankAccount::withdrawImmediately(double amount)
{
    BankAccount::withdraw(amount);
    annualInterestRate = 2;
}

double SavingBankAccount::checkBalance()
{
    double interest = balance * annualInterestRate / 100 * savingMonths / 12;
    return balance + interest;
}

double SavingBankAccount::checkInterest() 
{
    double interest = balance * annualInterestRate / 100 * savingMonths / 12;
    return interest;
}