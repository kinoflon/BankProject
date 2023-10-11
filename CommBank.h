#ifndef COMMBANK_H
#define COMMBANK_H

#include <string>
#include "Bank.h"
#include "Account.h"

class CommBank : public Bank {

    protected:
        Account** newAccount;
        float interestRate;
        float loanOwed;
    
    public:
        CommBank();
        CommBank(float loanOwed);
        
        void generatePay();
        float generateLoan(float loan, float weeklyPay);
        void updateLoan(float amount);
        void generateInterest();

        ~CommBank();


};


#endif