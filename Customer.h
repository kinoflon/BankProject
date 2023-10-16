#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string>
using namespace std;

// Forward declaration of the Account class
class Account;

class Customer : public Person {
    protected:
        int customerId;
        string bank;
        float creditScore;
        Account* account; // Use the forward-declared Account*

    public:
        mutable float loan = 0;
        Customer();
        Customer(string name);
        Customer(int customerId);
        
        void setCustomerID(int id);
        void setAccount(Account* account);
        Account* getAccount() const;
        void showInfo() const;

        int getID() const;
        void setID(int customerId);
        string getBank() const;
        void setBank(string bank);
        float getCreditScore() const;
        float getLoan(float loanAmount) const;
};

#endif
