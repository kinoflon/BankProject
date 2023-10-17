#ifndef ANZ_H
#define ANZ_H

#include <string>
#include "Bank.h"
#include "Account.h"

class ANZ : public Bank {
    protected:
        Account** newAccount; // Array to store customer accounts

    public:
        // Default constructor for ANZ
        ANZ();

        // Constructor for ANZ with capacity parameter
        ANZ(float capacity);

        // Method to generate a customer's pay
        void generatePay(int accountNumber);

        // Method to add an account to ANZ
        void addAccount(Account** extraAccount);

        // Destructor for ANZ, responsible for memory cleanup
        ~ANZ();
};

#endif
