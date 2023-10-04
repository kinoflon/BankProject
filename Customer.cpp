#include "Customer.h"

#include <iostream>
#include <string>

using namespace std;


Customer::Customer() {
    customerId = 0;
    bank = "";
    loan = 0;
    creditScore = 0;
}

Customer::Customer(int customerId) {
    this->customerId = customerId;
    bank = "";
    loan = 0;
    creditScore = 0;
}

int Customer::getID() {
    return customerId;
}

void Customer::setID(int customerId) {
    this->customerId = customerId;
}

string Customer::getBank() {
    return bank;
}

void Customer::setBank(string bank) {
    this->bank = bank;
}

float Customer::getCreditScore() {
    return creditScore;
}

float Customer::getLoan() {
    return loan;
}

void Customer::showInfo() {
    cout << "Customer info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
    cout << "loan: " << loan << endl;
    cout << "credit score: " << creditScore << endl;
}