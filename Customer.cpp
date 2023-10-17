#include "Customer.h"  // Include the header file for the Customer class
#include "Account.h"   // Include the header file for the Account class
#include <iostream>
using namespace std;

Customer::Customer() {
    customerId = 0;   // Initialize the customer ID to 0
    bank = "";        // Initialize the bank name to an empty string
    account = nullptr; // Initialize the account pointer to nullptr
}

Customer::Customer(string name, float wage) : Person(name, wage) {
    customerId = 0;   // Initialize the customer ID to 0
    bank = "";        // Initialize the bank name to an empty string
    account = nullptr; // Initialize the account pointer to nullptr
}

void Customer::setAccount(Account* account) {
    this->account = account; // Set the account associated with the customer
}

Customer::Customer(int customerId) {
    this->customerId = customerId; // Initialize the customer ID with the provided value
    bank = "";                     // Initialize the bank name to an empty string
    account = nullptr;            // Initialize the account pointer to nullptr
}

void Customer::setCustomerID(int id) {
    if (id >= 100 && id <= 999) {
        customerId = id; // Set the customer ID if it's a valid 3-digit number
    } else {
        cout << "Invalid customer ID. It should be a 3-digit number." << endl;
    }
}

int Customer::getID() const {
    return customerId; // Return the customer's ID
}

void Customer::setID(int customerId) {
    this->customerId = customerId; // Set the customer's ID
}

string Customer::getBank() const {
    return bank; // Return the bank associated with the customer
}

void Customer::setBank(string bank) {
    this->bank = bank; // Set the bank associated with the customer
}

float Customer::getPay() const {
    return pay; // Return the customer's weekly pay
}

void Customer::setPay(float pay) {
    this->pay = pay; // Set the customer's weekly pay
}

Account* Customer::getAccount() const {
    return account; // Return the associated account of the customer
}

void Customer::showInfo() const {
    cout << "Customer info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
    cout << "customer ID: " << customerId << endl;
    cout << "bank: " << bank << endl;
}
