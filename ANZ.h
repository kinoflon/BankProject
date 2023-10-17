#ifndef ANZ_H
#define ANZ_H

#include <string>
#include "Bank.h"
#include "Account.h"

class ANZ : public Bank {

    protected:
        Account** newAccount;
    
    public:
        ANZ();
        ANZ(float capacity);
        
        void generatePay(int accountNumber);

        void addAccount(Account** extraAccount);

        ~ANZ();
};

#endif
