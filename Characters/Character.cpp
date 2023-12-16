#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"

#include <iostream>
#include <string>
using namespace std;

Character::Character(const string& name, Personality attributes) {
    this->name = name;
    this->attributes = attributes;
}

void Character::print() { this->attributes.print(); }