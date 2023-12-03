
#include "../include/Characters/Crush.h"
#include "../include/Characters/Character.h"
#include <iostream>
#include <string>
using namespace std;

Crush::Crush(const std::string& name, int age) : Character(name, age) {}

Crush::~Crush() {}

void Crush::print() { cout << "Crush:" << name << " " << age << endl; }
void Crush::calcLove(Admirer admirer){}