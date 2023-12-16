#include "../include/Scene_Action/Action.h"
#include <iostream>
#include <string>

using namespace std;

/*
class Action
{
protected:
        string name;
        int code;

public:
    // Constructor
    Action(int n, string s);
    ~Action();

    // Operator overloading
    void operator=(const Action& a);

    // Functions
    void printName() const;
};
*/

Action::Action(string name) { this->name = name; }
Action::Action(string name, double actionCoef) {
    this->name = name;
    this->code = actionCoef;
}

void Action::printName() const { cout << this->name; }

Action::~Action() {}

void Action::operator=(const Action& a) {
    this->name = a.name;
    this->code = a.code;
}
