#include "Bank.h"

#include <iostream>
#include <string>

using namespace std;

Bank::Bank() {
    name = "";
    capacity = 0;
    numAccounts = 1;
}

Bank::Bank(string name) {
    this->name = name;
    capacity = 0;
    numAccounts = 1;
}

string Bank::getBank() const {
    return name;
}

// void Bank::generatePay() {
//     return;
// }

float Bank::generateLoan() {
    return 0;
}

void Bank::updateLoan() {
    return;
}