
#include "../include/Characters/Crush.h"
#include "../include/Characters/Character.h"
#include <iostream>
#include <string>
using namespace std;

Crush::Crush(const std::string& name, personality attributes)
    : Character(name, attributes) {}

Crush::~Crush() {}

void Crush::print() {
    cout << "Crush:" << name << " " << endl;
    Character::print();
    cout << endl;
}
void Crush::calcLove(Admirer admirer) {}