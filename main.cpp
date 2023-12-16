// #include "include/Characters/Admirer.h"
#include "include/Characters/Crush.h"
#include "include/Characters/Personality.h"
#include "include/Scene_Action/Scene.h"
#include "include/Game/Game.h"
#include <iostream>
using namespace std;

int main() {
/*

    // player->print();
    // delete player;
    // 建立一個人物
    // appearance, iq, luck, physical, talent, wealth
    struct Personality playerAttr = {10, 20, 30, 40, 50, 60};
    Admirer player("John", playerAttr);
    player.print();

    // 建立一個暗戀對象
    // appearance, iq, luck, physical, talent, wealth
    struct personality crushAttr = {30, 400, 30, 20, 20, 30};
    crushAttr.iq = 300;
    Crush crush1("JJJ", crushAttr);
    crush1.print();
    
    // 建立今天的場景
    Scene scene1("Library"); // 活大、圖書館、教室、宿舍

    // 印出場景敘述
    scene1.happen();

    // 印出場景的選項，並且讓玩家選擇，並且回傳結果
    personality newPersonality = scene1.act(player);

    player.update(updateScore); // 依照結果升級
    crush1.update(player.getAttributes(), actionCoef);

    // 印出結果
    player.print();
*/
    Game Game;
    Game.init();
    return 0;
}