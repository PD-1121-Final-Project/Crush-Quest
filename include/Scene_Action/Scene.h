#ifndef SCENE_H
#define SCENE_H

#include "../Characters/Admirer.h"
#include "../Characters/Personality.h"
#include "../Scene_Action/Function.h"
#include "../Event/ActionEvent.h"
#include "../Item/Item.h"
#include "../Event/Event.h"
#include "Action.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Scene {
    friend class ActionEvent;

  protected:
    string name;
    string introduction;
    ActionEvent** events;
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
    ActionEvent* getCurrentEvent(int eventIndex);
};
#endif
