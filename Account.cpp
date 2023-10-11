#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

Account::Account() {
    accountNumber;
    bsb;
    balance = 0;
    pay = wage/52;
}
Account::Account(float balance) {
    accountNumber;
    bsb;
    this->balance = balance;
    pay = wage/52;
}

int Account::getAccountNum() {
    return accountNumber;
}

void Account::setAccountNum(int accountNumber) {
    this->accountNumber = accountNumber;
}

int Account::getBSB() {
    return bsb;
}

void Account::setBSB(int bsb) {
    this->bsb = bsb;
}

float Account::getBalance() {
    return balance;
}

void Account::setBalance(float balance) {
    this->balance = balance;
}

float Account::getPay() {
    return pay;
}

void Account::setPay(float pay) {
    this->pay = pay;
}

void Account::showInfo() {
    cout << "Customer info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
    cout << "loan: " << loan << endl;
    cout << "credit score: " << creditScore << endl;
    cout << "account number: " << accountNumber << endl;
    cout << "bsb: " << bsb << endl;
    cout << "balance: " << balance << endl;
    cout << "pay: " << pay << endl;
}