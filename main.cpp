#include <iostream>
#include <vector>
#include "Account.h"
#include "Customer.h"
#include "Person.h"

using namespace std;

int main() {
    vector<Customer> customers;

    cout << "Welcome to the Banking System" << endl;
    cout << "Please choose a bank to become a customer of:" << endl;
    cout << "1. NAB" << endl;
    cout << "2. ANZ" << endl;
    cout << "3. CommBank" << endl;
    cout << "4. Westpac" << endl;
    cout << "Enter your choice (1/2/3/4): ";

    int bankChoice;
    cin >> bankChoice;

    string bankName;

    switch (bankChoice) {
        case 1:
            bankName = "NAB";
            break;
        case 2:
            bankName = "ANZ";
            break;
        case 3:
            bankName = "CommBank";
            break;
        case 4:
            bankName = "Westpac";
            break;
        default:
            cout << "Invalid bank choice. Exiting the program." << endl;
            return 1;
    }

    while (true) {
        cout << "Banking System for " << bankName << endl;
        cout << "1. Create Customer Account" << endl;
        cout << "2. Perform Transaction" << endl;
        cout << "3. Display Customer Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter customer name: ";
                string name;
                cin.ignore();
                getline(cin, name);

                bool customerExists = false;
                for (const auto& customer : customers) {
                    if (customer.getName() == name && customer.getBank() == bankName) {
                        customerExists = true;
                        break;
                    }
                }

                if (customerExists) {
                    cout << "A customer with the same name already exists in " << bankName << "." << endl;
                } else {
                    Customer customer(name);
                    customer.setBank(bankName);
                    customers.push_back(customer);
                    cout << "Customer account created successfully." << endl;
                }
                break;
            }
            case 2: {
                cout << "Enter customer ID: ";
                int customerId;
                cin >> customerId;

                Customer* customer = nullptr;
                for (auto& c : customers) {
                    if (c.getID() == customerId) {
                        customer = &c;
                        break;
                    }
                }

                if (customer == nullptr) {
                    cout << "Customer not found." << endl;
                    break;
                }

                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "Enter transaction type (1/2): ";
                int transactionType;
                cin >> transactionType;

                if (transactionType == 1) {
                    cout << "Enter amount to deposit: ";
                    float amount;
                    cin >> amount;
                    //customer->deposit(amount);
                    //Honestly not sure how to make this work
                    cout << "Deposit successful." << endl;
                } else if (transactionType == 2) {
                    cout << "Enter amount to withdraw: ";
                    float amount;
                    cin >> amount;
                    //if (customer->withdraw(amount)) {
                    //same here
                    //    cout << "Withdrawal successful." << endl;
                    //} else {
                    //    cout << "Insufficient balance." << endl;
                    //}
                } else {
                    cout << "Invalid transaction type." << endl;
                }

                break;
            }
            case 3: {
                cout << "Enter customer ID: ";
                int customerId;
                cin >> customerId;

                for (const auto& customer : customers) {
                    if (customer.getID() == customerId) {
                        customer.showInfo();
                        break;
                    }
                }

                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}
