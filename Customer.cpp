#include "Customer.h"
#include "Account.h"
#include <iostream>
using namespace std;

Customer::Customer() {
    customerId = 0;
    bank = "";
    account = nullptr;
}

Customer::Customer(string name, float wage) : Person(name, wage) {
    customerId = 0;
    bank = "";
    account = nullptr;
}

void Customer::setAccount(Account* account) {
    this->account = account;
}

Customer::Customer(int customerId) {
    this->customerId = customerId;
    bank = "";
    account = nullptr;
}

void Customer::setCustomerID(int id) {
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

float Customer::getPay() const {
    return pay;
}

void Customer::setPay(float pay) {
    this->pay = pay;
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
}
