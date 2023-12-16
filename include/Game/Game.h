
// GAME.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stdexcept> 
#include <chrono>  // 新增的頭文件
#include <thread>  // 新增的頭文件
#include "../Characters/Personality.h"
#include "../Characters/Character.h"
#include "../Characters/Admirer.h"
#include <vector>
#include "../Items/Items.h"
using namespace std;

class Game 
{
private :
    Admirer* player;
    vector <Items> items ;
public :
    Game (): player(nullptr) {};
    ~Game(){delete player;};
    void init();
};

#endif // GAME_H
