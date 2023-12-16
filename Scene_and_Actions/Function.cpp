#ifndef FUNCTIONS_H 
#define FUNCTIONS_H 

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include "../include/Scene_Action/Function.h"
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
