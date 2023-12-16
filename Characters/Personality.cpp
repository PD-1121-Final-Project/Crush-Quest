#include "../include/Characters/Personality.h"
#include <iostream>
using namespace std;

void personality::print() {
    cout << "wealth: " << wealth << endl;
    cout << "iq: " << iq << endl;
    cout << "physical: " << physical << endl;
    cout << "talent: " << talent << endl;
    cout << "appearance: " << appearance << endl;
    cout << "luck: " << luck << endl;
}