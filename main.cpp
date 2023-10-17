#include <iostream>      // Include the necessary header for input/output
#include <string>
#include "Person.h"     // Include your custom classes' headers
#include "Bank.h"
#include "CommBank.h"
#include "ANZ.h"
#include "NAB.h"
#include "Westpac.h"
#include "Customer.h"
#include "Account.h"
#include <vector>

using namespace std;    // Import the standard library namespace

int main() {             // Main function where the program execution starts
    vector<Customer> customers;  // Create a vector to store customer objects

    // Print a welcome message to the console
    cout << "Welcome to the Banking System" << endl;
    cout << "Please choose a bank to become a customer of:" << endl;
    cout << "1. NAB" << endl;
    cout << "2. ANZ" << endl;
    cout << "3. CommBank" << endl;
    cout << "4. Westpac" << endl;
    cout << "Enter your choice (1/2/3/4): ";

    int bankChoice;
    cin >> bankChoice;   // Read the user's choice of bank

    string bankName;     // Declare a variable to store the selected bank's name

    // Use a switch statement to determine the bank based on the user's choice
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
            return 1;   // Exit the program with an error code
    }

    while (true) {  // Start an infinite loop for the banking system
        // Display a menu for the selected bank
        cout << "Banking System for " << bankName << endl;
        cout << "1. Create Customer Account" << endl;
        cout << "2. Perform Transaction" << endl;
        cout << "3. Display Customer Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;    // Variable to store the user's choice
        cin >> choice; // Read the user's choice

        switch (choice) {  // Use a switch statement to handle different options
            case 1: {
                cout << "Enter customer name: ";
                string name;
                cin.ignore();    // Ignore the newline character in the input buffer
                getline(cin, name);  // Read the customer's name

                // Ask the user for a 3-digit customer ID
                int customerID;
                cout << "Enter a 3-digit customer ID: ";
                cin >> customerID;

                // Ask the user for their wage (salary p.a.)
                float wage;
                cout << "Enter customer's wage: ";
                cin >> wage;

                bool customerExists = false;  // Flag to check if a customer already exists
                for (auto& customer : customers) { // Iterate through the customers vector
                    if (customer.getName() == name && customer.getBank() == bankName) {
                        customerExists = true;
                        break;
                    }
                }

                if (customerExists) {
                    cout << "A customer with the same name already exists in " << bankName << "." << endl;
                } else {
                    Customer customer(name, wage);  // Create a new Customer object
                    customer.setCustomerID(customerID);  // Set customer ID
                    customer.setBank(bankName);  // Set the bank's name

                    // Create a dynamic Account object and pass its pointer to setAccount
                    Account* account = new Account(0, wage);
                    customer.setAccount(account);

                    // Calculate and set the pay
                    customer.setPay(wage / 52);

                    customers.push_back(customer);  // Add the customer to the vector
                    cout << "Customer account created successfully." << endl;
                }
                break;  // Exit the case
            }

            case 2: {
                cout << "Enter customer ID: "; //Prompt user for id to find customer info
                int customerId;
                cin >> customerId;

                Customer* customer = nullptr;
                for (auto& c : customers) {  // Iterate through the customers vector
                    if (c.getID() == customerId) {
                        customer = &c;
                        break;
                    }
                }

                if (customer == nullptr) {
                    cout << "Customer not found." << endl; //error message if id does not match a customer
                    break;
                }

                // Display transaction options
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "Enter transaction type (1/2): ";
                int transactionType;
                cin >> transactionType;

                if (transactionType == 1) {
                    cout << "Enter amount to deposit: "; // ask user for amount of money to deposit
                    float amount;
                    cin >> amount;
                    customer->getAccount()->deposit(amount);
                } else if (transactionType == 2) {
                    cout << "Enter amount to withdraw: "; // ask user for amount of money to withdraw
                    float amount;
                    cin >> amount;
                    customer->getAccount()->withdraw(amount);
                } else {
                    cout << "Invalid transaction type." << endl; // error message if 1 or 2 are no input
                }
                break;
            }

            case 3: {
                cout << "Enter customer ID: "; // identify customer
                int customerId;
                cin >> customerId;

                for (const auto& customer : customers) {  // Iterate through the customers vector
                    if (customer.getID() == customerId) {
                        customer.showInfo();  // Display customer information

                        // Check if the customer has an associated account
                        Account* account = customer.getAccount();
                        if (account != nullptr) {
                            account->showInfo();  // Display account information
                        } else {
                            cout << "This customer does not have an associated account." << endl;
                        }
                        break;
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting the program." << endl;
                return 0;  // Exit the program with a success code
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
    return 0;  // Return a success code to indicate successful program execution
}