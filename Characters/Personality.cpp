#include "../include/Characters/Personality.h"
#include "../include/Scene_Action/Function.h"
#include <iostream>
#include <cmath>
using namespace std;

void Personality::print() {
    cout << "| wealth: ";
    rangePrint(wealth);
    cout << " |";
    sleep(700);

    cout << "| intelligence: ";
    rangePrint(iq);
    cout << " |";
    sleep(700);

    cout << "| physical: ";
    rangePrint(physical);
    cout << " |";
    sleep(700);

    cout << "| talent: ";
    rangePrint(talent);
    cout << " |";
    sleep(700);

    cout << "| appearance: ";
    rangePrint(appearance);
    cout << " |";
    sleep(700);

    cout << "| luck: ";
    rangePrint(luck);
    cout << " |";

    cout << endl;
}

void Personality::operator+=(const Personality& p) {
    wealth += p.wealth;
    iq += p.iq;
    physical += p.physical;
    talent += p.talent;
    appearance += p.appearance;
    luck += p.luck;
}

double Personality::mean() const {
    return (wealth + iq + physical + talent + appearance) / CORRNUM;
}

double Personality::covariance(const Personality& other) const {
    double mean1 = mean();
    double mean2 = other.mean();

    double cov = (wealth - mean1) * (other.wealth - mean2) +
                 (iq - mean1) * (other.iq - mean2) +
                 (physical - mean1) * (other.physical - mean2) +
                 (talent - mean1) * (other.talent - mean2) +
                 (appearance - mean1) * (other.appearance - mean2);

    return cov / CORRNUM;
}

double Personality::standardDeviation() const {
    double meanVal = mean();

    double variance = pow(wealth - meanVal, 2) + pow(iq - meanVal, 2) +
                      pow(physical - meanVal, 2) + pow(talent - meanVal, 2) +
                      pow(appearance - meanVal, 2);

    return sqrt(variance / CORRNUM);
}

double Personality::getCorr(const Personality& other) const {
    double cov = covariance(other);
    double stdDev1 = standardDeviation();
    double stdDev2 = other.standardDeviation();

    return cov / (stdDev1 * stdDev2);
}