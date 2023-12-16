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

Scene::Scene(string name, Json::Value sceneObj) {
    this->name = JsonToString(sceneObj["name"]);
    this->introduction = JsonToString(sceneObj["introduction"]);

    this->eventCnt = sceneObj["events"].size();
    this->events = new Event*[this->eventCnt];
    for (int i = 0; i < this->eventCnt; i++) {
        Json::Value eventObj = sceneObj["events"][i];
        this->events[i] = new Event(sceneObj["events"][i]);
    }
}

Scene::~Scene() {
    for (int i = 0; i < this->eventCnt; i++) {
        delete this->events[i];
    }
    delete[] this->events;
}

Personality Scene::getResult(Admirer player, Action a) {
    Personality currentPersonality = player.getPersonality();
    // TODO : add the result of the action to the Personality
    currentPersonality.wealth += 1;
    currentPersonality.iq += 1;
    currentPersonality.physical += 1;
    currentPersonality.talent += 1;
    currentPersonality.appearance += 1;
    currentPersonality.luck += 1;
    return currentPersonality;
}

void Scene::happen() {
    slowPrint(this->introduction);
    slowPrint("...");
}

void Scene::printEvent(int eventIndex) {
    // print event
    events[eventIndex]->printDialogs();
    events[eventIndex]->printActionChoices();
}

void Scene::act(Admirer player, Personality& updateScore, double& actionCoef) {

    const int eventIndex = 0;

    this->printEvent(eventIndex);

    // // get player input
    // int actionDecision_cin;
    // cin >> actionDecision_cin;

    // // change input index
    // actionDecision_cin -= 1;

    // // print player decision
    // this->events[eventIndex].printDecision(actionDecision_cin);

    // // get action object
    // Action chosenAction =
    //     *(this->events[eventIndex].actionChoice[actionDecision_cin]);

    // // get result
    // updateScore = this->getResult(player, chosenAction);
    // actionCoef = chosenAction.getCoef();
}
