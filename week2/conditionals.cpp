#include <iostream>
using namespace std;

//This function takes an integer score as input
//If the score is greater than or equal to 70, the corresponding letter grade is printed
//Otherwise, "This is a failing score." is printed
int main(){
	int score;
	cout <<  "Enter a score."  << endl;
	cin >> score;

	if ( score >= 90 ){
		cout << "This is an A letter grade." << endl;
	}
	if (score >= 80) {
		cout << "This is a B letter grade." << endl;
	}

	if (score >= 70){
		cout << "This is a C letter grade." << endl;
	}

	else{
		cout << "This is a failing score." << endl;
	}

	return 0;
}
