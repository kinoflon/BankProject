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
    Bank();
    Bank(string name);
    string getBank() const;
    virtual void generatePay(Customer* customer) const;
};

#endif
