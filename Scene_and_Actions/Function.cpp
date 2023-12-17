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
#include <cmath>
#include <random>
using namespace std;

void printDashedLine() {

    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    int width = size.ws_col; // Get the number of columns in the terminal

    cout << "\n";
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

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

void rangePrint(double x) {
    if (x > 4) {
        cout << "★★★★★";
    } else if (x > 3) {
        cout << "★★★★✩";
    } else if (x > 2) {
        cout << "★★★✩✩";
    } else if (x > 1) {
        cout << "★★✩✩✩";
    } else {
        cout << "★✩✩✩✩";
    }
}


// 函數返回一個介於 0 到 1 之間的值，斜率隨著輸入值增加而逐漸遞減，並加入隨機性
double mapLuckToRandomRatio(int luck) {
    // 調整這個值以達到適合的遞減速度
    double decayFactor = 0.7;

    // 映射到 0 到 1 之間的範圍
    double mappedValue = luck / 5.0;

    // 遞減斜率
    double decayedValue = 1.0 - exp(-decayFactor * luck);

    // 加入隨機性
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> randomDist(-0.1, 0.1); // 調整這個範圍以控制隨機性的強度
    double randomValue = randomDist(gen);

    // 最終映射值，加入隨機性
    double result = mappedValue * decayedValue + randomValue;

    // 將結果限制在 0 到 1 之間
    result = max(0.0, min(1.0, result));

    return result;
};


#endif
