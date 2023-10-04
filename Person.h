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
        Person(string name);

        virtual void showInfo();

        string getName();
        float getWage();
        void setName(string name);
        void setWage(float wage);

};



#endif