#include "../include/Characters/Crush.h"
#include "../include/Characters/Admirer.h"

Crush::Crush(const string& name, int age, Personality attributes)
    : Character(name, age, attributes) {}

Crush::~Crush() {}

void Crush::print() {
    cout << "Crush:" << name << " " << love << endl;
    Character::print();
    cout << endl;
}
void Crush::update(Personality admirerAtt, double actionCoef) {
    double personalityCorr = this->attributes.getCorr(admirerAtt);
    love += actionCoef + personalityCorr;
}