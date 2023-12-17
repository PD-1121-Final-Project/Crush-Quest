#include "../include/Characters/Crush.h"
#include "../include/Characters/Admirer.h"
#include "../include/Scene_Action/Function.h"

Crush::Crush(const string& name, Personality attributes)
    : Character(name, attributes) {}

Crush::~Crush() {}

void Crush::print() {
    cout << "Crush:" << name << " " << impression << endl;
    Character::print();
    cout << endl;
}
void Crush::update(Personality admirerAtt, double impressionIncre) {

    impression += impressionIncre;
    this->attributes += admirerAtt;
}

void Crush::corUpdate(Personality admirerAtt, double actionCoef) 
    {
      double personalityCorr = this->attributes.getCorr(admirerAtt);
      impression += mapLuckToRandomRatio(actionCoef + personalityCorr);
    }
