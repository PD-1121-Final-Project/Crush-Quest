#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Action.h"

class Scene
{
protected:
	string situationStatement;
	int actionChoiceCnt;
    Action** actionChoice;
    
    //Functions
    void printSituation() const;
	void printActionChoice();
	void printActionDecision(int actionNum);
	void printDecisionConsequence(int actionNum);

public:
	// Constructors
	Scene(string statement, int actionChoiceCnt, Action** action_list);
	~Scene();
	
	// Functions
	void happen();
};
#endif

