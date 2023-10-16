#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string& name, const std::string& bank);
    int getID() const;
    void deposit(float amount);
    void withdraw(float amount);
    void displayInfo() const;

private:
    int customerID;
    std::string name;
    std::string bank;
    float balance;
};

#endif



// #ifndef CUSTOMER_H
// #define CUSTOMER_H

// #include "Person.h"
// #include <string>
// using namespace std;

// class Customer : public Person {

//     protected:
//         int customerId;
//         string bank;
//         Customer* account;
//     private:

//     public:
//         mutable float loan = 0;
//         Customer();
//         Customer(string name);
//         Customer(int customerId);
        
//         void setAccount(Customer* account);

//         void showInfo() const;

//         int getID() const;
//         void setID(int customerId);
//         string getBank() const;
//         void setBank(string bank);
//         float getCreditScore() const;
//         float getLoan(float loanAmount) const;

// };

// #endif