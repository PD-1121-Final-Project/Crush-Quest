#include <iostream>
#include <string>
#include <stdexcept> 
#include <chrono>  // 新增的頭文件
#include <thread>  // 新增的頭文件
#include "../Characters/Personality.h"
#include "../Characters/Character.h"
#include "../Characters/Admirer.h"

using namespace std;
int const delay = 10;

void slowPrint(const string& message) 
{
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}


