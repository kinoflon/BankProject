#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    float wage;

public:
    Person();
    Person(string name, float wage);

    void showInfo() const;

    string getName() const;
    float getWage() const;
    void setName(string name);
    void setWage(float wage);
};

#endif
