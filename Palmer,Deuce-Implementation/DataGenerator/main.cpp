#include <iostream>
#include <fstream>
#include <random>
using namespace std;
int main(int argc, char** argv) {
    vector<int> set1;
    vector<int> set2;
    int num;
    string one, two;
    num = stoi(argv[1]);
    one = argv[2];
    two = argv[3];
    for (int z=0; z<num; z++){
        int num1 =(rand() % 100000)+1;
        int num2 = (rand() % 100000)+1;
        set1.push_back(num1);
        set2.push_back(num2);
        auto add = find(set1.begin(), set1.end(), num1);
        if (add != set1.end()){

        }
        else {
            set1.push_back(num1);
        }
        auto add2 = find(set2.begin(), set2.end(), num2);
        if (add2 != set2.end()){

        }
        else {
            set2.push_back(num2);
        }
    }
    cout << "Generating Sets...\n";
    ofstream myFile1;
    myFile1.open(one);
    if (!myFile1.is_open()) {//checks if file can open
        cout << "File failed to open." << endl;
    }
    myFile1 << num << endl;
    for (int x=0; x<num; x++){
        myFile1 << set1[x] << ":";
        for (int w=0; w<num; w++){
            int random = rand() %num;
            int hold = set2[w];
            set2[w] = set2[random];
            set2[random] = hold;
        }
        for (int w=0; w<num-1; w++){
            myFile1 << set2[w] <<",";
        }
        if (x == num-1) {
            myFile1 << set2[num - 1];
        }
        else {
            myFile1 << set2[num - 1] << endl;
        }
    }
    cout << "Writing to File...\n";
    myFile1.close();
    ofstream myFile2;
    myFile2.open(two);
    if (!myFile2.is_open()) {//checks if file can open
        cout << "File failed to open." << endl;
    }
    myFile2 << num << endl;
    for (int x=0; x<num; x++){
        myFile2 << set2[x] << ":";
        for (int w=0; w<num; w++){
            int random = rand() %num;
            int hold = set1[w];
            set1[w] = set1[random];
            set1[random] = hold;
        }
        for (int w=0; w<num-1; w++){
            myFile2 << set1[w] <<",";
        }
        if (x == num-1) {
            myFile2 << set1[num - 1];
        }
        else {
            myFile2 << set1[num - 1] << endl;
        }
    }
    myFile2.close();
    cout << "Done!!";
}
