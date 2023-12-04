#include <iostream>
#include <string>
#include <sstream>

#include "Functions.h"
#include "Action.h"
#include "Scene.h"
#include "Constants.h"
using namespace std;


int main()
{
	Action TALK = Action(0, "���");
	Action SCROLL_PHONE = Action(1, "�Ƥ��");
	Action WINK = Action(2, "�ߴA��");
	Action FIGHT = Action(3, "���[");
	Action STUDY = Action(4, "Ū��");
	
	Action** action_list = new Action*[TOTAL_ACTION_CNT];
	action_list[0] = &TALK;
	action_list[1] = &SCROLL_PHONE;
	action_list[2] = &WINK;
	action_list[3] = &FIGHT;
	action_list[4] = &STUDY;
	
	Scene DAY_ONE = Scene("���ѧA�Ө�t�W����s�A�ݨ�@�ӦP�ǧA�@���鱡..........", 5, action_list);
	DAY_ONE.happen();
	

	return 0;
}
