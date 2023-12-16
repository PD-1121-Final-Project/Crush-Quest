#include "../include/Characters/Personality.h"
#include "../include/Scene_Action/Function.h"
#include <iostream>
using namespace std;

void Personality::print() {
    cout << "| wealth: " << wealth << " | ";
    
    cout << "intellegence: " << iq << " | ";
    
    cout << "physical: " << physical << " | ";
    
    cout << "talent: " << talent << " | ";
    
    cout << "appearance: " << appearance << " | ";
    
    cout << "luck: " << luck <<  " |";
}
void Personality::operator+=(Personality& p){
    wealth += p.wealth;
    iq += p.iq;
    physical += p.physical;
    talent += p.talent;
    appearance += p.appearance;
    luck += p.luck;
}
