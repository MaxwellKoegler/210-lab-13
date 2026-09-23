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

}

void selectionSort(student arr[]){
    for(int i = 0; i < SIZE-1; i++) {
        int minI = i;

        for(int j = i + 1; j < SIZE; i++) {
            if(arr[j].score < arr[minI].score){
                minI = j;
            }
        }
        swap(arr[i], arr[minI]);
    }
}