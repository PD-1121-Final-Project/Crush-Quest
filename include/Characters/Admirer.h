
// Admirer.h
#ifndef ADMIRER_H
#define ADMIRER_H

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class Admirer : public Character {
  private:
    // Attributes specific to Admirer
    // ...

  public:
    // // Constructor and destructor
    Admirer(const std::string& name, int age);
    ~Admirer();

    // // Overridden method from Character
    // void displayAffection() override;
    void print();
};

#endif // ADMIRER_H
