#include <iostream>
#include <sstream>
#include <string>

#include "../include/Scene_Action/Action.h"
#include "../include/Scene_Action/Constant.h"
#include "../include/Scene_Action/Function.h"
#include "../include/Scene_Action/Scene.h"
using namespace std;

int testScene() {
    Action TALK = Action(0, "���");
    Action SCROLL_PHONE = Action(1, "�Ƥ��");
    Action WINK = Action(2, "�ߴA��");
    Action FIGHT = Action(3, "���[");
    Action STUDY = Action(4, "Ū��");

    Action** actionList = new Action*[TOTAL_ACTION_CNT];
    actionList[0] = &TALK;
    actionList[1] = &SCROLL_PHONE;
    actionList[2] = &WINK;
    actionList[3] = &FIGHT;
    actionList[4] = &STUDY;

    Scene DAY_ONE =
        Scene("���ѧA�Ө�t�W����s�A�ݨ�@�ӦP�ǧA�@���鱡..........", 5, actionList);
    DAY_ONE.happen();

    return 0;
}
