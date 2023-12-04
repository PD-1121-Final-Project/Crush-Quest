
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
    // 道具的array

  public:
    Admirer(const std::string& name, int age, personality attributes);
    ~Admirer();
    void print();
};

#endif // ADMIRER_H
