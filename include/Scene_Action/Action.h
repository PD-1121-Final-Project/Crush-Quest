#ifndef ACTION_H
#define ACTION_H

#include <string>
using namespace std;

class Action {
  protected:
    string name;
    int code;
    double coef;

  public:
    // Constructor
    Action(string name);
    Action(string name, double actionCoef);
    ~Action();

    // Operator overloading
    void operator=(const Action& a);

    // Functions
    void printName() const;
    double getCoef() const { return coef; }
};

#endif
