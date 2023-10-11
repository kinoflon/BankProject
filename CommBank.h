#ifndef COMMBANK_H
#define COMMBANK_H

#include <string>
#include "Bank.h"
#include "Customer.h"

class CommBank : public Bank {

    protected:
        Customer** newAccount;
        float interestRate;
    
    public:
        CommBank();

};


#endif