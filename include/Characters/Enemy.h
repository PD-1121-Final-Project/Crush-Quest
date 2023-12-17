
// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Admirer.h"
#include "Character.h"
#include "Crush.h"
#include "Personality.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Enemy : public Character {
  private:
    // Attributes specific to Enemy
    // attack events (string array )
    vector<string> attackEvents = {"情敵到處說你的壞話",
                                   "情敵搶先約暗戀對象去看流星雨"};

  public:
    Enemy(const std::string& name, Personality attributes);
    ~Enemy();
    void attack(Crush& crush, Admirer& admirer);

    friend class Admirer;
    friend class Crush;
};

#endif // ENEMY_H
