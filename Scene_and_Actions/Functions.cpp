#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

void slowPrint(string statement)
{
    istringstream iss(statement);

    char character;
    while (iss >> character) {
        cout << character;
        this_thread::sleep_for(chrono::milliseconds(50));  // Adjust the delay time as needed
    }
    cout << "\n";
}

#endif
