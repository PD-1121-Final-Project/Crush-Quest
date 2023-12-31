﻿
// Personality.h

#ifndef PERSONALITY_H
#define PERSONALITY_H

#include <iostream>
using namespace std;

const double CORRNUM =
    5.0; // the number of attributes used to calculate correlation

struct Personality {
    double wealth;
    double iq;
    double physical;
    double talent;
    double appearance;
    double luck; // excluded in getCorr

    double mean() const;
    double covariance(const Personality& other) const;
    double standardDeviation() const;

    void print();
    void operator+=(const Personality& p);
    double getCorr(const Personality& other) const;
    void printRaw() const {
        cout << wealth << " " << iq << " " << physical << " " << talent << " "
             << appearance << " " << luck << endl;
    }
};

#endif // PERSONALITY_H
