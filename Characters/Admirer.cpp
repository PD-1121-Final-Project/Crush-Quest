
#include "../include/Characters/Admirer.h"
#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"
#include <iostream>
#include <string>
using namespace std;

Admirer::Admirer(const std::string& name, int age, Personality attributes)
    : Character(name, age, attributes) {}

Admirer::~Admirer() {}

void Admirer::print() {
    cout << "Admirer:" << name << " " << age << endl;
    Character::print();
    cout << endl;
}

void Admirer::update(Personality newAttributes) {
    this->attributes += newAttributes;
}
