
// Personality.h

#ifndef PERSONALITY_H
#define PERSONALITY_H

struct Personality {
    double wealth;
    double iq;
    double physical;
    double talent;
    double appearance;
    double luck;

    void print();
    void operator+=(Personality& p);
};

#endif // PERSONALITY_H
