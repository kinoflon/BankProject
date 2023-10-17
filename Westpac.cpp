#include "Westpac.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor for Westpac without capacity parameter
Westpac::Westpac() {
    name = "Westpac";
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

// Constructor for Westpac with capacity parameter
Westpac::Westpac(float capacity) {
    name = "Westpac";
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

// Method to generate a customer's pay
void Westpac::generatePay(int accountNumber) {

    int whichAccount = accountNumber;

    int newBalance;

    if (numAccounts > 1) {
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();

        newBalance = balance + pay;

        newAccount[whichAccount]->setBalance(newBalance);
    } else {
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();

        newBalance = balance + pay;

        newAccount[whichAccount]->setBalance(newBalance);
    }
}

// Method to add an account to Westpac
void Westpac::addAccount(Account** extraAccount) {

    int temp = numAccounts;
    numAccounts++;

    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);

    newAccount[numAccounts]->getBalance();
}

// Destructor for Westpac, responsible for memory cleanup
Westpac::~Westpac() {
    for (int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}
