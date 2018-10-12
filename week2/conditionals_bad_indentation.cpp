#include <iostream>
using namespace std;

int main(){
	int score;
	cout <<  "Enter a score."  << endl;
	cin >> score; 
if ( score >= 90 ){
		cout << "This is an A letter grade." << endl;
	} if (score >= 80) {
cout << "This is a B letter grade." << endl;
}

if (score >= 70){
		cout << "This is a C letter grade." << endl;
} else{ cout << "This is a failing score." << endl;
}

	return 0;
}

