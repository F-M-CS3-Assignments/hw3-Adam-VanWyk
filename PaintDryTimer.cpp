


#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;




struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};


long long int get_time_remaining(DryingSnapShot dss){
	// Replace with your code
	return 0;
}


string drying_snap_shot_to_string(DryingSnapShot dss){
	string s = "";
	s += dss.name;
	s += "(takes ";
	s += dss.timeToDry->ToString();
	s += " to dry) time remaining: ";

	TimeCode timeRemaining(0, 0, 0);


	return s;
}


double get_sphere_sa(double rad){
	return 4*M_PI*rad*rad;
}


TimeCode *compute_time_code(double surfaceArea){
	TimeCode time(0, 0, surfaceArea);
	TimeCode* tcp = &time;
	return tcp;
}


void tests(){
	// get_time_remaining
	DryingSnapShot dss;
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	long long int ans = get_time_remaining(dss);
	assert(ans > 6 && ans < 8);
	// add more tests here


	// get_sphere_sa
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);
	// add more tests here


	// compute_time_code
	TimeCode *tc2 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc2->GetTimeCodeAsSeconds() == 1);
	delete tc2;


	// add more tests here


	cout << "ALL TESTS PASSED!" << endl;

}


int main(){
	
	string userInput;
	cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
	cin >> userInput;
	
	while (userInput != "Q" && userInput != "q"){
		if (userInput == "A" || userInput == "a"){
			cout << "Adding" << endl;



			cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
			cin >> userInput;
		} else if(userInput == "V" || userInput == "v"){
			cout << "Viewing" << endl;

			cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
			cin >> userInput;
		} else{
			cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
			cin >> userInput;
		}
	}
	


	//tests());
	return 0;
}