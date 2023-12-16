#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../include/Scene_Action/Function.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
using namespace std;

void slowPrint(string statement) {
    istringstream iss(statement);

    char character;
    while (iss >> character) {
        cout << character;
        this_thread::sleep_for(
            chrono::milliseconds(50)); // Adjust the delay time as needed
        flush(cout);
    }

    cout << "\n";
}

#endif
