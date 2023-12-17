
// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Crush.h"
#include "Admirer.h"
#include "Personality.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Enemy : public Character {
  private:
    // Attributes specific to Enemy
    // attack events (string array )
    vector <string> attackEvents = {"情敵到處說你的壞話", "情敵搶先約暗戀對象去看流星雨"};

  public:
    Enemy(const std::string& name, Personality attributes);
    ~Enemy();
    Personality getAttributes() const {return attributes;}
    void attack(Crush& crush, Admirer& admirer);
  
  friend class Admirer;
  friend class Crush;
};

#endif // ENEMY_H
