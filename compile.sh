#!/bin/bash
g++ -std=c++11 -fdiagnostics-color=always -g $(find . -type f -name "*.cpp" ! -path "./vcpkg/*") -I./include/jsoncpp_arm64-osx/include -L./include/jsoncpp_arm64-osx/lib -ljsoncpp -o ./main
