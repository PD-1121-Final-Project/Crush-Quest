#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "../include/Characters/Admirer.h"
#include "../include/Characters/Personality.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Scene_Action/Scene.h"
#include "../include/jsonToString.h"
#include <chrono>
#include <json/json.h>
#include <thread>

Scene::Scene(string name) {
    this->name = name;
    if (name == "Library") {
        this->situationStatement = "你在圖書館裡面，你要做什麼呢?";
        const int TOTAL_ACTION_CNT = 5;
        Action* TALK = new Action("找曖昧對象聊天");
        Action* SCROLL_PHONE = new Action("滑手機");
        Action* WINK = new Action("眨眼");
        Action* FIGHT = new Action("打架");
        Action* STUDY = new Action("讀書");

        this->actionChoice = new Action*[TOTAL_ACTION_CNT];
        actionChoice[0] = TALK;
        actionChoice[1] = SCROLL_PHONE;
        actionChoice[2] = WINK;
        actionChoice[3] = FIGHT;
        actionChoice[4] = STUDY;
        this->actionChoiceCnt = TOTAL_ACTION_CNT;
    }
}

Scene::Scene(string name, Json::Value sceneObj) {
    this->name = JsonToString(sceneObj["name"]);
    this->situationStatement = JsonToString(sceneObj["situationStatement"]);

    // Allocate memory for dialogs
    const Json::Value dialogsArr = sceneObj["dialogs"];
    this->dialogsCnt = dialogsArr.size();
    this->dialogs = new string[dialogsCnt];
    cout << dialogsCnt << endl;

    // Fill dialogs with action names
    for (int i = 0; i < dialogsCnt; ++i) {
        if (!dialogsArr[i].isNull()) {
            this->dialogs[i] = JsonToString(dialogsArr[i]);
        }
    }

    const int TOTAL_ACTION_CNT = 5;
    Action* TALK = new Action("找曖昧對象聊天");
    Action* SCROLL_PHONE = new Action("滑手機");
    Action* WINK = new Action("眨眼");
    Action* FIGHT = new Action("打架");
    Action* STUDY = new Action("讀書");

    this->actionChoice = new Action*[TOTAL_ACTION_CNT];
    actionChoice[0] = TALK;
    actionChoice[1] = SCROLL_PHONE;
    actionChoice[2] = WINK;
    actionChoice[3] = FIGHT;
    actionChoice[4] = STUDY;
    this->actionChoiceCnt = TOTAL_ACTION_CNT;
}

Scene::Scene(string statement, int actionChoiceCnt, Action** actionList) {
    this->situationStatement = statement;
    this->actionChoiceCnt = actionChoiceCnt;

    this->actionChoice = new Action*[this->actionChoiceCnt];
    // Add the actions available.
    for (int i = 0; i < this->actionChoiceCnt; i++) {
        this->actionChoice[i] = actionList[i];
    }
}

Scene::~Scene() {
    for (int i = 0; i < this->actionChoiceCnt; i++) {
        delete actionChoice[i];
        actionChoice[i] = nullptr;
    }
    delete[] this->actionChoice;
    this->actionChoice = nullptr;

    delete[] this->dialogs;
}

void Scene::printSituation() const {
    slowPrint(this->situationStatement);
    slowPrint("...");
    for (int i = 0; i < dialogsCnt; i++) {
        slowPrint(this->dialogs[i]);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void Scene::printActionChoice() {
    cout << "你可以選擇:"
         << "\n";
    for (int i = 0; i < this->actionChoiceCnt; i++) {
        cout << "(" << i + 1 << ") ";
        this->actionChoice[i]->printName();
        cout << "\n";
    }
}

void Scene::printActionDecision(int actionNum) {
    cout << "你選擇: ";
    this->actionChoice[actionNum]->printName();
    cout << "\n";
}

personality Scene::getResult(Admirer player, Action a) {
    personality currentPersonality = player.getPersonality();
    // TODO : add the result of the action to the personality
    currentPersonality.wealth += 1;
    currentPersonality.iq += 1;
    currentPersonality.physical += 1;
    currentPersonality.talent += 1;
    currentPersonality.appearance += 1;
    currentPersonality.luck += 1;
    return currentPersonality;
}

void Scene::printDecisionConsequence(int actionNum) {
    slowPrint("然後.......");
}

void Scene::happen() {
    // print situation statement
    this->printSituation();
}

personality Scene::act(Admirer player) {
    this->printActionChoice();

    // get player input
    int actionDecision_cin;
    cin >> actionDecision_cin;

    // change input index
    actionDecision_cin -= 1;

    // print player decision
    this->printActionDecision(actionDecision_cin);

    // get action object
    Action chosenAction = *(this->actionChoice[actionDecision_cin]);

    // get result
    personality newPersonality = this->getResult(player, chosenAction);

    return newPersonality;
}
