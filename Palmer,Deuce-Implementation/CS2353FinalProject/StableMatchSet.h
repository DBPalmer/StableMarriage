//
// Created by Deuce Palmer on 10/25/21.
//
#include "SetOfElements.h"
#ifndef CS2353FINALPROJECT_STABLEMATCHSET_H
#define CS2353FINALPROJECT_STABLEMATCHSET_H
#include <string>
#include <vector>
#include <list>
using namespace std;

class StableMatchSet {
private:
    vector<pair<Element*, Element*> > matches;
public:
    StableMatchSet();
    void determineMatches(SetOfElements *A, SetOfElements *B);
    void addMatch(Element *a, Element *b);
    bool matchesAreStable();
    void display();
    bool isNotInMatch(Element *Q);
    bool notDone(SetOfElements *A, SetOfElements *B);
    void separate(Element *a, Element *b);
    Element* findCurrMatch(Element *b);
    Element* elementInSet(SetOfElements *B, Element *b);
    bool keepGoing(vector<Element*> Aoff, string Apreff);
    Element* nextBestPref(Element *a);
};


#endif //CS2353FINALPROJECT_STABLEMATCHSET_H
