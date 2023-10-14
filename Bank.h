#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class Bank {

    protected:
        string name;
        float capacity;
        int numAccounts;

    public:
        Bank();
        Bank(string name);
        string getBank() const;

        // virtual void generatePay() = 0;
        virtual void generatePay() const { return; }
        virtual float generateLoan();
        virtual void updateLoan();
};

#endif