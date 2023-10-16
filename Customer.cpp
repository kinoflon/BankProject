#include "Customer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Customer::Customer(const std::string& name, const std::string& bank)
    : name(name), bank(bank) {
    // Generate a random 3-digit customer ID
    srand(time(nullptr));
    customerID = 100 + rand() % 900;
    balance = 0;
}

int Customer::getID() const {
    return customerID;
}

void Customer::deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit of $" << amount << " successful." << std::endl;
    } else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

void Customer::withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawal of $" << amount << " successful." << std::endl;
    } else {
        std::cout << "Invalid withdrawal amount or insufficient balance." << std::endl;
    }
}

void Customer::displayInfo() const {
    std::cout << "Customer ID: " << customerID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Bank: " << bank << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
}



// #include "Customer.h"
// #include "Account.h"

// #include <iostream>
// #include <string>

// using namespace std;


// Customer::Customer() {
//     customerId = 0;
//     bank = "";
//     // loan = 0;
//     account = nullptr;
// }

// Customer::Customer(const string& name, const string& bank, int customerID) {
//     this->name = name;
//     this->customerId = customerID;
//     this->bank = bank;
//     this->loan = 0;
//     this->account = nullptr;
// }

// void Customer::setAccount(Customer* account) {
//     this->account = account;
// }

// Customer::Customer(int customerId) {
//     this->customerId = customerId;
//     bank = "";
//     loan = 0;
//     account = nullptr;
// }

// int Customer::getID() const {
//     return customerId;
// }

// void Customer::setID(int customerId) {
//     this->customerId = customerId;
// }

// string Customer::getBank() const {
//     return bank;
// }

// void Customer::setBank(string bank) {
//     this->bank = bank;
// }

// float Customer::getLoan(float loanAmount) const {
//     loan += loanAmount;
//     return loan;
// }

// void Customer::showInfo() const {
//     cout << "Customer info:" << endl;
//     cout << "name: " << name << endl;
//     cout << "wage: " << wage << endl;
//     cout << "customer ID: " << customerId << endl;
//     cout << "bank: " << bank << endl;
//     cout << "loan: " << loan << endl;
// }