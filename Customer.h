#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string>
using namespace std;

class Customer : public Person {

    protected:
        int customerId;
        string bank;
        float loan;
        float creditScore;
        Customer* account;

    public:
        Customer();
        Customer(string name);
        Customer(int customerId);
        
        void setAccount(Customer* account);

        void showInfo() const;

        int getID() const;
        void setID(int customerId);
        string getBank() const;
        void setBank(string bank);
        float getCreditScore() const;
        float getLoan() const;

};

#endif