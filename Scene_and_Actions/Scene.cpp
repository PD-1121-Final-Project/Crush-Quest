#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Scene.h"
#include "Action.h"
#include "Functions.h"

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
	Scene(string statement, int actionChoiceCnt, Action** action_list);
	~Scene();
	
	// Functions
	void happen();
};
*/


Scene::Scene(string statement, int actionChoiceCnt, Action** action_list)
{
	this->situationStatement = statement;
	this->actionChoiceCnt = actionChoiceCnt;
	
	this->actionChoice = new Action*[this->actionChoiceCnt];
	// Add the actions available.
	for(int i = 0; i < this->actionChoiceCnt; i++)
	{
	    this->actionChoice[i] = action_list[i];
	}
}


Scene::~Scene()
{
	for(int i = 0; i < this->actionChoiceCnt; i++) 
	{
        delete [] this->actionChoice[i];
        this->actionChoice[i] = nullptr;
    }
    delete [] this->actionChoice;
    this->actionChoice = nullptr;
}


void Scene::printSituation() const
{
    slowPrint(this->situationStatement);
}

void Scene::printActionChoice()
{
	cout << "你可以選擇:" << "\n";
	for(int i = 0; i < this->actionChoiceCnt; i++)
	{
		cout << "(" << i+1 << ") ";
		this->actionChoice[i]->printName();
		cout << "\n";
	}
}

void Scene::printActionDecision(int actionNum)
{	
	cout << "你選擇: ";
	this->actionChoice[actionNum]->printName();
	cout << "\n";
}


void Scene::printDecisionConsequence(int actionNum)
{
	slowPrint("然後.......");
}

void Scene::happen()
{
	this->printSituation();
	this->printActionChoice();
	
	int actionDecision_cin;
	cin >> actionDecision_cin;
	actionDecision_cin -= 1;
	
    this->printActionDecision(actionDecision_cin);
    
    this->printDecisionConsequence(actionDecision_cin);
}




