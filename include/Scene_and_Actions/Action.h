#ifndef ACTION_H
#define ACTION_H

#include <string>
using namespace std;

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

#endif
