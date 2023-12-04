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
	Action TALK = Action(0, "聊天");
	Action SCROLL_PHONE = Action(1, "滑手機");
	Action WINK = Action(2, "拋媚眼");
	Action FIGHT = Action(3, "打架");
	Action STUDY = Action(4, "讀書");
	
	Action** action_list = new Action*[TOTAL_ACTION_CNT];
	action_list[0] = &TALK;
	action_list[1] = &SCROLL_PHONE;
	action_list[2] = &WINK;
	action_list[3] = &FIGHT;
	action_list[4] = &STUDY;
	
	Scene DAY_ONE = Scene("今天你來到系上的迎新，看到一個同學你一見鍾情..........", 5, action_list);
	DAY_ONE.happen();
	

	return 0;
}
