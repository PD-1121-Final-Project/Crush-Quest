
#include "../include/Game/Game.h"
#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"
#include "../include/Game/Game.h"
#include "../include/Item/Item.h"
#include "../include/Scene_Action/Function.h"
#include <chrono> // 新增的頭文件
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread> // 新增的頭文件
#include <vector>
using namespace std;
Game::Game() : player(nullptr), day(0) {
    // wealth iq; physical; talent appearance; luck
    Personality attributes = {2, 0, 0, 2, 4, 1};
    crush1 = new Crush("小美", attributes);
    Personality luckPotionChange = {0, 0, 0, 0, 0, 1};
    Personality steroidChange = {0, 0, 1, 0, 0, 0};
    Personality smartMedChange = {0, 1, 0, 0, 0, 0};
    Personality makeUpChange = {0, 0, 0, 0, 1, 0};
    Personality moneyChange = {1, 0, 0, 0, 0, 0};
    Personality laxativeChange = {-0.5, -0.5, -0.5, -0.5, -0.5, -0.5};
    Personality flowerChange = {0, 0, 0, 0, 0, 0};

    items.push_back(new Item("luckPotion", luckPotionChange, 2));
    items.push_back(new Item("Steroid", steroidChange, 1));
    items.push_back(new Item("smartMed", smartMedChange, 1));
    items.push_back(new Item("makeUp", makeUpChange, 2));
    items.push_back(new Item("money", moneyChange, 2));
    items.push_back(new Item("laxative", laxativeChange, -10));
    items.push_back(new Item("flower", flowerChange, +10));
}
Game::~Game() {
    delete player;
    player = nullptr;
    delete crush1;
    crush1 = nullptr;
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
        items[i] = nullptr;
    }
};
void Game::init() {
    int choice;
    Personality attribute;

    slowPrint("歡迎遊玩台大校園戀愛文字遊戲\n\n你是一位對校園充滿期待的大一新生"
              "，在這遊戲中，你能夠自由掌控你的未來走向，請選擇您的身家背景\n1."
              "富二代\n2.體育健將\n3.高材生\n4.帥哥\n5.藝術家\n6."
              "出身不太好，但做什麼事都特別順心的人\n7."
              "全知全能\n（請輸入數字不需加點）");

    do {
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else if (choice < 1 || choice > 7) {
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else {
            break;
        }
    } while (true);

    switch (choice) {
    case 1:
        attribute = {4, 0, 0, 0, 2, 2};
        break;
    case 2:
        attribute = {0, 0, 4, 2, 2, 1};
        break;
    case 3:
        attribute = {0, 4, 0, 2, 2, 1};
        break;
    case 4:
        attribute = {2, 0, 0, 2, 4, 1};
        break;
    case 5:
        attribute = {0, 2, 0, 4, 2, 1};
        break;
    case 6:
        attribute = {0, 0, 0, 0, 0, 5};
        break;
    case 7:
        attribute = {5, 5, 5, 5, 5, 0};
        break;
    default:
        attribute = {0, 0, 0, 0, 0, 0};
        break;
    }
    string name;
    slowPrint("請輸入角色名稱:");
    cin >> name;

    player = new Admirer(name, attribute);
    player->print();
}
void Game::dayContinue() {
    std::ifstream scene_json("./Scene_and_Actions/scene.json",
                             std::ifstream::binary);
    if (!scene_json.is_open()) {
        cerr << "Failed to open 'scene.json' file." << endl;
        exit(1);
    }
    Json::Value sceneObj;
    if (scene_json.fail()) {
        cerr << "Failed to parse JSON." << endl;
        exit(1);
    }
    scene_json >> sceneObj;

    // Get day count
    this->day = sceneObj.size();

    cout << "初始：";
    player->getPersonality().printRaw();
    cout << endl;
    // 建立今天的場景
    for (int i = 0; i < day; i++) {

        if (i == 0) {
            cout << "\n今天是你與她相識的第" << i + 1 << "天" << endl;
        }

        Scene scene1("Library", sceneObj[i]); // 活大、圖書館、教室、宿舍

        // 印出場景敘述
        scene1.happen();

        // 印出場景的選項，並且讓玩家選擇，並且回傳結果
        // Personality newPersonality = scene1.act(player);
        Personality updateScore;
        double actionCoef = 0;
        scene1.act(*player, updateScore, actionCoef);

        player->update(updateScore); // 依照結果升級
        crush1->update(player->getPersonality(), actionCoef);

        if (i % 3 == 0 && i != 0) {
            cout << "\n今天是你與她相識的第" << i * 6 << "天" << endl;
        }
    }

    // 印出結果
    player->print();

    // 關閉檔案
    scene_json.close();
}
void Game::nextScene() {}
void Game::gameEnd() {
    slowPrint("你認為時機成熟了，決定放手一博，向暗戀對象告白。");
    double end = player->getPersonality().getCorr(crush1->getPersonality());
    cout << end;
}
void Game::printCrush() { crush1->print(); }

void Game::gainItem() {}
void Game::printItems() {
    for (int i = 0; i < items.size(); i++) {
        items[i]->print();
    }
}