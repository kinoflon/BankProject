#include "Account.h"
#include "Customer.h"  // Including Customer.h header
#include <iostream>
#include <cstdlib>  // Including the C standard library for random number generation
using namespace std;

// Default constructor for Account class
Account::Account() {
    accountNumber = rand() % 90000000 + 10000000;  // Generates an 8-digit random account number
    bsb = rand() % 900000 + 100000;  // Generates a 6-digit random BSB (Bank-State-Branch) code
    balance = 0;  // Initializes the balance to zero
    pay = 0;  // Initializes the pay to zero
}

// Parameterized constructor for Account class
Account::Account(float balance, float wage) {
    accountNumber = rand() % 90000000 + 10000000;  // Generates an 8-digit random account number
    bsb = rand() % 900000 + 100000;  // Generates a 6-digit random BSB (Bank-State-Branch) code
    this->balance = balance;  // Sets the balance to the provided value
    pay = wage / 52;  // Calculates the pay based on the provided wage
}

// Getter for the account number
int Account::getAccountNum() {
    return accountNumber;
}

// Setter for the account number
void Account::setAccountNum(int accountNumber) {
    this->accountNumber = accountNumber;
}

// Getter for the BSB
int Account::getBSB() {
    return bsb;
}

// Setter for the BSB
void Account::setBSB(int bsb) {
    this->bsb = bsb;
}

// Getter for the balance
float Account::getBalance() {
    return balance;
}

// Setter for the balance
void Account::setBalance(float balance) {
    this->balance = balance;
}

// Getter for the pay
float Account::getPay() {
    return pay;
}

// Setter for the pay
void Account::setPay(float pay) {
    this->pay = pay;
}

// Deposit money into the account
void Account::deposit(float amount) {
    if (amount > 0) {
        balance += amount;  // Increase the balance by the deposited amount
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraw money from the account
bool Account::withdraw(float amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;  // Decrease the balance by the withdrawn amount
        cout << "Withdrawal successful. New balance: $" << balance << endl;
        return true;  // Indicate successful withdrawal
    } else {
        cout << "Insufficient balance or invalid withdrawal amount." << endl;
        return false;  // Indicate unsuccessful withdrawal
    }
}

// Display account information
void Account::showInfo() {
    cout << "Account info:" << endl;
    cout << "account number: " << accountNumber << endl;
    cout << "bsb: " << bsb << endl;
    cout << "balance: $" << balance << endl;
    cout << "pay: $" << pay << endl;
}
