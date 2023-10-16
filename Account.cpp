#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

Account::Account() {
    accountNumber = rand() %99999999+10000000;
    bsb = rand() % 99999+10000;
    balance = 0;
    pay = wage/52;
}
Account::Account(float balance) {
    accountNumber = rand() %99999999+10000000;
    bsb = rand() % 99999+10000;
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
    cout << "Account info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
    cout << "loan: " << loan << endl;
    cout << "account number: " << accountNumber << endl;
    cout << "bsb: " << bsb << endl;
    cout << "balance: " << balance << endl;
    cout << "pay: " << pay << endl;
}

void Account::setLoan(float newLoan) {
    loan = loan + newLoan;
}