#ifndef ACTION_H
#define ACTION_H

#include "../Characters/Personality.h"
#include <string>
using namespace std;

class Action {
  protected:
    string description;
    double actionCoef;
    Personality updateScore;
    string response;

  public:
    // Constructor
    Action(string name, double actionCoef, Personality updateScore, string response);
    ~Action();

    // Operator overloading
    void operator=(const Action& a);

    // Functions
    void printDescription() const;
    double getCoef() const { return actionCoef; }
    Personality getUpdateScore() const { return updateScore; }
    string getResponse() const { return response; }
};

#endif
