#include "ANZ.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

ANZ::ANZ() {
    name = "ANZ";
    interestRate = 0.0735;
    newAccount = new Account*[numAccounts];
    capacity = 0;
}

ANZ::ANZ(float capacity) {
    name = "ANZ";
    interestRate = 0.0624;
    newAccount = new Account*[numAccounts];
    this->capacity = capacity;
}

void ANZ::generatePay(int accountNumber) {

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

float ANZ::generateLoan(float loan, int accountNumber) {

    int whichAccount = accountNumber;
    float newLoan;
    float newBalance;

    if(numAccounts > 1) {
        float balance = newAccount[whichAccount]->getBalance();
        float loanOwed = newAccount[whichAccount]->getLoan();
        newLoan = loanOwed + loan;
        newBalance = balance + loan;

        newAccount[whichAccount]->setBalance(newBalance);
        newAccount[whichAccount]->setLoan(newLoan);
    }
    else {
        float balance = newAccount[whichAccount]->getBalance();
        float loanOwed = newAccount[whichAccount]->getLoan();
        newLoan = loanOwed + loan;
        newBalance = balance + loan;

        newAccount[whichAccount]->setBalance(newBalance);
        newAccount[whichAccount]->setLoan(newLoan);
    }
}

void ANZ::updateLoan(float amount, int accountNumber) {

    int whichAccount = accountNumber;
    float newBalance;
    float newLoan;

    float balance = newAccount[whichAccount]->getBalance();
    float loanOwed = newAccount[whichAccount]->getLoan();

    newLoan = loanOwed - amount;
    newBalance = balance - amount;

    newAccount[whichAccount]->setBalance(newBalance);
    newAccount[whichAccount]->setLoan(newLoan);
    
}

void ANZ::generateInterest(float weeklyPay) {
    
    float increaseInPay;
    
    cout << "The base weekly pay is " << weeklyPay << endl;

    increaseInPay = (weeklyPay * interestRate);

    cout << "Each week, the pay will increase by" << increaseInPay << endl;
}

void ANZ::addAccount(Account** extraAccount){

    int temp = numAccounts;
    numAccounts++;

    copy(newAccount, newAccount + min(temp, numAccounts), newAccount);

    newAccount[numAccounts]->getBalance();

}

ANZ::~ANZ() {
    for(int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}