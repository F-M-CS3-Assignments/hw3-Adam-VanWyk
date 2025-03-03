


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

// This function calculates the remaining time to dry for a DryingSnapShot struct
// by finding the difference between now and the start time of a dss.
long long int get_time_remaining(DryingSnapShot dss){
	time_t end = time(0);
	return (end - dss.startTime);
}

// This function prints out a dss struct with a random 10 digit number identifier, 
// as well as stating "DONE!" after the paint is dry. 
string drying_snap_shot_to_string(DryingSnapShot dss){
	string s = "";
	s += dss.name;
	s += " (takes ";
	s += dss.timeToDry->ToString();
	s += " to dry) ";

	time_t end = time(0);

	if (dss.timeToDry->GetTimeCodeAsSeconds() <= static_cast<long long unsigned int>(end - dss.startTime)){
		s += "DONE!";
		return s;
	} else{
		TimeCode timeRemaining(0, 0, dss.timeToDry->GetTimeCodeAsSeconds()-(end - dss.startTime));
		s += "time remaining: ";
		s += timeRemaining.ToString();
		return s;
	}	
}

// Returns shere surface area with a parameter for the sphere's radius. 
double get_sphere_sa(double rad){
	return 4*M_PI*rad*rad;
}

// This computes the time to dry for a sphere by adding the surface area parameter's
// amount of seconds to a TimeCode object. 
TimeCode *compute_time_code(double surfaceArea){
	return new TimeCode(0, 0, surfaceArea);
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
	srand(time(0));

	vector <DryingSnapShot> dssVector; // Vector to hold all TimeCode objects
	string userInput;
	cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
	cin >> userInput;
	

	while (userInput != "Q" && userInput != "q"){
		if (userInput == "A" || userInput == "a"){
			
			double radius;
			cout << "Radius: ";
			cin >> radius;
			double surfaceA = get_sphere_sa(radius);
			TimeCode* tcp = compute_time_code(surfaceA);

			unsigned long long randNum = (rand() & 10000) * 100000 + (rand() % 100000);
			string batchName = "Batch-" + to_string(randNum);

			dssVector.emplace_back(DryingSnapShot{batchName, time(0), tcp}); // Creates all TimeCode objects in the vector

			cout << drying_snap_shot_to_string(dssVector.back()) << endl; // Prints the created dss struct

			cout << "Choose an option: (A)dd, (V)iew Current Items, (Q)uit: ";
			cin >> userInput;
		} else if(userInput == "V" || userInput == "v"){
			for (DryingSnapShot dss : dssVector){ // Iterates through the dss vector
				cout << drying_snap_shot_to_string(dss) << endl;
			}

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