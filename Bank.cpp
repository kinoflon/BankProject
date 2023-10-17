#include "Bank.h"
#include "Customer.h"
#include <iostream>

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

void Bank::generatePay(Customer* customer) const {
    if (customer != nullptr) {
        float pay = customer->getWage() / 52;
        cout << "Customer's pay: $" << pay << endl;
    } else {
        cout << "Customer not found." << endl;
    }
}