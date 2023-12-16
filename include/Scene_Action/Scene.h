#ifndef SCENE_H
#define SCENE_H

#include "../Characters/Admirer.h"
#include "../Characters/Personality.h"
#include "../Scene_Action/Function.h"
#include "../jsonToString.h"
#include "Action.h"
#include <chrono>
#include <iostream>
#include <json/json.h>
#include <sstream>
#include <string>
#include <thread>

using namespace std;

class Event {
    friend class Scene;

  private:
    string dialogs;
    Action** actionChoice;
    int actionChoiceCnt;

  public:
    Event(string dialogs, Action** actionChoice, int actionChoiceCnt) {
        this->dialogs = dialogs;
        this->actionChoice = actionChoice;
        this->actionChoiceCnt = actionChoiceCnt;
    }
    Event(Json::Value eventObj) {
        this->dialogs = JsonToString(eventObj["dialogs"]);
        this->actionChoiceCnt = eventObj["actions"].size();
        this->actionChoice = new Action*[this->actionChoiceCnt];
        for (int j = 0; j < this->actionChoiceCnt; j++) {
            Json::Value actionObj = eventObj["actions"][j];
            this->actionChoice[j] =
                new Action(JsonToString(actionObj["description"]),
                           actionObj["actionCoef"].asDouble(),
                           JsonToString(actionObj["response"]));
        }
    }

    ~Event() {
        for (int i = 0; i < this->actionChoiceCnt; i++) {
            delete this->actionChoice[i];
        }
        delete[] this->actionChoice;
    }
    void printDialogs() {
        slowPrint(dialogs);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    void printActionChoices() {
        cout << "你可以選擇:"
             << "\n";
        for (int i = 0; i < actionChoiceCnt; i++) {
            cout << "(" << i + 1 << ") ";
            actionChoice[i]->printDescription();
            cout << "\n";
        }
    }
    void printDecision(int actionNum) {
        cout << "你選擇: ";
        actionChoice[actionNum]->printDescription();
        cout << "\n";
    }
};

class Scene {
    friend class Event;

  protected:
    string name;
    string introduction;
    Event** events;
    int eventCnt;

    // Functions
    Personality getResult(Admirer player, Action a);

  public:
    // Constructors
    Scene(string name, Json::Value sceneObj);
    ~Scene();

    // Functions
    void happen();
    void act(Admirer player, Personality& updateScore, double& actionCoef);
    void printEvent(int eventIndex);
};
#endif
