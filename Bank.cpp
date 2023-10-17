#include "Bank.h"
#include "Customer.h"
#include <iostream>

// Default constructor for Bank
Bank::Bank() {
    name = "";
    capacity = 0;
    numAccounts = 1;
}

// Constructor for Bank with a name parameter
Bank::Bank(string name) {
    this->name = name;
    capacity = 0;
    numAccounts = 1;
}

// Method to get the name of the bank
string Bank::getBank() const {
    return name;
}

// Method to generate and display a customer's pay
void Bank::generatePay(Customer* customer) const {
    if (customer != nullptr) {
        float pay = customer->getWage() / 52; // Calculate pay for a week
        cout << "Customer's pay: $" << pay << endl;
    } else {
        cout << "Customer not found." << endl;
    }
}
