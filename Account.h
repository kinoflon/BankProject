#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Customer; // Forward declaration

class Account {
protected:
    int accountNumber;
    int bsb;
    float balance;
    float pay;

public:
    Account();
    Account(float balance, float wage);
    int getAccountNum();
    void setAccountNum(int accountNumber);
    int getBSB();
    void setBSB(int bsb);
    float getBalance();
    void setBalance(float balance);
    float getPay();
    void setPay(float pay);
    void deposit(float amount);
    bool withdraw(float amount);
    void showInfo();
};

#endif
