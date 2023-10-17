#include "CommBank.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor for CommBank without capacity parameter
CommBank::CommBank() {
    name = "CommBank";
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

// Constructor for CommBank with a capacity parameter
CommBank::CommBank(float capacity) {
    name = "CommBank";
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

// Method to generate a customer's pay
void CommBank::generatePay(int accountNumber) {
    // Get the customer's account number
    int whichAccount = accountNumber;

    int newBalance;

    if (numAccounts > 1) {
        // Calculate the new balance by adding the pay to the current balance
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();
        newBalance = balance + pay;

        // Set the new balance
        newAccount[whichAccount]->setBalance(newBalance);
    } else {
        // Calculate the new balance by adding the pay to the current balance
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();
        newBalance = balance + pay;

        // Set the new balance
        newAccount[whichAccount]->setBalance(newBalance);
    }
}

// Method to add an account to CommBank
void CommBank::addAccount(Account** extraAccount) {
    int temp = numAccounts;
    numAccounts++;

    // Copy the accounts and get the balance of a new account
    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);
    newAccount[numAccounts]->getBalance();
}

// Destructor for CommBank
CommBank::~CommBank() {
    // Clean up dynamically allocated memory for accounts
    for (int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}
