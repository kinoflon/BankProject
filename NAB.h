#ifndef NAB_H
#define NAB_H

#include <string>
#include "Bank.h"
#include "Account.h"

class NAB : public Bank {

    protected:
        Account** newAccount;
    
    public:
        NAB();
        NAB(float capacity);
        
        void generatePay(int accountNumber);

        void addAccount(Account** extraAccount);

        ~NAB();
};

#endif
