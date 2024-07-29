//
// Created by Deuce Palmer on 10/25/21.
//
#include "SetOfElements.h"
#include <iostream>

SetOfElements::SetOfElements(){
}
void SetOfElements::addElement(Element *e){
    elementsInSet.push_back(e);
}
vector<Element*>* SetOfElements::getElements(){
    return &elementsInSet;
}
void SetOfElements::display(){
    cout << endl;
    for (int x=0; x < elementsInSet.size(); x++){
        cout << elementsInSet[x]->getName() << ": (";
        for (int z=0; z < (elementsInSet[x]->getPreferences().size()-1); z++){
            cout << elementsInSet[x]->getPreferences()[z]->getName() << ", ";
        }
        int w = elementsInSet[x]->getPreferences().size() - 1;
        cout << elementsInSet[x]->getPreferences()[w]->getName() << ")" << endl;
    }
};