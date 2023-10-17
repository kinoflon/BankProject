#include "Person.h"
#include <iostream>
using namespace std;

// Default constructor for the Person class
Person::Person() {
    name = "";
    wage = 0.0;
}

// Parameterized constructor for the Person class
Person::Person(string name, float wage) {
    this->name = name;
    this->wage = wage;
}

// Display person's information
void Person::showInfo() const {
    cout << "Person info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: $" << wage << endl;
}

// Getter for the person's name
string Person::getName() const {
    return name;
}

// Getter for the person's wage
float Person::getWage() const {
    return wage;
}

// Setter for the person's name
void Person::setName(string name) {
    this->name = name;
}

// Setter for the person's wage
void Person::setWage(float wage) {
    this->wage = wage;
}
