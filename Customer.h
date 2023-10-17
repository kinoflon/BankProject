#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string>
using namespace std;

class Account;

class Customer : public Person {
protected:
    int customerId;
    string bank;
    Account* account;
    float pay;

public:
    Customer();
    Customer(string name, float wage);
    Customer(int customerId);

    void setCustomerID(int id);
    void setAccount(Account* account);
    Account* getAccount() const;
    void showInfo() const;

    int getID() const;
    void setID(int customerId);
    string getBank() const;
    float getPay() const;

    void setBank(string bank);
    void setPay(float pay);
};

#endif
