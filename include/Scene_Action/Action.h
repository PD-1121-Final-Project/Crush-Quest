#ifndef ACTION_H
#define ACTION_H

#include <string>
using namespace std;

class Action {
  protected:
    string description;
    double actionCoef;
    string response;

  public:
    // Constructor
    Action(string name, double actionCoef, string response);
    ~Action();

    // Operator overloading
    void operator=(const Action& a);

    // Functions
    void printDescription() const;
    double getCoef() const { return actionCoef; }
};

#endif
