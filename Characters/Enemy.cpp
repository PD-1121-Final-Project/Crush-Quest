#include "../include/Characters/Enemy.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Event/ItemEvent.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const std::string& name, Personality attributes)
    : Character(name, attributes) {}

Enemy::~Enemy() {}

void Enemy::attack(Crush& crush, Admirer& admirer, Item** items, int itemCnt) {
    // initialize item event
    int randomIdx = rand() % 2;
    ItemEvent* itemEvent = new ItemEvent(attackEvents[randomIdx], items, itemCnt);

    slowPrint("ϟ\\ϟ\\ϟ 情敵警報！ϟ/ϟ/ϟ");

    
    slowPrint(attackEvents[randomIdx]);
    slowPrint("請選擇你想要使用的道具：");

    // delete chosen attack event
    attackEvents.erase(attackEvents.begin() + randomIdx);
}