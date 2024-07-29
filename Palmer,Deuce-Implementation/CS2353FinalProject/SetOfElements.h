//
// Created by Deuce Palmer on 10/25/21.
//
#include "Element.h"
#ifndef CS2353FINALPROJECT_SETOFELEMENTS_H
#define CS2353FINALPROJECT_SETOFELEMENTS_H
#include <string>
#include <vector>
using namespace std;

class SetOfElements {
private:
    vector<Element*> elementsInSet;
public:
    SetOfElements();
    void addElement(Element *e);
    vector<Element*>* getElements();
    void display();
};


#endif //CS2353FINALPROJECT_SETOFELEMENTS_H
