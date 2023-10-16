#include "Customer.h"
#include "Account.h"

#include <iostream>
#include <string>

using namespace std;


Customer::Customer() {
    customerId = 0;
    bank = "";
    // loan = 0;
    account = nullptr;
}

Customer::Customer(string name) {
    this->name = name;
    customerId = 0;
    bank = "";
    // loan = 0;
    account = nullptr;
}

void Customer::setAccount(Customer* account) {
    this->account = account;
}

Customer::Customer(int customerId) {
    this->customerId = customerId;
    bank = "";
    loan = 0;
    account = nullptr;
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

float Customer::getLoan(float loanAmount) const {
    loan += loanAmount;
    return loan;
}

void Customer::showInfo() const {
    cout << "Customer info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
    cout << "loan: " << loan << endl;
}