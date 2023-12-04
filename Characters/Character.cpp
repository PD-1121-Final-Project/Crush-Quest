#include "../include/Characters/Character.h"
#include "../include/Characters/personality.h"

#include <iostream>
#include <string>
using namespace std;

Character::Character(const string& name, int age, personality attributes) {
    this->name = name;
    this->age = age;
    this->attributes = attributes;
}

Character::~Character() { cout << "Character destructor called" << endl; }

void Character::print() { this->attributes.print(); }