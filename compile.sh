#!/bin/bash
g++ -std=c++11 -fdiagnostics-color=always -g $(find . -type f -name "*.cpp") -o ./main
