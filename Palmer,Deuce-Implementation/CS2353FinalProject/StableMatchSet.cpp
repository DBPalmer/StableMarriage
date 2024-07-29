//
// Created by Deuce Palmer on 10/25/21.
//
#include "StableMatchSet.h"
#include <iostream>

StableMatchSet::StableMatchSet(){
//doesnt need anything
}
void StableMatchSet::determineMatches(SetOfElements *A, SetOfElements *B) {
    int size = A->getElements()->size();
    while (this->notDone(A, B)){
        for (int z=0; z<size; z++) {
            for (int x = 0; x < size; x++) {
                if (this->isNotInMatch((*A->getElements())[x])) {
                    Element *hold = this->nextBestPref((*A->getElements())[x]);
                    Element *pairing = this->elementInSet(B, hold);
                    (*A->getElements())[x]->addOffer(pairing);
                        if (this->isNotInMatch(pairing)) {
                            this->addMatch((*A->getElements())[x], pairing);
                        } else {
                            Element *match = this->findCurrMatch(pairing);
                            if (pairing->locationOf((*A->getElements())[x]) <
                                pairing->locationOf(match)) {
                                this->separate(match, pairing);
                                this->addMatch((*A->getElements())[x], pairing);
                            }
                        }
                }
            }
        }
    }
}
void StableMatchSet::addMatch(Element *a, Element *b) {
    this->matches.push_back(make_pair (a, b));
}
bool StableMatchSet::matchesAreStable(){
    for (int x=0; x<this->matches.size(); x++){
        for (int z=0; z<this->matches.size(); z++){
            if (x != z){
                if (matches[x].first->prefersOver(matches[z].second, matches[x].second) && matches[z].second->prefersOver(matches[x].first, matches[z].first)){
                    cout << matches[x].first->getName() << ", " << matches[z].second->getName() << endl;
                    return false;
                }
                if (matches[x].second->prefersOver(matches[z].first, matches[x].first) && matches[z].first->prefersOver(matches[x].second, matches[z].second)){
                    cout << matches[x].second->getName() << ", " << matches[z].first->getName() << endl;
                    return false;
                }
            }
        }
    }
    return true;
}
void StableMatchSet::display(){
    for (int x=0; x<this->matches.size(); x++){
        cout << "(" << this->matches[x].first->getName() << ", " << this->matches[x].second->getName() << ")" << endl;
    }
}
bool StableMatchSet::isNotInMatch(Element *Q){
    for (int x=0; x<this->matches.size(); x++){
        if (Q->getName() == this->matches[x].first->getName() || Q->getName() == this->matches[x].second->getName()){
            return false;
        }
    }
    return true;
}
bool StableMatchSet::notDone(SetOfElements *A, SetOfElements *B){
    for (int x=0; x<A->getElements()->size(); x++){
        if (this->isNotInMatch((*A->getElements())[x])){
            return true;
        }
    }
    return false;
}
void StableMatchSet::separate(Element *a, Element *b){
    for (int x=0; x<this->matches.size(); x++){
        if (a->getName() == this->matches[x].first->getName() && b->getName() == this->matches[x].second->getName()){
            matches.erase(matches.begin() + x);
        }
    }
}
Element* StableMatchSet::findCurrMatch(Element *b){
    for (int x=0; x<this->matches.size(); x++){
        if (b->getName() == this->matches[x].second->getName()){
            return this->matches[x].first;
        }
    }
}
Element* StableMatchSet::elementInSet(SetOfElements *B, Element *b){
    for (int x=0; x<B->getElements()->size(); x++){
        if ((*B->getElements())[x]->getName() == b->getName()){
            return (*B->getElements())[x];
        }
    }
}
bool StableMatchSet::keepGoing(vector<Element*> Aoff, string Apreff){
    for (int w = 0; w < Aoff.size(); w++) {
        if (Apreff == Aoff[w]->getName()) {
            return false;
        }
    }
    return true;
}
Element* StableMatchSet:: nextBestPref(Element *a){
    for (int x=0; x<a->getPreferences().size(); x++){
        if (this->keepGoing(a->getOffers(), a->getPreferences()[x]->getName())){
            return a->getPreferences()[x];
        }
    }
}
