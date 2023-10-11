#include "CommBank.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

CommBank::CommBank() {
    name = "CommBank";
    interestRate = 0.0624;
    loanOwed = 0;
    newAccount = new Account*[numAccounts];
}

CommBank::CommBank(float loanOwed) {
    name = "CommBank";
    interestRate = 0.0624;
    this->loanOwed = loanOwed;
    newAccount = new Account*[numAccounts];
}

void CommBank::generatePay() {

    float balance = newAccount[0]->getBalance();
    float pay = newAccount[0]->getPay();
    
    balance = balance + pay;
}

float CommBank::generateLoan(float loan, float weeklyPay) {
    
    float balance = newAccount[0]->getBalance();
    float pay = newAccount[0]->getPay();

    loanOwed = loan;
    balance = balance + loan;
}

void CommBank::updateLoan(float amount) {
    loanOwed = loanOwed - amount;
}

void CommBank::generateInterest() {

}

CommBank::~CommBank() {
    for(int i = 0; i < numAccounts; i++) {
        delete newAccount[i];
    }
    delete newAccount;
}
