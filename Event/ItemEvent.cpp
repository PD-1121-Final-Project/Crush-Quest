#include "../include/Event/ItemEvent.h"

ItemEvent::ItemEvent(string dialogs, Item** itemChoice, int itemChoiceCnt)
    : Event(dialogs), itemChoice(itemChoice), itemChoiceCnt(itemChoiceCnt) {}

ItemEvent::~ItemEvent() {
    for (int i = 0; i < this->itemChoiceCnt; i++) {
        delete this->itemChoice[i];
    }
    delete[] this->itemChoice;
}