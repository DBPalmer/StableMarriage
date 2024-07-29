//
// Created by Deuce Palmer on 10/25/21.
//

#include "Element.h"
Element::Element(string nam){
    name = nam;
}
string Element::getName(){
    return name;
}
void Element::addPreference(Element *pref){
    preferences.push_back(pref);
}
vector<Element*> Element::getPreferences(){
    return preferences;
}
void Element::addOffer(Element *offer){
    offers.push_back(offer);
}
vector<Element*> Element::getOffers(){
    return offers;
}
int Element::locationOf(Element *loc){
    for (int x=0;x<preferences.size();x++){
        if (loc->name == preferences[x]->name){
            return x;
        }
    }
}
bool Element::prefersOver(Element *a, Element *b){
    for (int x=0; x<this->getPreferences().size(); x++){
        if (this->getPreferences()[x]->getName() == a->getName()){
            return true;
        }
        if (this->getPreferences()[x]->getName() == b->getName()){
            return false;
        }
    }
}
