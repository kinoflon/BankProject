#ifndef NAB_H
#define NAB_H

#include <string>
#include "Bank.h"
#include "Account.h"

class NAB : public Bank {
    protected:
        Account** newAccount; // Array to store customer accounts

    public:
        // Default constructor for NAB
        NAB();

        // Constructor for NAB with capacity parameter
        NAB(float capacity);

        // Method to generate a customer's pay
        void generatePay(int accountNumber);

        // Method to add an account to NAB
        void addAccount(Account** extraAccount);

        // Destructor for NAB, responsible for memory cleanup
        ~NAB();
};

#endif
