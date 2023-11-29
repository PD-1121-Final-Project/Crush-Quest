#include "../include/Characters/Character.h"
#include <iostream>
#include <string>
using namespace std;

Character::Character(const string& name, int age) {
    this->name = name;
    this->age = age;
}

Character::~Character() { cout << "Character destructor called" << endl; }