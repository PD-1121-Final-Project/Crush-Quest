#!/bin/bash
g++ -std=c++11 -fdiagnostics-color=always -g $(find ${1} -type f -name "*.cpp") -o ${1}/main
