#ifndef ITEM_H
#define ITEM_H

#include "../Characters/Character.h"
#include "../Characters/Personality.h"
#include <iostream>
#include <string>

using namespace std;

class Items {
  private:
    string itemName;
    int itemNum;              // 玩家擁有該item的數量
    Personality increaseRate; // 使用此item會各自增加的屬性值量
    int impressionIncre;

  public:
    Items(string name, Personality IR, int impreIncre)
        : itemName(name), increaseRate(IR), itemNum(0),
          impressionIncre(impreIncre){};
    ~Items();
    void print();
    int getItemNum() const;
    void gainItem();
    void usingItemTo(Character&);
};

#endif