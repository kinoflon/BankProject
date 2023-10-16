#include <iostream>
#include <string>
#include "Person.h"
#include "Bank.h"
#include "CommBank.h"
#include "ANZ.h"
#include "NAB.h"
#include "Westpac.h"
#include "Customer.h"
#include "Account.h"

using namespace std;

int main() {
    // Create a person and ask for their name
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    Account* person;
    person->setName(name);

    cout << "Welcome, " << person->getName() << "!" << endl;

    // Let the person pick a bank
    cout << "Choose a bank: " << endl;
    cout << "1. CommBank" << endl;
    cout << "2. ANZ" << endl;
    cout << "3. NAB" << endl;
    cout << "4. Westpac" << endl;

    int bankChoice;
    cout << "Enter the number of the bank you want to choose: ";
    cin >> bankChoice;

    Bank* selectedBank;

    if (bankChoice == 1) {
        selectedBank = new CommBank();
    } else if (bankChoice == 2) {
        selectedBank = new ANZ();
    } else if (bankChoice == 3) {
        selectedBank = new NAB();
    } else if (bankChoice == 4) {
        selectedBank = new Westpac();
    } else {
        cout << "Invalid bank choice. Exiting." << endl;
        return 1;
    }

    // Create a customer
    string test = person->getName();


    person->setName(test);
    person->setBank(selectedBank->getBank());

    cout << "You are now a customer of " << person->getBank() << endl;

    //From Callum.
    //Give options on what they should do
    //for example, open new account, accumulate loan, generate pay (ask for wage). 
    // similar to the commented code below
    // also have a choice for them to.
    // all the only thing different when accumulating the loan is the interest rate so do a switch statement that uses the bankchoice
    // to differentiate the bloody things



    // Take out a loan
    float loanAmount;
    cout << "Enter the loan amount you want to take out: ";
    cin >> loanAmount;

    cout << "You have taken a loan of $" << person->getLoan(loanAmount) << endl;

    // Transfer money from pay into the account
    float weeklyPay;
    cout << "Enter your weekly pay: $";
    cin >> weeklyPay;

    person->setBalance(weeklyPay);

    cout << "Your account balance is $" << person->getBalance() << endl;

    // Display customer and account information
    person->Customer::showInfo();
    person->Account::showInfo();

    // Clean up allocated memory
    delete selectedBank;

    return 0;
}




// using namespace std;

// int main() {
//     vector<Customer> customers;

//     cout << "Welcome to the Banking System" << endl;
//     cout << "Please choose a bank to become a customer of:" << endl;
//     cout << "1. NAB" << endl;
//     cout << "2. ANZ" << endl;
//     cout << "3. CommBank" << endl;
//     cout << "4. Westpac" << endl;
//     cout << "Enter your choice (1/2/3/4): ";

//     int bankChoice;
//     cin >> bankChoice;

//     string bankName;

//     switch (bankChoice) {
//         case 1:
//             bankName = "NAB";
//             break;
//         case 2:
//             bankName = "ANZ";
//             break;
//         case 3:
//             bankName = "CommBank";
//             break;
//         case 4:
//             bankName = "Westpac";
//             break;
//         default:
//             cout << "Invalid bank choice. Exiting the program." << endl;
//             return 1;
//     }

//     while (true) {
//         cout << "Banking System for " << bankName << endl;
//         cout << "1. Create Customer Account" << endl;
//         cout << "2. Perform Transaction" << endl;
//         cout << "3. Display Customer Information" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: ";

//         int choice;
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 cout << "Enter customer name: ";
//                 string name;
//                 cin.ignore();
//                 getline(cin, name);

//                 bool customerExists = false;
//                 for (const auto& customer : customers) {
//                     if (customer.getName() == name && customer.getBank() == bankName) {
//                         customerExists = true;
//                         break;
//                     }
//                 }

//                 if (customerExists) {
//                     cout << "A customer with the same name already exists in " << bankName << "." << endl;
//                 } else {
//                     Customer customer(name);
//                     customer.setBank(bankName);
//                     customers.push_back(customer);
//                     cout << "Customer account created successfully." << endl;
//                 }
//                 break;
//             }
//             case 2: {
//                 cout << "Enter customer ID: ";
//                 int customerId;
//                 cin >> customerId;

//                 Customer* customer = nullptr;
//                 for (auto& c : customers) {
//                     if (c.getID() == customerId) {
//                         customer = &c;
//                         break;
//                     }
//                 }

//                 if (customer == nullptr) {
//                     cout << "Customer not found." << endl;
//                     break;
//                 }

//                 cout << "1. Deposit" << endl;
//                 cout << "2. Withdraw" << endl;
//                 cout << "Enter transaction type (1/2): ";
//                 int transactionType;
//                 cin >> transactionType;

//                 if (transactionType == 1) {
//                     cout << "Enter amount to deposit: ";
//                     float amount;
//                     cin >> amount;
//                     //customer->deposit(amount);
//                     //Honestly not sure how to make this work
//                     cout << "Deposit successful." << endl;
//                 } else if (transactionType == 2) {
//                     cout << "Enter amount to withdraw: ";
//                     float amount;
//                     cin >> amount;
//                     //if (customer->withdraw(amount)) {
//                     //same here
//                     //    cout << "Withdrawal successful." << endl;
//                     //} else {
//                     //    cout << "Insufficient balance." << endl;
//                     //}
//                 } else {
//                     cout << "Invalid transaction type." << endl;
//                 }

//                 break;
//             }
//             case 3: {
//                 cout << "Enter customer ID: ";
//                 int customerId;
//                 cin >> customerId;

//                 for (const auto& customer : customers) {
//                     if (customer.getID() == customerId) {
//                         customer.showInfo();
//                         break;
//                     }
//                 }

//                 break;
//             }
//             case 4:
//                 cout << "Exiting the program." << endl;
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please enter a valid option." << endl;
//                 break;
//         }
//     }

//     return 0;
// }
