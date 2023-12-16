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

Action::Action(string description, double actionCoef, string response) {
    this->description = description;
    this->actionCoef = actionCoef;
    this->response = response;
}

void Action::printDescription() const { cout << this->description; }

Action::~Action() {}

void Action::operator=(const Action& a) {
    this->description = a.description;
    this->actionCoef = a.actionCoef;
}