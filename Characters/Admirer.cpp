
#include "../include/Characters/Admirer.h"
#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"
#include <iostream>
#include <string>
using namespace std;

Admirer::Admirer(const std::string& name, Personality attributes)
    : Character(name, attributes) {}

Admirer::~Admirer() {}

void Admirer::print() {
    cout << "Admirer:" << name << " "  << endl;
    Character::print();
    cout << endl;
}

void Admirer::update(Personality newAttributes, double impressionIncre) {
    this->attributes += newAttributes;
}
