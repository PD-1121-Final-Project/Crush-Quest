
// Admirer.h
#ifndef ADMIRER_H
#define ADMIRER_H

#include "Character.h"
#include "Crush.h"
#include "Personality.h"
#include <iostream>
#include <string>
using namespace std;

class Admirer : public Character {
  private:
    // Attributes specific to Admirer
    // 道具的array

  public:
    Admirer(const std::string& name, int age, Personality attributes);
    ~Admirer();
    void print();
    void update(Personality newAttributes);
    Personality getAttributes() const {return attributes;}
  
  friend class Crush;
};

#endif // ADMIRER_H
