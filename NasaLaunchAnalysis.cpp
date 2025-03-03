/*
Author: Adam VanWyk
Edit date: 03/3/25
This program will read data from a file and calculate the average time of day of nasa launches.
Note #3: I have read the notes.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "TimeCode.h"
using namespace std;

// This function takes a string parameter and returns a TimeCode object associated with the Space_Corrected.csv file that
// contains all nasa launch times. 
TimeCode parse_line(string line){
    TimeCode time(0, 0, 1); // Initial TimeCode object will not be added to late vector if returned in current state. 

    vector<string> split;
    stringstream ss(line);
    string item;
    while (getline(ss, item, ',')){ // Split the string by commas
        split.push_back(item);
    }
    // for (const auto& part : split){
    //     cout << part << endl;
    // }
    if (split.size() < 5){ // If the line from the file dows not have the correct number of elements, return null (effectively)
        return time;
    }

    string important = split[4]; // Isolate the section of previous vector with recorded time
    if (!important.find(':')){ // Check again that it has the recorded time, if not, return null
        return time;
    }
    split.clear();
    ss.clear();
    ss.str(important);

    while (getline(ss, item, ' ')){
        split.push_back(item);
    }
    if (split[2].find(':') == string::npos){ // Check again that the correct item has the recorded time
        return time;
    } 
    important = split[2];
    split.clear();
    ss.clear();
    ss.str(important);

    while (getline(ss, item, ':')){ // Split the recorded time into hours and minutes
        split.push_back(item);
    }

    // This section creates the TimeCode object according to the brecorded time from the .csv file
    int hours = stoi(split[0]);
    int minutes = stoi(split[1]); 
    time.SetHours(hours);
    time.SetMinutes(minutes);
    time.SetSeconds(0); 

    return time; // Return the correct time, not null, after all tests and checks have been cleared
}

int main(){
    ifstream inFS; // ifstream to open .csv file
    vector<TimeCode> times; // Vector to hold every TimeCode object
    string line;
    TimeCode t(0, 0, 1); // Check for parse_line returned TimeCodes, they should not equal (0, 0, 1)
    double average = 0;

    inFS.open("Space_Corrected.csv");
    if (!inFS.is_open()){
        cout << "File failed to open. " << endl;
        return 1;
    }
    getline(inFS, line); // First line has no data
    getline(inFS, line);

    while(!inFS.eof()){ // Read until the end of the file
        TimeCode time = parse_line(line); 
        if (time != t){
            average += TimeCode::ComponentsToSeconds(time.GetHours(), time.GetMinutes(), time.GetSeconds());
            times.push_back(time);        // Store every TimeCode object
        }
        getline(inFS, line);
    }   
    
    average = average/times.size();
    int avg = average;
    int hours = avg/3600;
    int minutes = (avg%3600)/60;
    int seconds = avg%60;
    TimeCode time(hours, minutes, seconds); // Create average TimeCode 
    cout << times.size() << " data points." << endl;
    cout << "AVERAGE: " << time.ToString() << endl;

    return 0;
}


