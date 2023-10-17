#include <iostream>
#include <string>
#include <vector>

#include "ANZ.h"
#include "Account.h"
#include "Bank.h"
#include "CommBank.h"
#include "Customer.h"
#include "NAB.h"
#include "Person.h"
#include "Westpac.h"

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

  Bank* selectedBank;

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

  Account** account = new Account*();

  if (bankName == "NAB") {
    NAB* bank = new NAB;

    bank->addAccount(account);

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

          cout << "Enter customer wage: ";
          float wage;
          cin.ignore();
          getline(cin, wage);

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
            cout << "A customer with the same name already exists in "
                 << bankName << "." << endl;
          } else {
            Customer customer(name);
            customer.setCustomerID(customerID);
            customer.setWage(wage);
            customer.setBank(bankName);

            // Create a dynamic Account object and pass its pointer to
            // setAccount
            customer.setAccount(account[0]);

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
              account[0] = customer.getAccount();
              if (account[0] != nullptr) {
                account[0]->showInfo();
              } else {
                cout << "This customer does not have an associated account."
                     << endl;
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
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Loan Amount: ";
            float loan;
            cin >> loan;
            bank->generateLoan(loan, accountNumber);

          } else if (operationType == 2) {
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Amount To Pay Off: ";
            float loanMinus;
            cin >> loanMinus;
            float weekly = loanMinus/52;
            bank->updateLoan(loanMinus, accountNumber);
            bank->generateInterest(weekly);
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



  } else if (bankName == "ANZ") {
    ANZ* bank = new ANZ;

    bank->addAccount(account);

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

          cout << "Enter customer wage: ";
          float wage;
          cin.ignore();
          getline(cin, wage);

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
            cout << "A customer with the same name already exists in "
                 << bankName << "." << endl;
          } else {
            Customer customer(name);
            customer.setCustomerID(customerID);
            customer.setWage(wage);
            customer.setBank(bankName);

            // Create a dynamic Account object and pass its pointer to
            // setAccount
            customer.setAccount(account[0]);

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
              account[0] = customer.getAccount();
              if (account[0] != nullptr) {
                account[0]->showInfo();
              } else {
                cout << "This customer does not have an associated account."
                     << endl;
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
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Loan Amount: ";
            float loan;
            cin >> loan;
            bank->generateLoan(loan, accountNumber);

          } else if (operationType == 2) {
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Amount To Pay Off: ";
            float loanMinus;
            cin >> loanMinus;
            float weekly = loanMinus/52;
            bank->updateLoan(loanMinus, accountNumber);
            bank->generateInterest(weekly);
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


  } else if (bankName == "Westpac") {
    Westpac* bank = new Westpac;

    bank->addAccount(account);

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

          cout << "Enter customer wage: ";
          float wage;
          cin.ignore();
          getline(cin, wage);

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
            cout << "A customer with the same name already exists in "
                 << bankName << "." << endl;
          } else {
            Customer customer(name);
            customer.setCustomerID(customerID);
            customer.setWage(wage);
            customer.setBank(bankName);

            // Create a dynamic Account object and pass its pointer to
            // setAccount
            customer.setAccount(account[0]);

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
              account[0] = customer.getAccount();
              if (account[0] != nullptr) {
                account[0]->showInfo();
              } else {
                cout << "This customer does not have an associated account."
                     << endl;
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
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Loan Amount: ";
            float loan;
            cin >> loan;
            bank->generateLoan(loan, accountNumber);

          } else if (operationType == 2) {
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Amount To Pay Off: ";
            float loanMinus;
            cin >> loanMinus;
            float weekly = loanMinus/52;
            bank->updateLoan(loanMinus, accountNumber);
            bank->generateInterest(weekly);
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


  } else if (bankName == "CommBank") {
    CommBank* bank = new CommBank;

    bank->addAccount(account);

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

          cout << "Enter customer wage: ";
          float wage;
          cin.ignore();
          getline(cin, wage);

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
            cout << "A customer with the same name already exists in "
                 << bankName << "." << endl;
          } else {
            Customer customer(name);
            customer.setCustomerID(customerID);
            customer.setWage(wage);
            customer.setBank(bankName);

            // Create a dynamic Account object and pass its pointer to
            // setAccount
            customer.setAccount(account[0]);

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
              account[0] = customer.getAccount();
              if (account[0] != nullptr) {
                account[0]->showInfo();
              } else {
                cout << "This customer does not have an associated account."
                     << endl;
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
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Loan Amount: ";
            float loan;
            cin >> loan;
            bank->generateLoan(loan, accountNumber);

          } else if (operationType == 2) {
            int accountNumber;
            cout << "Account Number: " << endl;
            cin >> accountNumber;
            accountNumber--;

            cout << "Enter Amount To Pay Off: ";
            float loanMinus;
            cin >> loanMinus;
            float weekly = loanMinus/52;
            bank->updateLoan(loanMinus, accountNumber);
            bank->generateInterest(weekly);
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
  }

  return 0;
}