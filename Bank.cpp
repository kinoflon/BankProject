#include "Bank.h"

#include <iostream>
#include <string>

using namespace std;

Bank::Bank() {
    name = "";
    capacity = 0;
    numAccounts = 0;
}

Bank::Bank(string name) {
    this->name = name;
    capacity = 0;
    numAccounts = 0;
}

void Bank::generatePay() {
    return;
}

float Bank::generateLoan() {
    return;
}

void Bank::updateLoan() {
    return;
}