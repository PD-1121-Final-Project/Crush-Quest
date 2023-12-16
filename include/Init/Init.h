#include <iostream>
#include <string>
#include <stdexcept> 
#include <chrono>  // 新增的頭文件
#include <thread>  // 新增的頭文件
#include "../Characters/Personality.h"
#include "../Characters/Character.h"
#include "../Characters/Admirer.h"

using namespace std;
int const delay = 10;

void slowPrint(const string& message) {
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

personality choose()  // 選擇角色
{
    int choice ;
    personality attribute;

    slowPrint("歡迎遊玩台大校園戀愛文字遊戲\n\n你是一位對校園充滿期待的大一新生，在這遊戲中，你能夠自由掌控你的未來走向，請選擇您的身家背景\n1.富二代\n2.體育健將\n3.高材生\n4.帥哥\n5.藝術家\n6.出身不太好，但做什麼事都特別順心的人\n7.全知全能\n（請輸入數字不需加點）");

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

    switch (choice)
    {
    case 1:
        attribute = {4, 0, 0, 0, 2, 2};
        return attribute;
    case 2:
        attribute = {0, 0, 4, 2, 2, 1};
        return attribute;
    case 3:
        attribute = {0, 4, 0, 2, 2, 1};
        return attribute;
    case 4:
        attribute = {2, 0, 0, 2, 4, 1};
        return attribute;
    case 5:
        attribute = {0, 2, 0, 4, 2, 1};
        return attribute;
    case 6:
        attribute = {0, 0, 0, 0, 0 ,5};
        return attribute;
    case 7:
        attribute = {5 ,5 ,5 ,5 ,5 ,0};
        return attribute;
    default:
        attribute = {0 ,0 ,0 ,0 ,0 ,0};
        return attribute;
        break;
    }
}

string enterName()  // 輸入名稱
{
    string name;
    slowPrint("請輸入角色名稱:");
    cin >> name;
    return name;
}

void init(Admirer*& player)
{
    personality tempP = choose();
    string tempN = enterName();
    player = new Admirer(tempN, tempP);
};
