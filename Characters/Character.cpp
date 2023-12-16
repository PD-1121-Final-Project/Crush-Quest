#include "../include/Characters/Character.h"
#include "../include/Characters/Personality.h"

#include <iostream>
#include <string>
using namespace std;

Character::Character(const string& name, int age, Personality attributes) {
    this->name = name;
    this->age = age;
    this->attributes = attributes;
}

void Character::print() { this->attributes.print(); }