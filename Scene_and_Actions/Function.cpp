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
void sleep(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void rangePrint(double x)
{
	if(x > 80)
	{
		cout << "*****";
	}
	else if(x > 60)
	{
		cout << "****";
	}
	else if(x > 40)
	{
		cout << "***";
	}
	else if (x > 20)
	{
		cout << "**";
	}
	else
	{
		cout << "*";
	}
}

#endif
