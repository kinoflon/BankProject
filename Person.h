#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;  // Name of the person
    float wage;   // Wage of the person

public:
    Person(); // Default constructor
    Person(string name, float wage); // Parameterized constructor

    void showInfo() const; // Display person's information

    string getName() const; // Getter for the person's name
    float getWage() const; // Getter for the person's wage
    void setName(string name); // Setter for the person's name
    void setWage(float wage); // Setter for the person's wage
};

#endif
