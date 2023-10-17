#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string>
using namespace std;

class Account;  // Forward declaration of the Account class

class Customer : public Person {
protected:
    int customerId;  // Unique identifier for the customer
    string bank;     // Name of the bank where the customer holds an account
    Account* account;  // Pointer to the associated Account object
    float pay;  // Weekly pay of the customer

public:
    // Constructors
    Customer();  // Default constructor
    Customer(string name, float wage);  // Parameterized constructor with name and wage
    Customer(int customerId);  // Constructor with a customer ID

    // Setter for the customer ID
    void setCustomerID(int id);

    // Getter and setter for the customer's ID
    int getID() const;
    void setID(int customerId);

    // Getter and setter for the bank name
    string getBank() const;
    void setBank(string bank);

    // Getter and setter for the weekly pay
    float getPay() const;
    void setPay(float pay);

    // Setter for the associated Account object
    void setAccount(Account* account);

    // Getter for the associated Account object
    Account* getAccount() const;

    // Display customer information
    void showInfo() const;
};

#endif
