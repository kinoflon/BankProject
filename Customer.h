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

    public:
        Customer();
        Customer(int customerId);

        void showInfo();

        int getID();
        void setID(int customerId);
        string getBank();
        void setBank(string bank);
        float getCreditScore();
        float getLoan();

};

#endif