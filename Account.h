#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Customer; // Forward declaration of the Customer class

class Account {
protected:
    int accountNumber;  // Unique account number
    int bsb;  // Bank-State-Branch code
    float balance;  // Current account balance
    float pay;  // Weekly pay

public:
    Account(); // Default constructor
    Account(float balance, float wage); // Parameterized constructor
    int getAccountNum(); // Getter for the account number
    void setAccountNum(int accountNumber); // Setter for the account number
    int getBSB(); // Getter for the BSB code
    void setBSB(int bsb); // Setter for the BSB code
    float getBalance(); // Getter for the account balance
    void setBalance(float balance); // Setter for the account balance
    float getPay(); // Getter for the weekly pay
    void setPay(float pay); // Setter for the weekly pay
    void deposit(float amount); // Deposit money into the account
    bool withdraw(float amount); // Withdraw money from the account
    void showInfo(); // Display account information
};

#endif
