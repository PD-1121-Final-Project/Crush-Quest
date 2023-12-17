#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../include/Scene_Action/Function.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <termios.h>
#include <thread>
#include <unistd.h>
using namespace std;

// Function to set the terminal to raw mode
void enableRawMode(termios& orig_termios) {
    termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to restore the original terminal settings
void disableRawMode(termios& orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void slowPrint(string statement, termios* orig_termios) {

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

        if (character == '\n' && orig_termios != nullptr) {
            cout << "[Press space to continue]" << endl;
            enableRawMode(*orig_termios);
            while (true) {
                char key = getchar();
                if (key == ' ')
                    break; // Break the loop if space is pressed
            }
            disableRawMode(*orig_termios);

            // Move cursor up and clear line
            cout << "\033[A\033[2K";
        }
    }

    cout << "\n";
}

void sleep(int ms) { this_thread::sleep_for(chrono::milliseconds(ms)); }

void rangePrint(double x)
{
	if(x > 4)
	{
		cout << "★★★★★";
	}
	else if(x > 3)
	{
		cout << "★★★★✩";
	}
	else if(x > 2)
	{
		cout << "★★★✩✩";
	}
	else if (x > 1)
	{
		cout << "★★✩✩✩";
	}
	else
	{
		cout << "★✩✩✩✩";
	}

}

#endif
