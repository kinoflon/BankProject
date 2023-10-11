#include "Person.h"

#include <iostream>
#include <string>


Person::Person() {
    name = "";
    wage = 0.0;
}

Person::Person(string name) {
    this->name = name;
    wage = 0;
}

string Person::getName() const {
    return name;
}

float Person::getWage() const {
    return wage;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setWage(float wage) {
    this->wage = wage;
}

void Person::showInfo() const {
    cout << "Person info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
}