#include "../include/Characters/Enemy.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Event/ItemEvent.h"
#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const std::string& name, Personality attributes)
    : Character(name, attributes) {impression = 100;}

Enemy::~Enemy() {}

void Enemy::attack(Crush& crush, Admirer& admirer, vector<Item*> items, int itemCnt) {
    // initialize item event
    int randomIdx = rand() % 2;
    ItemEvent itemEvent = ItemEvent(attackEvents[randomIdx], items, itemCnt);

    slowPrint("\n\nϟ\\ϟ\\ϟ 情敵警報！ϟ/ϟ/ϟ\n");
    slowPrint(attackEvents[randomIdx]);
    slowPrint("情敵的攻擊將會使你的印象值下降，但你可以使用道具來抵擋或是反擊！\n");
    if (itemCnt > 0) {
        int itemDecision_cin = 0, targetDecision_cin = 0;
        itemEvent.startEvent(itemDecision_cin, targetDecision_cin);

        switch (targetDecision_cin)
        {
        // (1) 情敵 (2) 暗戀對象 (3) 自己
        case 1:
            items[itemDecision_cin]->usingItemTo(this);
            break;
        
        case 2:
            items[itemDecision_cin]->usingItemTo(&crush);
            break;
        
        case 3:
            items[itemDecision_cin]->usingItemTo(&admirer);
            break;  
        }
    }

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