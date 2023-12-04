
#include "../include/Characters/Admirer.h"
#include "../include/Characters/Character.h"
#include <iostream>
#include <string>
using namespace std;

Admirer::Admirer(const std::string& name, int age, personality attributes)
    : Character(name, age, attributes) {}

Admirer::~Admirer() {}

void Admirer::print() {
    cout << "Admirer:" << name << " " << age << endl;
    Character::print();
    cout << endl;
}
