/*
Author: Adam VanWyk 
Last edit: 2/19/2025
This is an implementation of a TimeCode class which allows a user to create, modify, and compare
TimeCode objects by their seconds, minutes, and hours. Each TimeCode object only contains its 
total number of seconds. 
*/

#include <iostream> 
#include "TimeCode.h"
using namespace std;

// This is a constructor for a TimeCode object, it takes hours, minutes, and seconds as parameters
// and convertes them into the single total seconds variable (t).
TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec){
    t = (hr*3600) + (min*60) + sec;
}
// This default cunstructor inititlaizes the TimeCode objects total seconds (t) to the TimeCode object parameter's
// total seconds. 
TimeCode::TimeCode(const TimeCode& tc){
    t = tc.t;
}
//TimeCode::~TimeCode(){}

// This method allows the user to set a TimeCode object's hour amount, then edits the total seconds accordingly.
void TimeCode::SetHours(unsigned int hours){
    int hrDif;
    hrDif = GetHours() - hours;
    t += hrDif*3600;
}
// This method allows the user to set minutes, but does not allow values over 60 (no roll-overs). 
// Then edits the total seconds accordingly. 
void TimeCode::SetMinutes(unsigned int minutes){
    if (minutes <= 60){
        int minDif;
        minDif = minutes - GetMinutes();
        t += minDif*60;
    } else{
        throw invalid_argument("No roll over on SetMinutes " + to_string(minutes));
    }
}
// This method allows the user to set seconds, but does not allow values over 60 (no roll-overs).
// Then edits the total seconds accordingly. 
void TimeCode::SetSeconds(unsigned int seconds){
    if (seconds <= 60){
        int secDif;
        secDif = seconds - GetSeconds();
        t += secDif;
    } else{
        throw invalid_argument("No roll over on SetSeconds " + to_string(seconds));
    }
}
// This method sets the TimeCode's total time to zero. 
void TimeCode::reset(){
    t = 0; 
}
// This returns the total hours of a TimeCode object by integer dividing total seconds by 3600. 
unsigned int TimeCode::GetHours() const{
    unsigned int hours;
    hours = t/3600;
    return hours;
}
// This returns the total minutes of a TimeCode object by taking the modulus of total seconds by 3600
// to remove seconds that count as hours, then integer divides the remainder by 60. 
unsigned int TimeCode::GetMinutes() const{
    unsigned int min;
    min = (t%3600)/60;
    return min;
}
// This returns the seconds by taking total seconds (total time) modulus by 60. 
unsigned int TimeCode::GetSeconds() const{
    unsigned int sec;
    sec = t%60;
    return sec;
}
// This method is inline-defined in TimeCode.h
//long long unsigned int TimeCode::GetTimeCodeAsSeconds() const {return t;};

// This method checks that each component of a TimeCode object has been calculated correctly. 
void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const{
    hr = t/3600;
    min = (t%3600)/60;
    sec = t%60;
}
// This method reverses each TimeCode object from its hours, minutes, and seconds to total seconds. 
long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long sec){
    return (hr*3600) + (min*60) + sec;
}
// This method returns a string representation of a TimeCode object in the form:
// (hours:minutes:seconds)
string TimeCode::ToString() const{
    string timecode;
    timecode = to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":" + to_string(GetSeconds());
    return timecode;
}
// This method overloads the + operator for two TimeCode objects. It simply needs to add the total time
// of each object and assign the total time to the summed TimeCode object. 
TimeCode TimeCode::operator+(const TimeCode& other) const{
    TimeCode added;
    added.t = t + other.t;
    return added;
}
// This method overloads the - operator for two TimeCode objects. It does not allow the creation of negative time, obviously.
// 
TimeCode TimeCode::operator-(const TimeCode& other) const{
    TimeCode difference = TimeCode();
    if (t < other.t){
        throw invalid_argument("Cannot produce negative time...." + to_string(t) + " < " + to_string(other.t));
    } else{
        difference.t = t - other.t;
    } return difference;
    
}
TimeCode TimeCode::operator*(double a) const{
    TimeCode multTime = TimeCode();
    multTime.t = t*a;
    return multTime;
}
TimeCode TimeCode::operator/(double a) const{
    if (a==0){
        throw invalid_argument("Cannot divide by 0.");
    } else if(a < 0){
        throw invalid_argument("Cannot produce negative time....");
    }
    TimeCode divTime = TimeCode();
    divTime.t = t/a;
    return divTime;
}

bool TimeCode::operator== (const TimeCode& other) const{
    return (t == other.t);
}
bool TimeCode::operator != (const TimeCode& other) const{
    return (t != other.t);
}

bool TimeCode::operator < (const TimeCode& other) const{
    return (t < other.t);
}
bool TimeCode::operator <= (const TimeCode& other) const{
    return (t <= other.t);
}

bool TimeCode::operator > (const TimeCode& other) const{
    return (t > other.t);
}
bool TimeCode::operator >= (const TimeCode& other) const{
    return (t >= other.t);
}
