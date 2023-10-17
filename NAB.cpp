#include "NAB.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

NAB::NAB() {
    name = "NAB";
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

NAB::NAB(float capacity) {
    name = "NAB";
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

void NAB::generatePay(int accountNumber) {

    int whichAccount = accountNumber;

    int newBalance;

    if(numAccounts > 1) {
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();

        newBalance = balance + pay;

        newAccount[whichAccount]->setBalance(newBalance);
    }
    else {
        float balance = newAccount[whichAccount]->getBalance();
        float pay = newAccount[whichAccount]->getPay();

        newBalance = balance + pay;

        newAccount[whichAccount]->setBalance(newBalance);
    }
}

void NAB::addAccount(Account** extraAccount) {

    int temp = numAccounts;
    numAccounts++;

    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);

    newAccount[numAccounts]->getBalance();

}

NAB::~NAB() {
    for (int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}
