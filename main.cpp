// #include "include/Characters/Admirer.h"
#include "include/Characters/Crush.h"
#include "include/Characters/Personality.h"
#include "include/Game/Game.h"
#include "include/Scene_Action/Scene.h"
#include "include/jsonToString.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
using namespace std;

int main() {
    Game game;
    game.init();
    game.dayContinue();
    game.gameEnd();
    game.printItems();
    return 0;
}