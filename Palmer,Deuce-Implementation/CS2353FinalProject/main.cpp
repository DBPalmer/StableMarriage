#include "Element.h"
#include "SetOfElements.h"
#include "StableMatchSet.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int arg, char** argv) {
    int num;
    string name, pair, last, blank, file1, file2;
    file1 = argv[1];
    file2 = argv[2];
    ifstream setA(file1);
    if (!setA.is_open()) {//checks if file can open
        cout << "File failed to open." << endl;
    }
    SetOfElements *SetA = new SetOfElements;
    setA >> num;
    getline(setA, blank, '\n');
    while (!setA.eof()) {
        getline(setA, name, ':');
        Element* Name = new Element(name);
        for (int x=1; x<num; x++) {
            getline(setA, pair, ',');
            Element* Pair = new Element(pair);
            Name->addPreference(Pair);
        }
        getline(setA, last, '\n');
        Element* Test = new Element(last);
        Name->addPreference(Test);
        SetA->addElement(Name);
    }
    cout << "Set A contains:";
    SetA->display();
    cout << endl;
    setA.close();

    ifstream setB(file2);
    if (!setB.is_open()) {//checks if file can open
        cout << "File failed to open." << endl;
    }
    SetOfElements *SetB = new SetOfElements;
    setB >> num;
    getline(setB, blank, '\n');
    while (!setB.eof()) {
        getline(setB, name, ':');
        Element* Name = new Element(name);
        for (int x=1; x<num; x++) {
            getline(setB, pair, ',');
            Element* Pair = new Element(pair);
            Name->addPreference(Pair);
        }
        getline(setB, last, '\n');
        Element* Test = new Element(last);
        Name->addPreference(Test);
        SetB->addElement(Name);
    }
    cout << "Set B contains:";
    SetB->display();
    setB.close();
    cout << "\nStable Pairing:\n";
    StableMatchSet *answer = new StableMatchSet;
    answer->determineMatches(SetA, SetB);
    answer->display();
    cout << "\nResult of verification function: " << boolalpha << answer->matchesAreStable();
    return 0;
}
