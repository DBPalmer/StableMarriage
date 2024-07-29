//
// Created by Deuce Palmer on 10/25/21.
//
#ifndef CS2353FINALPROJECT_ELEMENT_H
#define CS2353FINALPROJECT_ELEMENT_H
#include <string>
#include <vector>
#include <list>
using namespace std;

class Element {
private:
    string name;
    vector<Element*> preferences;
    vector<Element*> offers;
public:
    Element(string name);
    string getName();
    void addPreference(Element *pref);
    vector<Element*> getPreferences();
    void addOffer(Element *offer);
    vector<Element*> getOffers();
    int locationOf(Element *loc);
    bool prefersOver(Element *a, Element *b);
};


#endif //CS2353FINALPROJECT_ELEMENT_H
