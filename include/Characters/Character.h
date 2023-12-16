
// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Personality.h"
#include <iostream>
#include <string>
using namespace std;

class Character {
  protected:
    // Attributes common to all Characters
    string name;
    Personality attributes;

  public:
    // // Constructors and destructors if needed
    Character(const string& name, Personality attributes);
    ~Character();
    void print();
    Personality getPersonality() {return attributes;};

    // // Virtual methods that can be overridden by child classes
    // virtual void displayAffection() = 0;
};

#endif // CHARACTER_H
