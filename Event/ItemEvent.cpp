#include "../include/Event/ItemEvent.h"
#include <vector>

ItemEvent::ItemEvent(string dialogs, vector<Item*> itemChoice,
                     int itemChoiceCnt)
    : Event(dialogs), itemChoice(itemChoice), itemChoiceCnt(itemChoiceCnt) {}

ItemEvent::~ItemEvent() {}

void ItemEvent::printItemChoices() {

    if (itemChoiceCnt > 0) {
        cout << endl;
        cout << ">>"
             << "\n";
        cout << endl;

        for (int i = 0; i < itemChoiceCnt; i++) {
            cout << "(" << i + 1 << ") ";
            itemChoice[i]->printName();
            cout << "\n";
        }
    }
}
void ItemEvent::startEvent(int& itemDecision_cin, int& targetDecision_cin) {

    cout << "請選擇你想要使用的道具：\n";
    // print items
    printItemChoices();

    // get player input
    do {
        try {
            if (!(std::cin >> itemDecision_cin)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else if (itemDecision_cin < 1 ||
                       itemDecision_cin > itemChoiceCnt) {
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else {
                break; // 如果輸入有效，跳出循環
            }
        } catch (const std::runtime_error& e) {
            cout << (e.what());
        }
    } while (true);
    itemDecision_cin--;

    cout << "請選擇你想要使用的對象：\n";
    cout << "(1) 情敵\n(2) 暗戀對象\n(3) 自己\n";

    // get player input
    do {
        try {
            if (!(std::cin >> targetDecision_cin)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else if (targetDecision_cin < 1 || targetDecision_cin > 3) {
                throw std::runtime_error(
                    "似乎打成不合規定的輸入，請再試一次\n\n");
            } else {
                break; // 如果輸入有效，跳出循環
            }
        } catch (const std::runtime_error& e) {
            std::cout << e.what();
        }
    } while (true);

    // print player decision and corresponding response

    cout << "\n";
}