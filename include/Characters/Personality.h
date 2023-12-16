
// Personality.h

#ifndef PERSONALITY_H
#define PERSONALITY_H

struct personality {
    double wealth;
    double iq;
    double physical;
    double talent;
    double appearance;
    double luck;

    void print();
    void operator+=(personality& p);
};

#endif // PERSONALITY_H
