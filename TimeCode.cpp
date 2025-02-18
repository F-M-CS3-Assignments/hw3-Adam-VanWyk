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
    int minDif;
    minDif = GetMinutes() - minutes;
    t += minDif*60;
}
void TimeCode::SetSeconds(unsigned int seconds){
    int secDif;
    secDif = GetSeconds() - seconds;
    t += secDif;
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

// TimeCode operator+(const TimeCode& other) const;
// TimeCode operator-(const TimeCode& other) const;
// TimeCode operator*(double a) const;
// TimeCode operator/(double a) const;

// bool operator == (const TimeCode& other) const;
// bool operator != (const TimeCode& other) const;

// bool operator < (const TimeCode& other) const;
// bool operator <= (const TimeCode& other) const;

// bool operator > (const TimeCode& other) const;
// bool operator >= (const TimeCode& other) const;
