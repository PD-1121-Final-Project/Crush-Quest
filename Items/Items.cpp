#include <iostream>
#include "../include/Characters/Personality.h"
#include "../include/Items/Items.h"
#include "../include/Characters/Character.h"
using namespace std;


Items::~Items()
{
    cout << "Items' destructor implementation";
}
void Items::print()
{
    cout << "Player have " << itemNum << " " << itemName << "\nThis item will gain you\n" << this -> increaseRate.iq << " Intellgence\n" << this -> increaseRate.physical <<" Strength\n" << this -> increaseRate.talent << " Talent\n" << this -> increaseRate.wealth << " Wealth\n" << this -> increaseRate.luck << " Luck\n" << this -> increaseRate.appearance << " Appearance\nUsing this item on other characters will increase " << impressionIncre << " impression of you" ;
}
void Items::gainItem()
{
    itemNum++;
}
void Items::usingItemTo(Character&)
{
    itemNum--;
}