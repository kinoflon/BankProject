#include "NAB.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

NAB::NAB() {
    name = "NAB";
    interestRate = 0.0712;
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

NAB::NAB(float capacity) {
    name = "NAB";
    interestRate = 0.0624;
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

void NAB::generatePay(int accountNumber) {

    int whichAccount = accountNumber;

    int newBalance;

    if(numAccounts > 1){

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

float NAB::generateLoan(float loan, int accountNumber) {

    int whichAccount = accountNumber;
    float newLoan;
    float newBalance;

    if(numAccounts > 1) {
        float balance = newAccount[whichAccount]->getBalance();
        float loanOwed = newAccount[whichAccount]->getLoan(0);
        newLoan = loanOwed + loan;
        newBalance = balance + loan;

        newAccount[whichAccount]->setBalance(newBalance);
        newAccount[whichAccount]->setLoan(newLoan);
    }
    else {
        float balance = newAccount[whichAccount]->getBalance();
        float loanOwed = newAccount[whichAccount]->getLoan(0);
        newLoan = loanOwed + loan;
        newBalance = balance + loan;

        newAccount[whichAccount]->setBalance(newBalance);
        newAccount[whichAccount]->setLoan(newLoan);
    }
}

void NAB::updateLoan(float amount, int accountNumber) {

    int whichAccount = accountNumber;
    float newBalance;
    float newLoan;

    float balance = newAccount[whichAccount]->getBalance();
    float loanOwed = newAccount[whichAccount]->getLoan(0);

    newLoan = loanOwed - amount;
    newBalance = balance - amount;

    newAccount[whichAccount]->setBalance(newBalance);
    newAccount[whichAccount]->setLoan(newLoan);
    
}

void NAB::generateInterest(float weeklyPay) {
    
    float increaseInPay;
    
    cout << "The base weekly pay is " << weeklyPay << endl;

    increaseInPay = (weeklyPay * interestRate);

    cout << "Each week, the pay will increase by" << increaseInPay << endl;
}

void NAB::addAccount(Account** extraAccount){

    int temp = numAccounts;
    numAccounts++;

    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);

    newAccount[numAccounts]->getBalance();

}

NAB::~NAB() {
    for(int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}