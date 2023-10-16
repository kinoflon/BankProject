#include "Customer.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

Customer::Customer() {
    customerId = 0;
    bank = "";
    // loan = 0;
    creditScore = 0;
    account = nullptr;
}

Customer::Customer(string name) {
    this->name = name;
    customerId = 0;
    bank = "";
    // loan = 0;
    creditScore = 0;
    account = nullptr;
}

void Customer::setAccount(Account* account) { // Corrected the parameter type to Account*
    this->account = account;
}

Customer::Customer(int customerId) {
    this->customerId = customerId;
    bank = "";
    loan = 0;
    creditScore = 0;
    account = nullptr;
}

void Customer::setCustomerID(int id) {
    // Ensure the customer ID is a 3-digit number
    if (id >= 100 && id <= 999) {
        customerId = id;
    } else {
        cout << "Invalid customer ID. It should be a 3-digit number." << endl;
    }
}

int Customer::getID() const {
    return customerId;
}

void Customer::setID(int customerId) {
    this->customerId = customerId;
}

string Customer::getBank() const {
    return bank;
}

void Customer::setBank(string bank) {
    this->bank = bank;
}

float Customer::getCreditScore() const {
    return creditScore;
}

float Customer::getLoan(float loanAmount) const {
    loan += loanAmount;
    return loan;
}

Account* Customer::getAccount() const {
    return account;
}


void Customer::showInfo() const {
    cout << "Customer info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
    cout << "loan: " << loan << endl;
    cout << "credit score: " << creditScore << endl;
}
