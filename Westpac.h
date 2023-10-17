#ifndef Westpac_H
#define Westpac_H

#include <string>
#include "Bank.h"
#include "Account.h"

class Westpac : public Bank {
    protected:
        Account** newAccount; // Array to store customer accounts

    public:
        // Default constructor for Westpac
        Westpac();

        // Constructor for Westpac with capacity parameter
        Westpac(float capacity);

        // Method to generate a customer's pay
        void generatePay(int accountNumber);

        // Method to add an account to Westpac
        void addAccount(Account** extraAccount);

        // Destructor for Westpac, responsible for memory cleanup
        ~Westpac();
};

#endif
