
// Crush.h
#ifndef CRUSH_H
#define CRUSH_H

#include "Admirer.h"
#include "Character.h"
#include "Personality.h"
#include <iostream>
#include <string>
using namespace std;

class Crush : public Character {
  private:
    // Attributes specific to Crush
    double love = 0;

  public:
    // // Constructor and destructor
    Crush(const std::string& name, int age, personality attributes);
    ~Crush();

    // // Overridden method from Character
    void print();
    void calcLove(Admirer admirer);
};

#endif // CRUSH_H
