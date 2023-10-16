#include "Account.h"

#include <iostream>
#include <string>

using namespace std;

Account::Account() {
    accountNumber = rand() %90000000+10000000;
    bsb = rand() % 900000+100000;
    balance = 0;
    pay = wage/52;
}
Account::Account(float balance) {
    accountNumber = rand() %90000000+10000000;
    bsb = rand() % 900000+100000;
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

void Account::deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

bool Account::withdraw(float amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << endl;
        return true;
    } else {
        cout << "Insufficient balance or invalid withdrawal amount." << endl;
        return false;
    }
}

void Account::showInfo() {
    cout << "Account info:" << endl;
    cout << "account number: " << accountNumber << endl;
    cout << "bsb: " << bsb << endl;
    cout << "balance: " << balance << endl;
    cout << "pay: " << pay << endl;
}

void Account::setLoan(float newLoan) {
    loan = loan + newLoan;
}