#include "../include/Characters/Enemy.h"
#include "../include/Scene_Action/Function.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const std::string& name, Personality attributes)
    : Character(name, attributes) {impression = 100;}

Enemy::~Enemy() {}

void Enemy::attack(Crush& crush, Admirer& admirer) {
    slowPrint("ϟ\\ϟ\\ϟ 情敵警報！ϟ/ϟ/ϟ");

    int randomIdx = rand() % 2;
    slowPrint(attackEvents[randomIdx]);
    slowPrint("請選擇你想要使用的道具：");

    // delete chosen attack event
    attackEvents.erase(attackEvents.begin() + randomIdx);
}
void Enemy::printImpre()
{
    cout << impression;
}
void Enemy::update(Personality a, double impressionIncre)
{
    impression += impressionIncre;
}
double Enemy::getImpression()
{
    return impression;
}