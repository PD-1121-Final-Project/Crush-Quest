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
    // Remove the first and last character if they are quotes
    if (statement.front() == '"' && statement.back() == '"') {
        statement = statement.substr(1, statement.size() - 2);
    }

    // Replace all occurrences of "\n" with actual newlines
    string::size_type pos = 0;
    while ((pos = statement.find("\\n", pos)) != string::npos) {
        statement.replace(pos, 2, "\n");
        pos += 1;
    }

    // Print characters one by one
    for (char character : statement) {
        cout << character;
        this_thread::sleep_for(
            chrono::milliseconds(1)); // Adjust delay time as needed
        flush(cout);
    }

    cout << "\n";
}

void sleep(int ms) { this_thread::sleep_for(chrono::milliseconds(ms)); }

void rangePrint(double x)
{
	if(x > 4)
	{
		cout << "*****";
	}
	else if(x > 3)
	{
		cout << "****";
	}
	else if(x > 2)
	{
		cout << "***";
	}
	else if (x > 1)
	{
		cout << "**";
	}
	else
	{
		cout << "*";
	}

}

#endif
