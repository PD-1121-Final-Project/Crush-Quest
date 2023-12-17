#include <iostream>
#include "../include/Characters/Personality.h"
#include "../include/Item/Item.h"
#include "../include/Characters/Character.h"
#include "../include/Scene_Action/Function.h"
using namespace std;


Item::~Item()
{
    
}
void Item::print()
{
    cout << "Player have " << itemNum << " " << itemName << "\nThis item will gain you\n" << this -> increaseRate.iq << " Intellgence\n" << this -> increaseRate.physical <<" Strength\n" << this -> increaseRate.talent << " Talent\n" << this -> increaseRate.wealth << " Wealth\n" << this -> increaseRate.luck << " Luck\n" << this -> increaseRate.appearance << " Appearance\nUsing this item on other characters will increase " << impressionIncre << " impression of you\n" ;
}
void Item::gainThisItem()
{
    itemNum++;
    cout << "\n";
    slowPrint (getContent);
    cout << "\n";
    printDashedLine();
}
void Item::usingItemTo(Character* object)
{
    itemNum--; 
    object -> update(this -> increaseRate, this ->impressionIncre);
    slowPrint(object->getName() + printContent);
}

void Item::printName()
{
    cout << itemName;
}