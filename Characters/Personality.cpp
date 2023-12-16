#include "../include/Characters/Personality.h"
#include "../include/Scene_Action/Function.h"
#include <iostream>
using namespace std;


void personality::print() {
    cout << "| wealth: ";
	rangePrint(wealth);
	cout << " |";
	sleep(700);
	
    cout << "| intelligence: ";
    rangePrint(iq);
    cout << " |";
    sleep(700);
	
    cout << "| physical: ";
	rangePrint(physical) ;
	cout << " |";
	sleep(700);
	
    cout << "| talent: ";
    rangePrint(talent);
    cout << " |";
    sleep(700);
	
    cout << "| appearance: ";
    rangePrint(appearance);
    cout << " |";
    sleep(700);
	
    cout << "| luck: ";
    rangePrint(luck);
    cout << " |";
    
	cout << endl;
}


void personality::operator+=(personality& p){
    wealth += p.wealth;
    iq += p.iq;
    physical += p.physical;
    talent += p.talent;
    appearance += p.appearance;
    luck += p.luck;
}
