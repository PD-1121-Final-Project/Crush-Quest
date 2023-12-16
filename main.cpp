// #include "include/Characters/Admirer.h"
#include "include/Characters/Crush.h"
#include "include/Characters/Personality.h"
#include "include/Scene_Action/Scene.h"
#include "include/Game/Game.h"
#include "include/jsonToString.h"
#include <fstream>
#include <iostream>
#include <json/json.h>
using namespace std;

int main() {


    std::ifstream scene_json("./Scene_and_Actions/scene.json",
                             std::ifstream::binary);
    if (!scene_json.is_open()) {
        cerr << "Failed to open 'scene.json' file." << endl;
        return 1;
    }
    Json::Value sceneObj;
    if (scene_json.fail()) {
        cerr << "Failed to parse JSON." << endl;
        return 1;
    }

    scene_json >> sceneObj;

    // if (!sceneObj[0]["name"].isNull()) {
    //     string sceneName = JsonToString(sceneObj[0]);
    //     cout << sceneName << endl;
    // }

    // 建立一個人物
    // appearance, iq, luck, physical, talent, wealth
    struct Personality playerAttr = {10, 20, 30, 40, 50, 60};
    Admirer player("John", playerAttr);
    player.print();

    // 建立一個暗戀對象
    // appearance, iq, luck, physical, talent, wealth
    struct Personality crushAttr = {30, 400, 30, 20, 20, 30};
    crushAttr.iq = 300;
    Crush crush1("JJJ", crushAttr);
    crush1.print();

    // 建立今天的場景
    Scene scene1("Library", sceneObj[0]); // 活大、圖書館、教室、宿舍

    // 印出場景敘述
    scene1.happen();

    // 印出場景的選項，並且讓玩家選擇，並且回傳結果
    // Personality newPersonality = scene1.act(player);
    Personality updateScore;
    double actionCoef = 0;
    scene1.act(player, updateScore, actionCoef);

    player.update(updateScore); // 依照結果升級
    crush1.update(player.getAttributes(), actionCoef);

    // 印出結果
    player.print();

    Game Game;
    Game.init();
    crush1.print();

    // 關閉檔案
    scene_json.close();

    return 0;
}