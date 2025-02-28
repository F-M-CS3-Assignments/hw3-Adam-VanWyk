/*
Author: Adam VanWyk
Edit date: 02/27/25
This program will read data from a file and calculate the average time of day of nasa launches.
Note #3: I have read the notes.
*/

#include <iostream>
#include <fstream>
#include "TimeCode.h"
using namespace std;

// TimeCode parse_line(string line){}

int main(){
    ifstream inFS;


    inFS.open("Space_Corrected_Short.csv");
    if (!inFS.is_open()){
        cout << "File failed to open. " << endl;
        return 1;
    }
    

    return 0;
}


