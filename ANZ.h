#ifndef ANZ_H
#define ANZ_H

#include <string>
#include "Bank.h"
#include "Account.h"

class ANZ : public Bank {

    protected:
        Account** newAccount;
        float interestRate;
    
    public:
        ANZ();
        ANZ(float capacity);
        
        void generatePay(int accountNumber);
        float generateLoan(float loan, int accountNumber);
        void updateLoan(float amount, int accountNumber);
        void generateInterest(float weeklyPay);

        void addAccount(Account** extraAccount);

        ~ANZ();


};


#endif