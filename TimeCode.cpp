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

// void SetHours(unsigned int hours);
// void SetMinutes(unsigned int minutes);
// void SetSeconds(unsigned int seconds);

// void reset();

// unsigned int GetHours() const;
// unsigned int GetMinutes() const;
// unsigned int GetSeconds() const;

//long long unsigned int TimeCode::GetTimeCodeAsSeconds() const {return t;};
void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const{
    hr = t/3600;
    min = (t%3600)/60;
    sec = t%60;
}
long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long sec){
    return (hr*3600) + (min*60) + sec;
}

// string ToString() const;

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


int main(){


    return 0;
}