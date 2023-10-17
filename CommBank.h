#ifndef COMMBANK_H
#define COMMBANK_H

#include <string>
#include "Bank.h"
#include "Account.h"

class CommBank : public Bank {
    protected:
        Account** newAccount; // Array to store customer accounts

    public:
        // Default constructor for CommBank
        CommBank();

        // Constructor for CommBank with capacity parameter
        CommBank(float capacity);

        // Method to generate a customer's pay
        void generatePay(int accountNumber);

        // Method to add an account to CommBank
        void addAccount(Account** extraAccount);

        // Destructor for CommBank, responsible for memory cleanup
        ~CommBank();
};

#endif
