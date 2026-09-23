//maxwell koegler | 9/22/26 | COMSC 210 | lab 13
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//this is our student data struct contianing ID and score
struct student {
    int ID;
    double score;
};
const int SIZE = 150; //input data length const
int main() {
    student roster[SIZE]; //initializes the array of student data types
    ifstream file("210-lab-13-grades.txt"); //opens file for reading
    if(!file){ //error handling
        cout << "Error opening input file";
        return 1;
    }
    for(int i = 0; i < SIZE; i++){ //populates the roster with file contents
        file >> roster[i].ID >> roster[i].score;
    }
    for(int i = 0; i < SIZE-1; i++) { //sort alg.
        int minI = i;
        for(int j = i + 1; j < SIZE; j++) {
            if(roster[j].score < roster[minI].score){
                minI = j;
            }
        }
        swap(roster[i], roster[minI]);
    }
    cout << "Results of 150 student records " << endl; //file outputs
    cout << "-------------------" << endl;
    double total;
    ofstream foul("210-lab-13-grades-sorted.txt"); //output file opening
    if(!foul){ //error handling
        cout << "Error opening output file";
        return 1;
    }   
    for(int i = 0; i < SIZE; i++){ //this outputs sorted file and calcs total for later mean usage
        total += roster[i].score;
        foul << roster[i].ID << " " << roster[i].score << endl;
    }
    cout << "Sorted results written to 210-lab-13-grades-sorted.txt" << endl;
    double mean = (total/SIZE); //calcs average
    cout << "Min score: " << roster[0].score << " (ID: " << roster[0].ID << ")" << endl; //outputs metrics
    cout << "Max score: " << roster[SIZE-1].score << " (ID: " << roster[SIZE-1].ID << ")" << endl;
    cout << "Mean score: " << mean << endl;
    cout << "Median score: " << (static_cast<double>(roster[75].score) + roster[74].score)/2 << endl; 
    double sqr = 0; //standard dev. calc
    for(int i = 0; i < SIZE; i++) {
        sqr += (roster[i].score - mean) * (roster[i].score - mean);
    }
    cout << "Standard dev: " << sqrt(sqr/SIZE) << endl;
}