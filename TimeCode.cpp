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

TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec){
    t = (hr*3600) + (min*60) + sec;
}
TimeCode::TimeCode(const TimeCode& tc){
    t = tc.t;
}
//TimeCode::~TimeCode(){}

void TimeCode::SetHours(unsigned int hours){
    int hrDif;
    hrDif = GetHours() - hours;
    t += hrDif*3600;
}
void TimeCode::SetMinutes(unsigned int minutes){
    if (minutes <= 60){
        int minDif;
        minDif = minutes - GetMinutes();
        t += minDif*60;
    } else{
        throw invalid_argument("No roll over on SetMinutes " + to_string(minutes));
    }
}
void TimeCode::SetSeconds(unsigned int seconds){
    if (seconds <= 60){
        int secDif;
        secDif = seconds - GetSeconds();
        t += secDif;
    } else{
        throw invalid_argument("No roll over on SetSeconds " + to_string(seconds));
    }
}

void TimeCode::reset(){
    t = 0; // resets time
}

unsigned int TimeCode::GetHours() const{
    unsigned int hours;
    hours = t/3600;
    return hours;
}
unsigned int TimeCode::GetMinutes() const{
    unsigned int min;
    min = (t%3600)/60;
    return min;
}
unsigned int TimeCode::GetSeconds() const{
    unsigned int sec;
    sec = t%60;
    return sec;
}

//long long unsigned int TimeCode::GetTimeCodeAsSeconds() const {return t;};
void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const{
    hr = t/3600;
    min = (t%3600)/60;
    sec = t%60;
}
long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long sec){
    return (hr*3600) + (min*60) + sec;
}

string TimeCode::ToString() const{
    string timecode;
    timecode = to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":" + to_string(GetSeconds());
    return timecode;
}

TimeCode TimeCode::operator+(const TimeCode& other) const{
    TimeCode added = TimeCode((GetHours() + other.GetHours()), (GetMinutes() + other.GetMinutes()), 
    (GetSeconds() + other.GetSeconds()));
    return added;
}
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
