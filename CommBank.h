#ifndef COMMBANK_H
#define COMMBANK_H

#include <string>
#include "Bank.h"
#include "Account.h"

class CommBank : public Bank {

    protected:
        Account** newAccount;
        float interestRate;
    
    public:
        CommBank();
        CommBank(float capacity);
        
        void generatePay(int accountNumber);
        float generateLoan(float loan, int accountNumber);
        void updateLoan(float amount, int accountNumber);
        void generateInterest(float weeklyPay);

        void addAccount(Account** extraAccount);

        ~CommBank();


};


#endif