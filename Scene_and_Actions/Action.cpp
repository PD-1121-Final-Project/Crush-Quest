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

Action::Action(string description, double actionCoef, Personality updateScore,
               string response) {
    this->description = description;
    this->actionCoef = actionCoef;
    this->updateScore = updateScore;
    this->response = response;
}

void Action::printDescription() const {
    string statement = this->description;
    // Remove the first and last character if they are quotes
    if (statement.front() == '"' && statement.back() == '"') {
        statement = statement.substr(1, statement.size() - 2);
    }
    cout << statement;
}

Action::~Action() {}

void Action::operator=(const Action& a) {
    this->description = a.description;
    this->actionCoef = a.actionCoef;
}