/*
Author: Adam VanWyk
Edit date: 02/27/25
This program will read data from a file and calculate the average time of day of nasa launches.
Note #3: I have read the notes.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "TimeCode.h"
using namespace std;

TimeCode parse_line(string line){
    TimeCode time(0, 0, 1);
    
    vector<string> split;
    stringstream ss(line);
    string item;
    while (getline(ss, item, ',')){
        split.push_back(item);
    }
    // for (const auto& part : split){
    //     cout << part << endl;
    // }
    string important = split[4];
    if (!important.find(':')){
        return time;
    }
    

    return time;
}

int main(){
    ifstream inFS;
    vector<TimeCode> times;
    string line;
    TimeCode t(0, 0, 1);

    inFS.open("Space_Corrected_Short.csv");
    if (!inFS.is_open()){
        cout << "File failed to open. " << endl;
        return 1;
    }
    getline(inFS, line); // First line has no data
    getline(inFS, line);
    while(!inFS.eof()){
        TimeCode time = parse_line(line);
        if (time != t){
            times.push_back(time);
        }
        getline(inFS, line);
    }   

    return 0;
}


