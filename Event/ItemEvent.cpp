#include "../include/Event/ItemEvent.h"
#include <vector>

ItemEvent::ItemEvent(string dialogs, vector<Item*> itemChoice, int itemChoiceCnt)
    : Event(dialogs), itemChoice(itemChoice), itemChoiceCnt(itemChoiceCnt) {}

ItemEvent::~ItemEvent() {

}

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

    slowPrint("請選擇你想要使用的道具：\n");
    // print items
    printItemChoices();

    // get player input
    do {
        if (!(cin >> itemDecision_cin)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else if (itemDecision_cin < 1 ||
                    itemDecision_cin > itemChoiceCnt) {
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else {
            break;
        }
    } while (true);
    itemDecision_cin --;

    slowPrint("請選擇你想要使用的對象：\n");
    slowPrint("(1) 情敵\n(2) 暗戀對象\n(3) 自己\n");

    // get player input
    do {
        if (!(cin >> targetDecision_cin)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else if (targetDecision_cin < 1 ||
                    targetDecision_cin > 3) {
            slowPrint("似乎打成不合規定的輸入，請再試一次\n\n");
        } else {
            break;
        }
    } while (true);
    targetDecision_cin --;

    // print player decision and corresponding response
    

    cout << "\n";

}