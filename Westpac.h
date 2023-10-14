#ifndef Westpac_H
#define Westpac_H

#include <string>
#include "Bank.h"
#include "Account.h"

class Westpac : public Bank {

    protected:
        Account** newAccount;
        float interestRate;
    
    public:
        Westpac();
        Westpac(float capacity);
        
        void generatePay(int accountNumber);
        float generateLoan(float loan, int accountNumber);
        void updateLoan(float amount, int accountNumber);
        void generateInterest(float weeklyPay);

        void addAccount(Account** extraAccount);

        ~Westpac();


};


#endif