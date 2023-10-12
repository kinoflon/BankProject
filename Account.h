#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"
#include <string>
using namespace std;


class Account : public Customer {

    protected:
        int accountNumber;
        int bsb;
        float balance;
        float pay;

        float loanOwed;

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

};


#endif