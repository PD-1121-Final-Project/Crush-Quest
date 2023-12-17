#ifndef ITEMEVENT_H
#define ITEMEVENT_H

#include "Event.h"

class ItemEvent : public Event {
  private:
    Item** itemChoice;
    int itemChoiceCnt;

  public:
    ItemEvent(string dialogs, Item** itemChoice, int itemChoiceCnt);
    // ItemEvent(Json::Value eventObj);
    ~ItemEvent();
    void printItemChoices();
    void printDecision(int itemNum);
    void startEvent(int& itemDecision_cin, int& targetDecision_cin);
};

#endif