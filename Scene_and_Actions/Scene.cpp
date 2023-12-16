#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "../include/Characters/Admirer.h"
#include "../include/Characters/Personality.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Scene_Action/Scene.h"

/*
class Scene
{
protected:
        string situationStatement;
        int actionChoiceCnt;
    Action** actionChoice;

    //Functions
    void printSituation() const;
        void printActionChoice() const;
        void printActionDecision(int actionNum);
        void printDecisionConsequence(int actionNum);

public:
        // Constructors
        Scene(string statement, int actionChoiceCnt, Action** actionList);
        ~Scene();

        // Functions
        void happen();
};
*/

Scene::Scene(string name) {
    this->name = name;
    if (name == "Library") {
        this->situationStatement = "你在圖書館裡面，你要做什麼呢?";
        const int TOTAL_ACTION_CNT = 5;
        Action* TALK = new Action(0, "找曖昧對象聊天");
        Action* SCROLL_PHONE = new Action(1, "滑手機");
        Action* WINK = new Action(2, "眨眼");
        Action* FIGHT = new Action(3, "打架");
        Action* STUDY = new Action(4, "讀書");

        this->actionChoice = new Action*[TOTAL_ACTION_CNT];
        actionChoice[0] = TALK;
        actionChoice[1] = SCROLL_PHONE;
        actionChoice[2] = WINK;
        actionChoice[3] = FIGHT;
        actionChoice[4] = STUDY;
        this->actionChoiceCnt = TOTAL_ACTION_CNT;
    }
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
}

void Scene::printSituation() const { slowPrint(this->situationStatement); }

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
