#ifndef Westpac_H
#define Westpac_H

#include <string>
#include "Bank.h"
#include "Account.h"

class Westpac : public Bank {

    protected:
        Account** newAccount;
    
    public:
        Westpac();
        Westpac(float capacity);
        
        void generatePay(int accountNumber);

        void addAccount(Account** extraAccount);

        ~Westpac();
};

#endif
