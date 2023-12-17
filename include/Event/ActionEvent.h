#ifndef ACTIONEVENT_H
#define ACTIONEVENT_H

#include "Event.h"

class ActionEvent : public Event {
  private:
    // for action event
    Action** actionChoice;
    int actionChoiceCnt;

  public:
    ActionEvent(string dialogs, Action** actionChoice, int actionChoiceCnt);
    ActionEvent(Json::Value eventObj);
    ~ActionEvent();
  
    void printDialogs();
    void printActionChoices();
    void printDecision(int actionNum);

    friend class Scene;
};

#endif