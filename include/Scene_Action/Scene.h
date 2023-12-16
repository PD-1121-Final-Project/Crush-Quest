#ifndef SCENE_H
#define SCENE_H

#include "../Characters/Admirer.h"
#include "../Characters/Personality.h"
#include "Action.h"
#include <iostream>
#include <json/json.h>
#include <sstream>
#include <string>

using namespace std;

class Scene {
  protected:
    string name;
    string situationStatement;
    int actionChoiceCnt;
    Action** actionChoice;
    string* dialogs;
    int dialogsCnt;

    // Functions
    void printSituation() const;
    void printActionChoice();
    void printActionDecision(int actionNum);
    void printDecisionConsequence(int actionNum);
    personality getResult(Admirer player, Action a);

  public:
    // Constructors
    Scene(string statement, int actionChoiceCnt, Action** actionList);
    Scene(string name);
    Scene(string name, Json::Value sceneObj);
    ~Scene();

    // Functions
    void happen();
    personality act(Admirer player);
};
#endif
