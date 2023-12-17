#ifndef ITEMEVENT_H
#define ITEMEVENT_H

#include "Event.h"
#include <vector>

class ItemEvent : public Event {
  private:
    vector<Item*> itemChoice;
    int itemChoiceCnt;

  public:
    ItemEvent(string dialogs, vector<Item*> itemChoice, int itemChoiceCnt);
    // ItemEvent(Json::Value eventObj);
    ~ItemEvent();
    void printItemChoices();
    void printDecision(int itemNum);
    void startEvent(int& itemDecision_cin, int& targetDecision_cin);
};

#endif