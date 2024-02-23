#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    long int accountNumber;
    string ownerName;
    long int ownerSocialID;
    double balance;

public:
    void input();
    void printToConsole();
    void deposit(double);
    void withdraw(double);
    double checkBalance();
};
#endif