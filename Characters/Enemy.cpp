#include "../include/Characters/Enemy.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const std::string& name, Personality attributes)
    : Character(name, attributes) {}

Enemy::~Enemy() {}

void Enemy::attack(Crush& crush, Admirer& admirer) {
    cout << "✸攻擊事件發生！✸";
}