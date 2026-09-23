//maxwell koegler | 9/22/26 | COMSC 210 | lab 13

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct student {
    int ID;
    double score;
};

const int SIZE = 150;

int main() {
    student roster[SIZE];
    ifstream file("210-lab-13-grades.txt");
    for(int i = 0; i < SIZE; i++){
        file >> roster[i].ID >> roster[i].score;
    }

    for(int i = 0; i < SIZE-1; i++) {
        int minI = i;

        for(int j = i + 1; j < SIZE; i++) {
            if(roster[j].score < roster[minI].score){
                minI = j;
            }
        }
        swap(roster[i], roster[minI]);
    }
    cout << "Sorted results: " << endl;
    cout << "-------------------" << endl;
    for(int i = 0; i < SIZE; i++){
        int max = roster[i].score;
        if(roster[i].score > max){
            max = roster[i].score;
        }
        cout << "Student ID: " << roster[i].ID << "; Score: " << roster[i].score << endl;
        cout << "Max score: " << max << endl;
        
    }



}
