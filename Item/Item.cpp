#include <iostream>
#include "../include/Characters/Personality.h"
#include "../include/Item/Item.h"
#include "../include/Characters/Character.h"
using namespace std;


Item::~Item()
{
    cout << "Items' destructor implementation";
}
void Item::print()
{
    cout << "Player have " << itemNum << " " << itemName << "\nThis item will gain you\n" << this -> increaseRate.iq << " Intellgence\n" << this -> increaseRate.physical <<" Strength\n" << this -> increaseRate.talent << " Talent\n" << this -> increaseRate.wealth << " Wealth\n" << this -> increaseRate.luck << " Luck\n" << this -> increaseRate.appearance << " Appearance\nUsing this item on other characters will increase " << impressionIncre << " impression of you" ;
}
void Item::gainThisItem()
{
    itemNum++;
}
void Item::usingItemTo(Character&)
{
    itemNum--;
}