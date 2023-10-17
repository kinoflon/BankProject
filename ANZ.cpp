#include "ANZ.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor for ANZ without capacity parameter
ANZ::ANZ() {
    name = "ANZ";
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

// Constructor for ANZ with capacity parameter
ANZ::ANZ(float capacity) {
    name = "ANZ";
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

// Method to generate a customer's pay
void ANZ::generatePay(int accountNumber) {

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

// Method to add an account to ANZ
void ANZ::addAccount(Account** extraAccount) {

    int temp = numAccounts;
    numAccounts++;

    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);

    newAccount[numAccounts]->getBalance();
}

// Destructor for ANZ, responsible for memory cleanup
ANZ::~ANZ() {
    for (int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}
