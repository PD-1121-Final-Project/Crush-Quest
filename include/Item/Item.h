#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "../Characters/Personality.h"
#include "../Characters/Character.h"

using namespace std;

class Item
{
private:
    string itemName;
    int itemNum; //玩家擁有該item的數量
    Personality increaseRate; //使用此item會各自增加的屬性值量
    string printContent;
    string getContent;
    double impressionIncre;
public:
    Item(string name, Personality IR, double impreIncre, string printContent, string getContent):itemName(name), increaseRate(IR), itemNum(0), impressionIncre(impreIncre), printContent(printContent), getContent(getContent){};
    ~Item();
    void print();
    void gainThisItem();
    void usingItemTo(Character* object);
    void printName();
    int getItemNum(){return itemNum;}
};



#endif 