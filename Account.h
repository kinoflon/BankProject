#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account();
    Account(float balance);

    int getAccountNum();
    void setAccountNum(int accountNumber);

    int getBSB();
    void setBSB(int bsb);

    float getBalance();
    void setBalance(float balance);

    float getPay();
    void setPay(float pay);

    void showInfo();

    void setLoan(float newLoan);

private:
    int accountNumber;
    int bsb;
    float balance;
    float pay;
    float loan;
};

#endif
