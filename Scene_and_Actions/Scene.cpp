#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "../include/Characters/Admirer.h"
#include "../include/Characters/Personality.h"
#include "../include/Event/ActionEvent.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Scene_Action/Scene.h"
#include "../include/jsonToString.h"
#include <chrono>
#include <json/json.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

Scene::Scene(string name, Json::Value sceneObj) {
    this->name = JsonToString(sceneObj["name"]);
    this->introduction = JsonToString(sceneObj["introduction"]);

    this->eventCnt = sceneObj["events"].size();
    this->events = new ActionEvent*[this->eventCnt];
    for (int i = 0; i < this->eventCnt; i++) {
        Json::Value eventObj = sceneObj["events"][i];
        this->events[i] = new ActionEvent(sceneObj["events"][i]);
    }
}

Scene::~Scene() {
    for (int i = 0; i < this->eventCnt; i++) {
        delete this->events[i];
    }
    delete[] this->events;
}

void Scene::happen() {
    cout << '\n';
    slowPrint(this->introduction);
}

ActionEvent* Scene::getCurrentEvent(int eventIndex) {
    // TODO : get current event
    return this->events[eventIndex];
}

void Scene::printEvent(int eventIndex) {
    // print event
    // Store original terminal settings
    events[eventIndex]->printDialogs();
    events[eventIndex]->printActionChoices();
}

void Scene::act(Admirer player, Personality& updateScore, double& actionCoef) {
    for (int i = 0; i < this->eventCnt; i++) {
        slowPrint("...");
        cout << "\n";
        this->printEvent(i);

        // get player inpu
        int actionCnt = this->getCurrentEvent(i)->actionChoiceCnt;

        if (actionCnt > 0) {

            int actionDecision_cin;
            // get player input
            do {
                try {
                    if (!(std::cin >> actionDecision_cin)) {
                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::runtime_error(
                            "似乎打成不合規定的輸入，請再試一次\n\n");
                    } else if (actionDecision_cin < 1 ||
                               actionDecision_cin > actionCnt) {
                        throw std::runtime_error(
                            "似乎打成不合規定的輸入，請再試一次\n\n");
                    } else {
                        break; // 如果輸入有效，跳出循環
                    }
                } catch (const std::runtime_error& e) {
                    std::cout << e.what();
                }
            } while (true);

            // change input index
            actionDecision_cin -= 1;

            // print player decision
            this->events[i]->printDecision(actionDecision_cin);

            cout << "\n";

            // get action object
            Action chosenAction =
                *(this->events[i]->actionChoice[actionDecision_cin]);

            // print action response
            slowPrint(chosenAction.getResponse());

            // get result
            updateScore += chosenAction.getUpdateScore();
            actionCoef += chosenAction.getCoef();
        }
    }
}
