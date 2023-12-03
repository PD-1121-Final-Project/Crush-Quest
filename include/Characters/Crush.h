
// Crush.h
#ifndef CRUSH_H
#define CRUSH_H

#include "Character.h"
#include "Admirer.h"
#include <iostream>
#include <string>
using namespace std;

class Crush : public Character {
  private:
    // Attributes specific to Crush
    double love = 0;

  public:
    // // Constructor and destructor
    Crush(const std::string& name, int age);
    ~Crush();

    // // Overridden method from Character
    void print();
    void calcLove(Admirer admirer);
};

#endif // CRUSH_H
