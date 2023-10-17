#ifndef COMMBANK_H
#define COMMBANK_H

#include <string>
#include "Bank.h"
#include "Account.h"

class CommBank : public Bank {

    protected:
        Account** newAccount;
    
    public:
        CommBank();
        CommBank(float capacity);
        
        void generatePay(int accountNumber);

        void addAccount(Account** extraAccount);

        ~CommBank();
};

#endif
