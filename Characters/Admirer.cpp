
#include "../include/Characters/Admirer.h"
#include "../include/Characters/Character.h"
#include <iostream>
#include <string>
using namespace std;

Admirer::Admirer(const std::string& name, int age) : Character(name, age) {}

Admirer::~Admirer() {}

void Admirer::print() { cout << "Admirer:" << name << " " << age << endl; }
