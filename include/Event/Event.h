#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "../Item/Item.h"
#include "../jsonToString.h"
#include "../Scene_Action/Action.h"
#include "../Characters/Personality.h"
#include "../Scene_Action/Function.h"
#include <chrono>
#include <iostream>
#include <json/json.h>
#include <sstream>
#include <string>
#include <thread>

class Event {

  protected:
    string dialogs;

  public:
    Event(string dialogs): dialogs(dialogs) {};
    Event(Json::Value eventObj){};
    ~Event(){};

  friend class Scene;
};

#endif