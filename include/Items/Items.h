#include <iostream>
#include <string>
#include "../Characters/Personality.h"
#include "../Characters/Character.h"

using namespace std;

class Items
{
private:
    string itemName;
    int itemNum; //玩家擁有該item的數量
    personality increaseRate; //使用此item會各自增加的屬性值量
    int impressionIncre;
public:
    Items(string name, personality IR, int impreIncre):itemName(name), increaseRate(IR), itemNum(0), impressionIncre(impreIncre){};
    ~Items();
    void print();
    int getItemNum() const;
    void gainItem();
    void usingItemTo(Character&);
};
personality init = {0,0,0,0,0,0};

Items perfume("perfume", init, 0);