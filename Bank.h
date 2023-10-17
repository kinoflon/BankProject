#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class Customer; // Forward declaration

class Bank {
protected:
    string name;
    float capacity;
    int numAccounts;

public:
    // Default constructor for Bank
    Bank();

    // Constructor for Bank with a name parameter
    Bank(string name);

    // Method to get the name of the bank
    string getBank() const;

    // Method to generate and display a customer's pay (virtual for potential overriding)
    virtual void generatePay(Customer* customer) const;
};

#endif
