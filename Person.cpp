#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    name = "";
    wage = 0.0;
}

Person::Person(string name, float wage) {
    this->name = name;
    this->wage = wage;
}

void Person::showInfo() const {
    cout << "Person info:" << endl;
    cout << "name: " << name << endl;
    cout << "wage: " << wage << endl;
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
