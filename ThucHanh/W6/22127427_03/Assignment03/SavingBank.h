#ifndef SAVING_BANK_ACCOUNT_H
#define SAVING_BANK_ACCOUNT_H
#include "BankAcc.h"

class SavingBankAccount : public BankAccount
{
protected:
    double annualInterestRate;
    int period;
    int savingMonths;

public:
    void input();
    void printToConsole();
    void deposit(double);
    void withdraw(double);
    double checkBalance();
    void withdrawImmediately(double);
    double checkInterest();
};

#endif
