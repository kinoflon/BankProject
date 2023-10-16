#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Account::Account() {
    accountNumber = rand() % 90000000 + 10000000;
    bsb = rand() % 900000 + 100000;
    balance = 0;
    pay = 0; // Initialize pay
    loan = 0; // Initialize loan
}

Account::Account(float balance) {
    accountNumber = rand() % 90000000 + 10000000;
    bsb = rand() % 900000 + 100000;
    this->balance = balance;
    pay = 0; // Initialize pay
    loan = 0; // Initialize loan
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
    std::cout << "Account info:" << std::endl;
    std::cout << "account number: " << accountNumber << std::endl;
    std::cout << "bsb: " << bsb << std::endl;
    std::cout << "balance: $" << balance << std::endl;
    std::cout << "pay: $" << pay << std::endl;
    std::cout << "loan: $" << loan << std::endl;
}

void Account::setLoan(float newLoan) {
    loan = loan + newLoan;
}
