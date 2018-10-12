#include <iostream>
#include <string>
using namespace std;

//This function takes an integer score as input
//If the score is greater than or equal to 70, the corresponding letter grade is printed
//Otherwise, "This is a failing score." is printed
int main(){

	string exercise;
	string workWriting;

	cout << "Did you exercise today?" << endl; 
	getline(cin, exercise);

	cout << "Did you do any writing today?" << endl;
	getline(cin, workWriting);

	if (exercise =="y"){
		cout << "You can drink juice!" << endl;
	}

	else if ( workWriting =="y"){
		cout << "You can drink juice!" << endl;
	}

	else{
		cout << "You cannot drink juice." << endl;
	}

	return 0;
}
