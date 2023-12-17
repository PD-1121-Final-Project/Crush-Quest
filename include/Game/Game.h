
// GAME.h
#ifndef GAME_H
#define GAME_H
// #include "include/Characters/Admirer.h"
#include "../Characters/Admirer.h"
#include "../Characters/Character.h"
#include "../Characters/Crush.h"
#include "../Characters/Personality.h"
#include "../Item/Item.h"
#include "../Scene_Action/Function.h"
#include "../Scene_Action/Scene.h"
#include "../jsonToString.h"
#include <chrono> // 新增的頭文件
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <stdexcept>
#include <string>
#include <thread> // 新增的頭文件
#include <vector>
<<<<<<< HEAD
=======
#include "../Characters/Enemy.h"
#include "../Item/Item.h"
#include "../Scene_Action/Function.h"
#include "../Scene_Action/Scene.h"
>>>>>>> main using namespace std;

class Game {
  private:
    int day;
    int dayCnt;
    Admirer* player;
    Crush* crush1;
    Enemy* enemy;
    vector<Item*> items;
    vector<Scene> Scenes;

  public:
    Game();
    ~Game();
    void init();        // 遊戲開始
    void dayContinue(); // 每天循環
    void gameEnd();     // 遊戲結束

    void nextScene(); // 切換至下一個場景（一天結束）
    void printCrush();
    void gainItem();
    void printItems();

    friend class Event; // 取得遊戲中的道具
};

#endif // GAME_H
