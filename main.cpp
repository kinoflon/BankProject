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
#include <vector>

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
            NAB* selectedBank = new NAB();

            break;
        case 2:
            bankName = "ANZ";
            ANZ* selectedBank = new ANZ();
            break;
        case 3:
            bankName = "CommBank";
            CommBank* selectedBank = new CommBank();
            break;
        case 4:
            bankName = "Westpac";
            Westpac* selectedBank = new Westpac();
            break;
        default:
            cout << "Invalid bank choice. Exiting the program." << endl;
            return 1;
    }

    selectedBank->
    

    while (true) {
        cout << "Banking System for " << bankName << endl;
        cout << "1. Create Customer Account" << endl;
        cout << "2. Perform Transaction" << endl;
        cout << "3. Display Customer Information" << endl;
        cout << "4. Loan Banking" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter customer name: ";
                string name;
                cin.ignore();
                getline(cin, name);

                //get wage

                // Ask the user for a 3-digit customer ID
                int customerID;
                cout << "Enter a 3-digit customer ID: ";
                cin >> customerID;

                bool customerExists = false;
                for (auto& customer : customers) {
                    if (customer.getName() == name && customer.getBank() == bankName) {
                        customerExists = true;
                        break;
                    }
                }

                if (customerExists) {
                    cout << "A customer with the same name already exists in " << bankName << "." << endl;
                } else {
                    Customer customer(name);
                    customer.setCustomerID(customerID);
                    customer.setBank(bankName);
                    
                    // Create a dynamic Account object and pass its pointer to setAccount
                    Account* account = new Account();
                    customer.setAccount(account);
                    
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
                    customer->getAccount()->deposit(amount);
                } else if (transactionType == 2) {
                    cout << "Enter amount to withdraw: ";
                    float amount;
                    cin >> amount;
                    customer->getAccount()->withdraw(amount);
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
                        
                        // Check if the customer has an associated account
                        Account* account = customer.getAccount();
                        if (account != nullptr) {
                            account->showInfo();
                        } else {
                            cout << "This customer does not have an associated account." << endl;
                        }
                        
                        break;
                    }
                }

                break;
            }
            case 4: {
                cout << "1. Take Out A Loan" << endl;
                cout << "2. Pay Off A Loan" << endl;
                cout << "Enter operation type (1/2): ";
                int operationType;
                cin >> operationType;

                if (operationType == 1) {
                    cout << "Enter Loan Amount: ";
                    float loan;
                    cin >> loan;
                    customer->getAccount()->deposit(amount);
                } else if (operationType == 2) {
                    cout << "Enter Amount To Pay Off: ";
                    float loanMinus;
                    cin >> loanMinus;
                    customer->getAccount()->withdraw(amount);
                } else {
                    cout << "Invalid operation type." << endl;
                }

                break;
            }
                
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}