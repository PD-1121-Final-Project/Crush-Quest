#include <iostream>
#include <string>
#include "../include/Scene_Action/Action.h"

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


Action::Action(int n, string s)
{
	this->code = n;
	this->name = s;
}

void Action::printName() const
{
	cout << this->name;
}


Action::~Action()
{
}


void Action::operator=(const Action& a)
{
	this->name = a.name;
	this->code = a.code;
}



