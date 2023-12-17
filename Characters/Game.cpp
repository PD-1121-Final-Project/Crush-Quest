
#include "../include/Game/Game.h"
#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"
#include "../include/Game/Game.h"
#include "../include/Item/Item.h"
#include "../include/Scene_Action/Function.h"
#include <chrono> // 新增的頭文件
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <thread> // 新增的頭文件
#include <vector>

using namespace std;
Game::Game() : player(nullptr), day(0) {
    // wealth iq; physical; talent appearance; luck
    Personality attribute;
    // 以下為隨機挑一個小美的理想型

    random_device rd;
    mt19937 gen(rd());

    // 定義一個均勻分佈，範圍為 1 到 5
    uniform_int_distribution<int> distribution(1, 5);

    // 生成隨機數
    int randomNumber = distribution(gen);
    switch (randomNumber) {
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
    default:
        attribute = {0, 0, 0, 0, 0, 0};
        break;
    }

    // 打印結果

    crush1 = new Crush("暗戀對象", attribute);
    enemy = new Enemy("情敵", attribute);
    Personality luckPotionChange = {0, 0, 0, 0, 0, 1};
    Personality steroidChange = {0, 0, 1, 0, 0, 0};
    Personality smartMedChange = {0, 1, 0, 0, 0, 0};
    Personality makeUpChange = {0, 0, 0, 0, 1, 0};
    Personality moneyChange = {1, 0, 0, 0, 0, 0};
    Personality laxativeChange = {-0.5, -0.5, -0.5, -0.5, -0.5, -0.5};
    Personality flowerChange = {0, 0, 0, 0, 0, 0};

    items.push_back(new Item("幸運藥水", luckPotionChange, 2, "感覺今天特別走運，好像整個世界都對我微笑", "你在一個神秘的藥店中發現了一瓶「幸運藥水」，老板告訴你，它能讓你感受到今天的一切都充滿了好運。 \n♪♪♪ 獲得道具「幸運藥水」"));
    items.push_back(new Item("類固醇", steroidChange, 1, "感覺自己變強壯了，肌肉充滿力量，勇氣倍增", "在一家健身房，你找到了一瓶「類固醇」，教練向你保證，它能讓你的身體變得更強大，充滿力量。 \n♪♪♪ 獲得道具「類固醇」"));
    items.push_back(new Item("聰明藥", smartMedChange, 1, "感覺自己變聰明了，思維變得清晰，解決問題事半功倍", "你在一家古老的書店中偶然發現了「聰明藥」，店主告訴你，只要使用它，你就能讓思維變得更加敏捷。 \n♪♪♪ 獲得道具「聰明藥」"));
    items.push_back(new Item("化妝品", makeUpChange, 2, "感覺自己變美美的，如花般綻放，自信滿滿", "在一場精緻的化妝品展覽上，你購得了一盒「讓人變美的神奇化妝品」，使用後讓你如花一般綻放。 \n♪♪♪  獲得道具「化妝品」"));
    items.push_back(new Item("擁有財富之力的金幣", moneyChange, 2, "感覺自己超有錢的，財源滾滾來，金錢如雨下", "在一個神秘的寶藏地點，你發現了一袋「擁有財富之力的金幣」，當你把它帶在身上時，突然感覺錢逐漸湧入你的生活。 \n♪♪♪ 獲得道具「擁有財富之力的金幣」"));
    items.push_back(new Item("瀉藥", laxativeChange, -10, "感覺自己有點不舒服，肚子有些翻江倒海，不太對勁", "在一家古老的藥店中，你被售賣一包「瀉藥」，老闆神色嚴肅地告誡你，這是一種強力的排毒藥劑，需要小心使用。\n♪♪♪ 獲得道具「瀉藥」"));
    items.push_back(new Item("愛情之花", flowerChange, +10, "感覺更喜歡你了，心花怒放，愛意漫漫如春暖花開", "漫步在花園中，你發現了一朵特別的「奇蹟之花」，據說它只在特殊的時刻開放，你輕輕觸碰花瓣，突然感到一陣幸福和喜悅湧上心頭。\n♪♪♪ 獲得道具「愛情之花」"));
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
    delete enemy;
    enemy = nullptr;
};
void Game::init() {
    int choice;
    Personality attribute;

    slowPrint("\\♥︎ 歡迎遊玩台大校園戀愛文字遊戲 ♥︎/\n在這款遊戲中，你是一位對校園充滿期待的大一新生，\n"
              "你將認識一位喜歡的對象，並透過與他互動增加好感度與能力值。\n"
              "請小心！情敵可能就在你身邊，遊戲中獲得的道具或許可以派上用場。\n只有你能夠自由掌控自己的未來走向，開始談場甜甜的戀愛吧！\n\n"
              "現在，請選擇您的角色設定：");
    cout << "\n1.富二代\n2.體育健將\n3.高材生\n4.帥哥\n5.藝術家\n6.出身不太好，但做什麼事都特別順心的人\n7.全知全能\n（請輸入數字不需加點）\n";

    do {
        try {
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else if (choice < 1 || choice > 7) {
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else {
                break; // 如果輸入有效，跳出循環
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what();
        }
    } while (true);

    switch (choice) {
    case 1:
        attribute = {4, 0, 0, 0, 2, 2};
        break;
    case 2:
        attribute = {0, 0, 4, 2, 2, 2};
        break;
    case 3:
        attribute = {0, 4, 0, 2, 2, 2};
        break;
    case 4:
        attribute = {2, 0, 0, 2, 4, 2};
        break;
    case 5:
        attribute = {0, 2, 0, 4, 2, 2};
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
    slowPrint("\n請輸入角色名稱:");
    cin >> name;

    player = new Admirer(name, attribute);
    cout << "\n\n你的能力值：\n";
    player->getAttributes().print();
    printDashedLine();
    // crush1 -> print();

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

    // 建立今天的場景
    for (int i = 0; i < day; i++) {

        if (i == 0) {
            sleep(1000);
            cout << "\n今天是你與她相識的第" << i + 1 << "天" << endl;
        }
        else if (i % 3 == 0 && i != 0) {
            sleep(1000);
            cout << "\n今天是你與她相識的第" << i * 6 << "天" << endl;
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
        crush1->corUpdate(player->getAttributes(), actionCoef);

        // 情敵攻擊事件
        if (i > 5) {
            enemy->attack(*crush1, *player, this->getNonZeroItems(),
                          this->getNonZeroItemCnt());
        }

        // 印出結果
        cout << "\n\n";
        cout << "你目前的能力值是：\n";
        player->getPersonality().print();

        cout << "[Press space to continue]" << endl;
        termios orig_termios;
        tcgetattr(STDIN_FILENO, &orig_termios);

        enableRawMode(orig_termios);
        while (true) {
            char key = getchar();
            if (key == ' ')
                break; // Break the loop if space is pressed
        }
        disableRawMode(orig_termios);

        // Move cursor up and clear line
        cout << "\033[A\033[2K";

        printDashedLine();

        if (i % 3 == 0 && i != 0) {
            cout << "\n今天是你與她相識的第" << i * 6 << "天" << endl;
        }


        //以下為獲得item實作
        random_device rd;
        mt19937 gen(rd());
        // 定義一個均勻分佈，範圍為 1 到 5
        uniform_int_distribution<int> distribution(0, 5);
        // 生成隨機數
        int randomNumber = distribution(gen);
        if (randomNumber <= player->getPersonality().luck) {
            uniform_int_distribution<int> distribution(0, 6);
            int randomNumber = distribution(gen);
            items[randomNumber]->gainThisItem();
        }
    }

    // 印出結果
    player->print();

    // 關閉檔案
    scene_json.close();
}
void Game::nextScene() {}
void Game::gameEnd() {
    slowPrint("你認為時機成熟了，決定放手一博，向暗戀對象告白。\n\n\n---你將小美約到醉月湖畔---\n\n\n你：小美，我其實...\n暗戀你很久了。\n你:..願意和我交往嗎？\n小美：...\n這..這麼突然");
    if(enemy->getImpression() <= crush1->getImpre())
    {
        slowPrint("其實我也喜歡你。遊戲結束");
    }
    else
    {
        slowPrint("你：嗨，我一直都想告訴你一個事情，我對你有一點特別的感覺，我想我們可以一起試試看嗎？\n\
                    暗戀對象：哇，真的嗎？其實我也一直有種感覺，但是... \n你：但是什麼呢？\n暗戀對象：其實最近我發現，我對另外一個人有點心動。\
                    \n你：（心情沉重）哦，是誰呢？\n暗戀對象：是那個新轉學生，他真的好有趣，我們聊得很開心。\n你：（心碎）哦，是這樣啊。那你們是不是已經...\
                    \n暗戀對象：嗯，我們昨天已經約了一起吃飯，感覺好奇妙。\n你：（嘴角勉強笑著）那太好了，我祝福你們。\n暗戀對象：謝謝，其實我還以為你會對我有點失望呢。\
                    \n你：（苦笑）沒有啦，我只是覺得自己有點太天真了，希望你和他會很幸福。\n暗戀對象：謝謝你的祝福，希望我們還是可以做朋友。\n你：當然，沒問題。祝你們有一段美好的感情。");
    }
    crush1->print();
}
void Game::printCrush() { crush1->print(); }

void Game::gainItem() {}
void Game::printItems() {
    for (int i = 0; i < items.size(); i++) {
        items[i]->print();
    }
}

int Game::getNonZeroItemCnt() {
    int cnt = 0;
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->getItemNum() > 0) {
            cnt++;
        }
    }
    return cnt;
}

vector<Item*> Game::getNonZeroItems() {
    vector<Item*> nonZeroItems;
    for (int i = 0; i < items.size(); i++) {
        if (items[i]->getItemNum() > 0) {
            nonZeroItems.push_back(items[i]);
        }
    }
    return nonZeroItems;
}