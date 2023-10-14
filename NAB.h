#ifndef NAB_H
#define NAB_H

#include <string>
#include "Bank.h"
#include "Account.h"

class NAB : public Bank {

    protected:
        Account** newAccount;
        float interestRate;
    
    public:
        NAB();
        NAB(float capacity);
        
        void generatePay(int accountNumber);
        float generateLoan(float loan, int accountNumber);
        void updateLoan(float amount, int accountNumber);
        void generateInterest(float weeklyPay);

        void addAccount(Account** extraAccount);

        ~NAB();


};


#endif