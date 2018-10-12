#include <iostream>
using namespace std;

int main(){
	int score; //variable to hold the score data
	cout <<  "Enter a score."  << endl; //Ask for score input from user
	cin >> score; //store user input into score variable

	//print A letter grade if the score is greater than or equal to 90
	if ( score >= 90 ){
		cout << "This is an A letter grade." << endl; 
	}
	//print B if the score is greater than or equal to 80
	if (score >= 80) {
		cout << "This is a B letter grade." << endl;
	}
	//print C if the score is greater than or equal to 70
	if (score >= 70){
		cout << "This is a C letter grade." << endl;
	}
	//print that this is a failing score
	else{
		cout << "This is a failing score." << endl;
	}

	return 0;
}
