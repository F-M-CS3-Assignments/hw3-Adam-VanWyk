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
    if (split.size() < 5){
        return time;
    }

    string important = split[4];
    if (!important.find(':')){
        return time;
    }
    split.clear();
    ss.clear();
    ss.str(important);

    while (getline(ss, item, ' ')){
        split.push_back(item);
    }
    if (split[2].find(':') == string::npos){
        return time;
    } 
    important = split[2];
    split.clear();
    ss.clear();
    ss.str(important);

    while (getline(ss, item, ':')){
        split.push_back(item);
    }

    int hours = stoi(split[0]);
    int minutes = stoi(split[1]);
    time.SetHours(hours);
    time.SetMinutes(minutes);
    time.SetSeconds(0);

    return time;
}

int main(){
    ifstream inFS;
    vector<TimeCode> times;
    string line;
    TimeCode t(0, 0, 1);
    double average = 0;

    inFS.open("Space_Corrected.csv");
    if (!inFS.is_open()){
        cout << "File failed to open. " << endl;
        return 1;
    }
    getline(inFS, line); // First line has no data
    getline(inFS, line);

    while(!inFS.eof()){
        TimeCode time = parse_line(line);
        if (time != t){
            average += TimeCode::ComponentsToSeconds(time.GetHours(), time.GetMinutes(), time.GetSeconds());
            times.push_back(time);        
        }
        getline(inFS, line);
    }   
    
    average = average/times.size();
    int avg = average;
    int hours = avg/3600;
    int minutes = (avg%3600)/60;
    int seconds = avg%60;
    TimeCode time(hours, minutes, seconds);
    cout << times.size() << " data points." << endl;
    cout << "AVERAGE: " << time.ToString() << endl;

    return 0;
}


