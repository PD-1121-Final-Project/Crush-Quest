
// Crush.h
#ifndef CRUSH_H
#define CRUSH_H

#include "Character.h"
#include "Personality.h"
#include <iostream>
#include <string>
using namespace std;

class Crush : public Character {
  private:
    // Attributes specific to Crush
    double impression = 0;

  public:
    // // Constructor and destructor
    Crush(const std::string& name, Personality attributes);
    ~Crush();

    // // Overridden method from Character
    void print();
    void update(Personality newAttributes, double impressionIncre = 0);
    void corUpdate(Personality admirerAtt, double actionCoef);
};

#endif // CRUSH_H
